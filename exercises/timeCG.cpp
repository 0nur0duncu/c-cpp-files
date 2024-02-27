#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // current time
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;
    
    // time structure
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is: "<< dt << endl;
    
    // time components
    tm *ltm = localtime(&now);
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    
    // elapsed time
    int elapsed = difftime(now, mktime(gmtm));
    cout << "Seconds since UTC Epoch: " << elapsed << endl;
    
    return 0;
}
