#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    // Command to execute
    //const char* cmd = "python hello.py";
    const char* cmd = "ipconfig";

    // Open a pipe to the command
    FILE* pipe = popen(cmd, "r");

    // Check if pipe was opened successfully
    if (!pipe) {
        cerr << "Error: popen() failed." << endl;
        exit(EXIT_FAILURE);
    }

    // Read output from the pipe
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        cout << buffer;
    }

    // Close the pipe
    pclose(pipe);

    return EXIT_SUCCESS;
}
