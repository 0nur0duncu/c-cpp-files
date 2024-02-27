#include <sapi.h> // include the Windows Speech API header file

int main() {
    // initialize COM
    CoInitialize(NULL);

    // create a new instance of the Speech Recognition Engine
    ISpRecognizer* recognizer;
    CoCreateInstance(CLSID_SpSharedRecognizer, NULL, CLSCTX_ALL, IID_ISpRecognizer, (void**)&recognizer);

    // create a new instance of the Speech Synthesizer Engine
    ISpVoice* synthesizer;
    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&synthesizer);

    // set the audio output to the default audio device
    synthesizer->SetOutput(NULL, TRUE);

    // create a new instance of the Speech Grammar Builder
    ISpRecoGrammar* grammar;
    recognizer->CreateGrammar(0, &grammar);

    // load the grammar from a file (replace "C:\\path\\to\\grammar.xml" with your own file path)
    grammar->LoadCmdFromFile(L"C:\\path\\to\\grammar.xml", SPLO_STATIC);

    // set the recognition event notification
    HANDLE eventHandle = CreateEvent(NULL, FALSE, FALSE, NULL);
    recognizer->SetNotifyWin32Event();
    recognizer->SetEventInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION));
    recognizer->SetNotifyWindowMessage((HWND)eventHandle, WM_USER, 0, 0);

    // set the recognition mode to continuous
    grammar->SetRuleState(NULL, NULL, SPRS_ACTIVE);
    recognizer->SetRecoState(SPRST_ACTIVE_ALWAYS);

    // main loop
    while (true) {
        // wait for a recognition event to occur
        WaitForSingleObject(eventHandle, INFINITE);

        // get the recognition event
        SPEVENT event;
        ULONG count;
        recognizer->GetEvents(1, &event, &count);

        // get the recognized text
        WCHAR* text = NULL;
        ISpRecoResult* result = (ISpRecoResult*)event.lParam;
        result->GetText(SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE, TRUE, &text, NULL);

        // do something based on the recognized text
        if (wcscmp(text, L"hello") == 0) {
            synthesizer->Speak(L"Hello, how can I assist you?", 0, NULL);
        } else if (wcscmp(text, L"what time is it") == 0) {
            SYSTEMTIME time;
            GetLocalTime(&time);
            WCHAR* timeText = new WCHAR[100];
            swprintf_s(timeText, 100, L"The time is %02d:%02d", time.wHour, time.wMinute);
            synthesizer->Speak(timeText, 0, NULL);
            delete[] timeText;
        } else if (wcscmp(text, L"goodbye") == 0) {
            synthesizer->Speak(L"Goodbye!", 0, NULL);
            break;
        }

        // release the resources
        CoTaskMemFree(text);
        result->Release();
        recognizer->ClearEvent(event);
    }

    // release the resources
    CloseHandle(eventHandle);
    grammar->Release();
    synthesizer->Release();
    recognizer->Release();
    CoUninitialize();

    return 0;
}
