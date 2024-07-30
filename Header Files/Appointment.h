#pragma once
#include "User.h"

class Doctor; // Forward declaration
class Patient; // Forward declaration

// Represents an appointment
class Appointment {
private:
    int appointmentID;     // Unique appointment ID
    shared_ptr<Patient> client;       // Pointer to the patient
    shared_ptr<Doctor> doctor;        // Pointer to the doctor
    DateTime dateAndTime;  // Appointment date and time
    Status status;         // Appointment status

public:
    // Constructor
    Appointment(DateTime dateTime, shared_ptr<Doctor> doctor, shared_ptr<Patient> client);

    // Getters
    int getAppointmentId() const;     // Get appointment ID
    DateTime getDateAndTime() const;         // Get date and time
    shared_ptr<Patient> getPatient() const;      // Get patient pointer
    shared_ptr<Doctor> getDoctor() const;        // Get doctor pointer
    Status getStatus() const;         // Get status

    // Setters
    void setDateAndTime(DateTime date);              // Set date and time
    void setPatient(shared_ptr<Patient>);        // Set patient pointer
    void setDoctor(shared_ptr<Doctor>);           // Set doctor pointer
    void setStatus(Status status);            // Set status
};
