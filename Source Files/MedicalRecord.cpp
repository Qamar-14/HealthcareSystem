#include "MedicalRecord.h"

static int recordIDs =1;

// Parameterized constructor
MedicalRecord::MedicalRecord(shared_ptr<Patient> patient, shared_ptr<Doctor> doctor, string diagnosis, string treatment) : client(patient), doctor(doctor) {
    this->diagnosis[diagnosis] = getCurrentDateTime();
    this->treatment[diagnosis].push_back(treatment);
    this->recordID = recordIDs;
    recordIDs++;
}

// Set the doctor for this medical record
void MedicalRecord::setDoctor(shared_ptr<Doctor> doctor) {
    this->doctor = doctor;
}

// Set the patient for this medical record
void MedicalRecord::setPatient(shared_ptr<Patient> patient) {
    this->client = patient;
}

// Add a diagnosis to the record
void MedicalRecord::addDiagnosis(const string& diagnosis, DateTime date) {
    this->diagnosis[diagnosis] = date;
}

// Add a treatment to the record
void MedicalRecord::addTreatment(const string& diagnosis, const string& treatment) {
    this->treatment[diagnosis].push_back(treatment);
}

// Get the doctor associated with this medical record
shared_ptr<Doctor> MedicalRecord::getDoctor() const {
    return doctor;
}

// Get the patient associated with this medical record
shared_ptr<Patient> MedicalRecord::getPatient() const {
    return client;
}

// Get the unique identifier for this medical record
int MedicalRecord::getRecordID() const {
    return recordID;
}

// Get the history of diagnosis
map<string, DateTime> MedicalRecord::getDiagnosisHistory() const {
    return diagnosis;
}

