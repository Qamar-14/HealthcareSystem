#include "iostream"
#include "ExternalDataTypes.h"

// Function to get the current date and time
DateTime getCurrentDateTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    DateTime dt;
    dt.year = 1900 + ltm->tm_year;
    dt.month = 1 + ltm->tm_mon;
    dt.day = ltm->tm_mday;
    dt.hour = ltm->tm_hour;
    dt.minute = ltm->tm_min;
    dt.second = ltm->tm_sec;

    return dt;
}


// Function to print the date and time
void printDateTime(const DateTime& dt) {
    cout << "Year: " << dt.year << endl;
    cout << "Month: " << dt.month << endl;
    cout << "Day: " << dt.day << endl;
    cout << "Time: " << dt.hour << ":"
        << dt.minute << ":"
        << dt.second << endl;
}
