#include <iostream>
#include <cstdlib>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{
    // Define options
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"output", required_argument, 0, 'o'},
        {"verbose", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };

    // Set default values for options
    int verbose = 0;
    char *output_file = NULL;

    // Parse command line arguments
    int option_index = 0;
    int c;
    while ((c = getopt_long(argc, argv, "ho:v", long_options, &option_index)) != -1) {
        switch (c) {
            case 'h':
                cout << "Usage: " << argv[0] << " [OPTIONS]" << endl;
                cout << "Options:" << endl;
                cout << "  -h, --help         Print this help message" << endl;
                cout << "  -o, --output FILE  Write output to FILE" << endl;
                cout << "  -v, --verbose      Verbose output" << endl;
                exit(EXIT_SUCCESS);
                break;
            case 'o':
                output_file = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case '?':
                // getopt_long will have printed an error message
                exit(EXIT_FAILURE);
                break;
            default:
                cerr << "Error: getopt returned character code " << c << endl;
                exit(EXIT_FAILURE);
        }
    }

    // Print out values of options
    cout << "Verbose: " << verbose << endl;
    if (output_file) {
        cout << "Output file: " << output_file << endl;
    }

    // Do something with the options...
    // ...

    return EXIT_SUCCESS;
}
