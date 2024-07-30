#include "Patient.h"
#include "UserService.h"

static int patientIDs = 1;

Patient::Patient(string username,string email, string password, string phone, Role title):
	User(username, email, password, phone, title){
	this->patientID = patientIDs;
	patientIDs++;
}

//Copy constructer
Patient::Patient(const Patient& other) :
    User(other), // Call the base class copy constructor
    patientID(other.patientID),
    medicalHistory(other.medicalHistory ? make_unique<MedicalRecord>(*other.medicalHistory) : nullptr),
    profile(other.profile ? make_unique<PatientProfile>(*other.profile) : nullptr),
    appointments(other.appointments) // Copy of map<int, shared_ptr<Appointment>>
{}

// Copy assignment operator.
Patient& Patient::operator=(const Patient& other)
{
    if (this != &other)
    {
        User::operator=(other);

        this->patientID = other.patientID;

        // Deep copy MedicalRecord
        if (other.medicalHistory) {
            this->medicalHistory = make_unique<MedicalRecord>(*other.medicalHistory);
        }
        else {
            this->medicalHistory.reset(); // Ensure no dangling pointer
        }

        // Deep copy PatientProfile
        if (other.profile) {
            this->profile = make_unique<PatientProfile>(*other.profile);
        }
        else {
            this->profile.reset(); // Ensure no dangling pointer
        }

        // Copy of map<int, shared_ptr<Appointment>>
        this->appointments = other.appointments;

    }
    return *this;
}

// Move constructor
Patient::Patient(Patient&& other) 
    : User(move(other)),
    patientID(other.patientID),
    medicalHistory(move(other.medicalHistory)),
    profile(move(other.profile)),
    appointments(move(other.appointments))
{
    other.patientID = 0; // Reset the state of the moved-from object
}

// Function to manage the profile
void Patient::manageProfile(const string& fullName, BloodType bloodtype, Gender gender, const string& address, double height, double weight, DateTime dateOfBirth) {
    if (!this->profile) { // Check if the profile does not exist
        this->profile = make_unique<PatientProfile>();
    }

    // Update profile details
    this->profile->setName(fullName);
    this->profile->setBloodType(bloodtype);
    this->profile->setGender(gender);
    this->profile->setAddress(address);
    this->profile->setHeight(height);
    this->profile->setWeight(weight);
    this->profile->setDateOfBirth(dateOfBirth);
}

int Patient::getID(){
	return this->patientID;
}

void Patient::setMedicalRecord(shared_ptr<MedicalRecord> medicalHistory) {
    this->medicalHistory = medicalHistory;
}

map<int, shared_ptr<Appointment>> Patient::getAppointments() {
    return this->appointments;
}

shared_ptr<MedicalRecord> Patient::getMedicalHistory() const {
    if (this->medicalHistory) {
        // Return a deep copy of the medical history
        return this->medicalHistory;
    }
    else {
        // Return an empty unique_ptr
        return nullptr;
    }
}

shared_ptr<PatientProfile> Patient::getProfile() const {
    if (this->profile) {
        // Return a deep copy of the medical history
        return this->profile;
    }
    else {
        // Return an empty unique_ptr
        return nullptr;
    }
}

vector<shared_ptr<User>> searchDoctor(Specialty field) {

    vector<shared_ptr<User>> result;

    unordered_map<int, shared_ptr<User>> doctors = UserService::getAllDoctors();

    // Iterate over all doctors in the manager
    for (const auto& entry : doctors) {
        shared_ptr<Doctor> doc = dynamic_pointer_cast<Doctor>(entry.second);
        if (doc && doc->getSpecialty() == field) {
            result.push_back(entry.second);
        }
    }

    return result;
}

Status Patient::scheduleAppointment(shared_ptr<Doctor> doctor, DateTime dateTime) {
    if (doctor->checkAvailability(dateTime))
    {
        auto client = make_shared<Patient>(this);

        // Book appointment
        auto appointment = make_shared<Appointment>(dateTime, doctor, client);
        this->appointments[appointment->getAppointmentId()] = appointment;

        UserService::addAppointment(doctor, appointment, appointment->getAppointmentId());

        return Status::Booked;
    }
    return Status::Busy;
}

void Patient::cancelAppointment(const int appointmentID) {
    
    auto doc = this->appointments[appointmentID]->getDoctor();

    UserService::cancelAppointment(doc, appointmentID, Role::patient);

    this->appointments.erase(appointmentID);
        
}
