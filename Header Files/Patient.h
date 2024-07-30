#pragma once
#include "User.h"
#include "PatientProfile.h"
#include "Appointment.h"

// Forward declaration of other classes to avoid circular dependencies
class MedicalRecord;

// The Patient class inherits from the User class
class Patient : public User {
private:
    int patientID;                                   // Unique identifier for the patient
    shared_ptr<MedicalRecord> medicalHistory;        // Pointer to the patient's medical record
    shared_ptr<PatientProfile> profile;              // Pointer to the patient's profile information
    map<int, shared_ptr<Appointment>> appointments;    // map of appointments for the patient

public:
    // Constructor to initialize a Patient object
    Patient(string username, string email, string password, string phone, Role title);

    // Copy Constructer
    Patient(const Patient& other);

    // Assignment operator Overloading
    Patient& operator=(const Patient& other);

    // Move constructor
    Patient(Patient&& other);

    // Function to manage the profile
    void manageProfile(const string& fullName, BloodType bloodtype, Gender gender, const string& address, double height, double weight, DateTime dateOfBirth);
    
    // setter method for adding medical record;
    void setMedicalRecord(shared_ptr<MedicalRecord> medicalHistory);

    // Getter for the patient ID (override base class Id getter method)
    int getID() override;

    // Getter for patients map of appointments
    map<int, shared_ptr<Appointment>> getAppointments();

    // Function to get the patient's medical history
    shared_ptr<MedicalRecord> getMedicalHistory() const;

    // Function to view the patient's profile
    shared_ptr<PatientProfile> getProfile() const;

    // Function to search for doctors based on a specialty
    vector<shared_ptr<User>> searchDoctor(Specialty field);

    // Function to schedule an appointment with a doctor at a specific date and time
    Status scheduleAppointment(shared_ptr<Doctor> doctor, DateTime dateTime);

    // Function to cancel an existing appointment by its ID
    void cancelAppointment(const int appointmentID);

};
