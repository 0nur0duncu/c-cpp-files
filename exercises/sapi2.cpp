#include <sapi.h>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Initialize SAPI
    CoInitialize(NULL);
    ISpVoice* pVoice = NULL;
    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

    if (FAILED(hr)) {
        cerr << "Failed to initialize SAPI." << endl;
        return 1;
    }

    // Initialize speech recognition engine
    ISpRecognizer* pRecognizer = NULL;
    hr = CoCreateInstance(CLSID_SpSharedRecognizer, NULL, CLSCTX_ALL, IID_ISpRecognizer, (void **)&pRecognizer);

    if (FAILED(hr)) {
        cerr << "Failed to initialize speech recognition engine." << endl;
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Create a grammar for voice commands
    ISpRecoContext* pContext = NULL;
    hr = pRecognizer->CreateRecoContext(&pContext);

    if (FAILED(hr)) {
        cerr << "Failed to create speech recognition context." << endl;
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    ISpRecoGrammar* pGrammar = NULL;
    hr = pContext->CreateGrammar(0, &pGrammar);

    if (FAILED(hr)) {
        cerr << "Failed to create speech recognition grammar." << endl;
        pContext->Release();
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Define the voice assistant commands
    hr = pGrammar->LoadDictation(NULL, SPLO_STATIC);

    if (FAILED(hr)) {
        cerr << "Failed to load dictation grammar." << endl;
        pGrammar->Release();
        pContext->Release();
        pRecognizer->Release();
        pVoice->Release();
        CoUninitialize();
        return 1;
    }

    // Start the voice recognition loop
    cout << "Listening..." << endl;
    hr = pContext->SetNotifyWin32Event();
    HANDLE hEvent = pContext->GetNotifyEventHandle();

    while (true) {
        WaitForSingleObject(hEvent, INFINITE);
        hr = pContext->GetEvents(1, NULL, &ulEventsFetched);

        if (SUCCEEDED(hr)) {
            SPPHRASE* pPhrase;
            hr = pContext->GetCurrentPhrase(&pPhrase);

            if (SUCCEEDED(hr)) {
                wstring command(pPhrase->pProperties->pFirstChild->pszValue);

                if (command == L"hello") {
                    pVoice->Speak(L"Hello! How can I help you?", 0, NULL);
                } else if (command == L"goodbye") {
                    pVoice->Speak(L"Goodbye!", 0, NULL);
                    break;
                } else {
                    pVoice->Speak(L"I'm sorry, I didn't understand that command.", 0, NULL);
                }

                pContext->ClearPhraseQueue();
                CoTaskMemFree(pPhrase);
            }
        }
    }

    // Clean up
    pGrammar->Release();
    pContext->Release();
    pRecognizer->Release();
    pVoice->Release();
    CoUninitialize();
}
