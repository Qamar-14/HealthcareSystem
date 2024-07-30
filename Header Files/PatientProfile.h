#pragma once
#include "User.h"

// PatientProfile class inherits from Patient
class PatientProfile  {
private:
    string fullName;        // Full name of the patient
    BloodType bloodtype;    // Blood type of the patient
    Gender gender;          // Gender of the patient
    string address;         // Address of the patient
    double height;          // Height of the patient (in meters)
    double weight;          // Weight of the patient (in kilograms)
    DateTime dateOfbirth;   // Date of birth of the patient

public:

    // Setters
    void setName(string name);
    void setAddress(string newAddress);
    void setGender(Gender gender);
    void setHeight(double newHeight);
    void setWeight(double newWeight);
    void setDateOfBirth(DateTime birth);
    void setBloodType(BloodType bloodtype);

    // Getters
    string getName();
    string getAddress();
    Gender getGender();
    double getHeight();
    double getWeight();
    DateTime getDateOfBirth();
    BloodType getBloodType();
};
