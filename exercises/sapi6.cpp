#include <iostream>
#include <sapi.h>

int main() {
    // Initialize COM library
    CoInitialize(NULL);

    // Create a speech recognition engine
    ISpRecognizer* recognizer = NULL;
    CoCreateInstance(CLSID_SpSharedRecognizer, NULL, CLSCTX_ALL, IID_ISpRecognizer, (void**)&recognizer);

    // Create a speech synthesis engine
    ISpVoice* voice = NULL;
    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&voice);

    // Set the recognition language to English
    LANGID langid = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);
    recognizer->SetLanguage(langid);

    // Set up the recognition event sink
    HANDLE recognitionEvent;
    ISpRecoContext* recoContext = NULL;
    recognizer->CreateRecoContext(&recoContext);
    recoContext->SetNotifyWin32Event();
    recoContext->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION));
    recognitionEvent = recoContext->GetNotifyEventHandle();

    // Start the recognition engine
    recognizer->SetInput(recoContext, NULL, TRUE);
    recoContext->SetContextState(SPCS_ENABLED);
    recoContext->Resume(0);

    // Main loop
    while (true) {
        // Wait for a recognition event
        WaitForSingleObject(recognitionEvent, INFINITE);

        // Get the recognition result
        CSpEvent event;
        while (event.GetFrom(recoContext) == S_OK) {
            if (event.eEventId == SPEI_RECOGNITION) {
                // Get the recognized text
                ISpRecoResult* result = event.RecoResult();
                SPPHRASE* phrase;
                result->GetPhrase(&phrase);
                std::wstring text(phrase->pProperties->pFirstChild->pFirstChild->pszValue);
                CoTaskMemFree(phrase);

                // Process the recognized text
                if (text == L"hello") {
                    voice->Speak(L"Hello there!", SPF_DEFAULT, NULL);
                } else if (text == L"what is your name") {
                    voice->Speak(L"My name is Voice Assistant!", SPF_DEFAULT, NULL);
                } else if (text == L"goodbye") {
                    voice->Speak(L"Goodbye!", SPF_DEFAULT, NULL);
                    return 0;
                } else {
                    voice->Speak(L"I'm sorry, I didn't understand.", SPF_DEFAULT, NULL);
                }
            }
        }
    }

    // Clean up
    recoContext->Release();
    recognizer->Release();
    voice->Release();
    CoUninitialize();
}
