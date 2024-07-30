#include "UserService.h"

// Initializing the static member
shared_ptr<UserService> UserService::instancePtr = nullptr;

// Static method to get the singleton instance
shared_ptr<UserService> UserService::getInstance() {
	if (!instancePtr) {
		instancePtr = shared_ptr<UserService>(new UserService());
	}
	return instancePtr;
}

// Static method to initialize the UserService with an Admin instance
//Before using UserService, you need to initialize it with an Admin instance.
void UserService::initialize(const shared_ptr<Admin>& admin) {
	getInstance()->admin = admin;
}

// Static method to get all doctors
unordered_map<int, shared_ptr<User>> UserService::getAllDoctors() {
	shared_ptr<Admin> admin = getInstance()->admin;
	if (admin) {
		auto doctors = admin->getAllUsers(Role::doctor);
		return doctors;
	}
	return {};
}

// static method to cancel appointment
void UserService::cancelAppointment(shared_ptr<User> user, int appointmentID, Role title) {
	// If the doctor is the one canceling
	if (title == Role::doctor) {
		shared_ptr<Patient> pat = dynamic_pointer_cast<Patient>(user);
		// remove from patients list
		pat->getAppointments().erase(appointmentID);

	}
	// else if it is the patient that wants to cancel
	else if (title == Role::patient) {
		shared_ptr<Doctor> doc = dynamic_pointer_cast<Doctor>(user);
		// remove from doctors list
		doc->getSchedule().erase(appointmentID);
	}

}

// static method to add an appointment to the doctors schedule
void UserService::addAppointment(shared_ptr<Doctor> doc, shared_ptr<Appointment> appointment, int appointmentID) {

	doc->addAppointment(appointment, appointmentID);
}

// static method for doctor to add medical record of patient
void UserService::addMedicalRecord(shared_ptr<Patient> patient, shared_ptr<Doctor> doc, string diagnosis, string treatment) {

	unique_ptr<MedicalRecord> medicalHistory = make_unique<MedicalRecord>(patient, doctor, diagnosis, treatment);
	patient->setMedicalRecord(make_unique<MedicalRecord>(*medicalHistory));
}

// static method for doctor to update an exisiting medical record of patient
void UserService::updateMedicalRecord(shared_ptr<Patient> patient, string diagnosis, string treatment) {

	if (patient->getMedicalHistory())
	{
		DateTime dateTime = getCurrentDateTime();

		// Add a diagnosis to the record
		patient->getMedicalHistory()->addDiagnosis(diagnosis, dateTime);

		// Add a treatment to the record
		patient->getMedicalHistory()->addTreatment(diagnosis, treatment);
	}

}

// static Method to return patients profile
shared_ptr<PatientProfile> UserService::viewProfile(const int patientID) {
	static unordered_map<int, shared_ptr<User>> patients;
	shared_ptr<Admin> admin = getInstance()->admin;
	if (admin) {
		auto pat = admin->getAllUsers(Role::patient);
		for (const auto& it : pat)
		{
			shared_ptr<Patient> entry = dynamic_pointer_cast<Patient>(it.second);
			if (entry->getID() == patientID)
			{
				return entry->getProfile();
			}
		}
	}

}

