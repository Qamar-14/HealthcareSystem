#include "Doctor.h"
#include "UserService.h"

static int DoctorIDs = 1;

//Constructer
Doctor::Doctor(string name, string username, string email, string password, string phone, Role title, Gender gender, string clinicAddress, Specialty field) :
    User(username, email, password, phone, title) {
    this->doctorID = DoctorIDs;
    DoctorIDs++;
    this->gender = gender;
    this->clinicAddress = clinicAddress;
    this->name = name;
    this->field = field;
}

//Copy constructer
Doctor::Doctor(const Doctor& other) :
    User(other), // Call the base class copy constructor
    name(other.name),
    doctorID(other.doctorID),
    gender(other.gender),
    clinicAddress(other.clinicAddress),
    schedule(other.schedule) // Copy vector of shared_ptr<Appointment>
{
    this->field = other.field;
}

// Setter for the clinic address
void Doctor::setClinicAddress(string clinicAddress) {
    this->clinicAddress = clinicAddress;
}

// Setter for the doctor's gender
void Doctor::setGender(Gender gender) {
    this->gender = gender;
}

// Setter for the doctor's specialty
void Doctor::setSpecialty(Specialty field) {
    this->field = field;
}

// Setter for the doctor's name
void Doctor::setName(string name) {
    this->name = name;
}

// Getter for the clinic address
string Doctor::getClinicAddress() const {
    return clinicAddress;
}

// Getter for the doctor's gender
Gender Doctor::getGender() const {
    return gender;
}

// Getter for the doctor's specialty
Specialty Doctor::getSpecialty() const {
    return field;
}

// Getter for the doctor's name
string Doctor::getName() const {
    return name;
}

// Getter for the Doctor ID (override base class Id getter method)
int Doctor::getID() {
    return doctorID;
}

// Getter for doctors schedule
map<int, shared_ptr<Appointment>> Doctor::getSchedule() {
    return this->schedule;
}

// Function to view patient's profile
shared_ptr<PatientProfile> Doctor::viewPatientProfile(const int patientID) {
    //Print details using UserService
    return UserService::viewProfile(patientID);

}

// Function to add a medical record for the patient
void Doctor::addMedicalRecord(shared_ptr<Patient> patient, string diagnosis,string treatment){
    
    auto doc = make_shared<Doctor>(this);

    UserService::addMedicalRecord(patient, doc, diagnosis, treatment);
}

// Function to update a medical record of a patient
void Doctor::updateMedicalRecord(shared_ptr<Patient> patient, string diagnosis, string treatment) {
    UserService::updateMedicalRecord(patient, diagnosis, treatment);
}


// Function to add an appointment to the doctor's schedule 
void Doctor::addAppointment(const shared_ptr<Appointment> appointment, int appointmentID) {
    this->schedule[appointmentID] = appointment;
}

// Function to remove an appointment from the doctor's schedule
void Doctor::cancelAppointment(int appointmentID) {

    auto pat = this->schedule[appointmentID]->getPatient();

    UserService::cancelAppointment(pat, appointmentID, Role::doctor);

    this->schedule.erase(appointmentID);
}

// Fuction to check if there is an available slot with the given date and time in the doctor's schedule.
bool Doctor::checkAvailability(DateTime dateTime) {
 
    for (const auto& it : this->schedule)
    {
        if (it.second->getDateAndTime() == dateTime) {
            return false;
        }
    }
    return true;
}



