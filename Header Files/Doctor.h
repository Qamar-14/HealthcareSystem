#pragma once
#include "User.h"
#include "Appointment.h"

// Forward declarations to avoid circular dependencies and reduce compile time
class MedicalRecord;

// The Doctor class inherits from the User class
class Doctor : public User {
private:
    int doctorID;                                // Unique identifier for the doctor
    string name;                                // Name of the doctor
    map<int, shared_ptr<Appointment>> schedule;   // Schedule of appointments for the doctor
    Specialty field;                           // Medical specialty of the doctor
    string clinicAddress;                      // Address of the clinic where the doctor practices
    Gender gender;                             // Gender of the doctor

public:
    //Constructer
    Doctor(string name, string username, string email, string password, string phone, Role title, Gender gender, string clinicAddress, Specialty field);

    //Copy Constructer
    Doctor(const Doctor& other);
    
    // Setter for the clinic address
    void setClinicAddress(string clinicAddress);

    // Setter for the doctor's gender
    void setGender(Gender gender);

    // Setter for the doctor's specialty
    void setSpecialty(Specialty field);

    // Setter for the doctor's name
    void setName(string name);

    // Getter for the clinic address
    string getClinicAddress() const;

    // Getter for the doctor's gender
    Gender getGender() const;

    // Getter for the doctor's specialty
    Specialty getSpecialty() const;

    // Getter for the doctor's name
    string getName() const;

    // Getter for the Doctor ID (override base class Id getter method)
    int getID() override;

    // Getter for doctors schedule
    map<int, shared_ptr<Appointment>> getSchedule();

    // Function to add a medical record for the patient
    void addMedicalRecord(shared_ptr<Patient> patient, string diagnosis, string treatment);

    // Function to update a medical record of a patient
    void updateMedicalRecord(shared_ptr<Patient> patient, string diagnosis, string treatment);

    // Function to add an appointment to the doctor's schedule 
    void addAppointment(const shared_ptr<Appointment> appointment, int appointmentID);

    // Function to remove an appointment from the doctor's schedule
    void cancelAppointment(const int appointmentID);

    // Fuction to check if there is an available slot with the given date and time in the doctor's schedule.
	bool checkAvailability(DateTime dateTime);

    // Function to view patient's profile
    shared_ptr<PatientProfile> viewPatientProfile(const int patientID);
};