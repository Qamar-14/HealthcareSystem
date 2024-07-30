#pragma once
#include <ctime>

using namespace std;

// Define a struct to represent Date and Time
typedef struct DateTime {
    int year;    // Year (e.g., 2024)
    int month;   // Month (1 to 12)
    int day;     // Day (1 to 31)
    int hour;    // Hour (0 to 23)
    int minute;  // Minute (0 to 59)
    int second;  // Second (0 to 59)

    // Overload the assignment operator
    DateTime& operator=(const DateTime& other) {
        if (this != &other) {
            year = other.year;
            month = other.month;
            day = other.day;
            hour = other.hour;
            minute = other.minute;
            second = other.second;
        }
        return *this;
    }

    // Overload the equality operator
    bool operator==(const DateTime& other) const {
        return (year == other.year &&
            month == other.month &&
            day == other.day &&
            hour == other.hour &&
            minute == other.minute &&
            second == other.second);
    }

    // Overload the inequality operator
    bool operator!=(const DateTime& other) const {
        return !(*this == other);
    }

    // Overload the less-than operator
    bool operator<(const DateTime& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }

    // Overload the less-than-or-equal operator
    bool operator<=(const DateTime& other) const {
        return !(*this > other);
    }

    // Overload the greater-than operator
    bool operator>(const DateTime& other) const {
        return other < *this;
    }

    // Overload the greater-than-or-equal operator
    bool operator>=(const DateTime& other) const {
        return !(*this < other);
    }

} DateTime;

// Enumeration for user roles in the system
typedef enum {
    admin,    // Administrator role
    patient,  // Patient role
    doctor    // Doctor role
} Role;

// Enumeration for gender
typedef enum {
    Female,   // Female gender
    Male      // Male gender
} Gender;

// Enumeration for appointment status
typedef enum {
    Booked,    // Appointment is booked
    Cancelled, // Appointment is cancelled
    Completed, // Appointment is completed
    Busy       // Doctor is busy
} Status;

// Enumeration for medical specialties
typedef enum {
    General,      // General practice
    Cardiology,   // Cardiology
    Dermatology,  // Dermatology
    Neurology,    // Neurology
    Dental        // Dental
} Specialty;

// Enumeration for blood types
typedef enum {
    A_POSITIVE,   // A positive blood type
    A_NEGATIVE,   // A negative blood type
    B_POSITIVE,   // B positive blood type
    B_NEGATIVE,   // B negative blood type
    AB_POSITIVE,  // AB positive blood type
    AB_NEGATIVE,  // AB negative blood type
    O_POSITIVE,   // O positive blood type
    O_NEGATIVE    // O negative blood type
} BloodType;

DateTime getCurrentDateTime();

void printDateTime(const DateTime& dt);

