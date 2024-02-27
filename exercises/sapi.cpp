#include <iostream>
#include <sapi.h>

int main() {
    // Initialize COM library
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM library" << std::endl;
        return 1;
    }

    // Create instance of SpVoice object
    ISpVoice* pVoice = NULL;
    hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
    if (FAILED(hr)) {
        std::cerr << "Failed to create SpVoice object" << std::endl;
        CoUninitialize();
        return 1;
    }

    // Set voice output format
    hr = pVoice->SetOutput(NULL, TRUE);
    if (FAILED(hr)) {
        std::cerr << "Failed to set voice output format" << std::endl;
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Speak a greeting
    pVoice->Speak(L"Hello, I am your voice assistant", 0, NULL);

    // Listen for user input
    ISpRecognizer* pRecognizer = NULL;
    hr = CoCreateInstance(CLSID_SpSharedRecognizer, NULL, CLSCTX_ALL, IID_ISpRecognizer, (void **)&pRecognizer);
    if (FAILED(hr)) {
        std::cerr << "Failed to create SpSharedRecognizer object" << std::endl;
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Set input source to microphone
    hr = pRecognizer->SetInput(NULL, TRUE);
    if (FAILED(hr)) {
        std::cerr << "Failed to set input source" << std::endl;
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Set recognition mode to free-form dictation
    ISpRecoContext* pContext = NULL;
    hr = pRecognizer->CreateRecoContext(&pContext);
    if (FAILED(hr)) {
        std::cerr << "Failed to create recognition context" << std::endl;
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }
    hr = pContext->SetPropertyNum(L"AdaptationOn", 0);
    if (FAILED(hr)) {
        std::cerr << "Failed to set adaptation mode" << std::endl;
        pContext->Release();
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }
    hr = pContext->SetGrammarState(SPGS_ENABLED);
    if (FAILED(hr)) {
        std::cerr << "Failed to enable grammar" << std::endl;
        pContext->Release();
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Start recognition loop
    std::cout << "Speak now..." << std::endl;
    while (true) {
        // Wait for speech input
        HANDLE hEvent = NULL;
        hr = pContext->GetEvents(1, &hEvent);
        if (FAILED(hr)) {
            std::cerr << "Failed to get speech events" << std::endl;
            pContext->Release();
            pRecognizer->Release();
            pVoice->Release();
            CoUninitialize();
            return 1;
        }

        // Get recognition
