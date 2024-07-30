#pragma once
#include "User.h"

class Doctor;  // Forward declaration
class Patient; // Forward declaration

// Class representing a patient's medical record
class MedicalRecord {
private:
    int recordID;                // Unique identifier for the medical record
    shared_ptr<Patient> client;            // Pointer to the patient associated with this record
    shared_ptr<Doctor> doctor;             // Pointer to the doctor associated with this record
    map<string, DateTime> diagnosis;             // Map of diagnosis with date of diagnosis 
    map<string, vector<string>> treatment;      // Map of diagnosis with corresponding treatments

public:
    // Parameterized constructor
    MedicalRecord(shared_ptr<Patient> patient, shared_ptr<Doctor> doctor, string diagnosis, string treatment);

    // Set the doctor for this medical record
    void setDoctor(shared_ptr<Doctor> doctor);

    // Set the patient for this medical record
    void setPatient(shared_ptr<Patient> patient);

    // Add a diagnosis to the record
    void addDiagnosis(const string& diagnosis, DateTime date);

    // Add a treatment to the record
    void addTreatment(const string& diagnosis, const string& treatment);

    // Get the doctor associated with this medical record
    shared_ptr<Doctor> getDoctor() const;

    // Get the patient associated with this medical record
    shared_ptr<Patient> getPatient() const;

    // Get the unique identifier for this medical record
    int getRecordID() const;

    // Get the history of diagnoses
    map<string, DateTime> getDiagnosisHistory() const;

    // Get the treatments associated with diagnoses
    map<string, string> getTreatment() const;
};
