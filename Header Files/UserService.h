#pragma once
#include "Admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "MedicalRecord.h"

// Implementation of Singleton Class 
class UserService {
private:
	shared_ptr<Admin> admin;
	// Static pointer to the singleton instance
	static shared_ptr<UserService> instancePtr;

	// Private constructor to prevent instantiation
	UserService() {}

public:
	// Deleting copy constructor and assignment operator
	UserService(const UserService& obj) = delete;
	UserService& operator=(const UserService& obj) = delete;


	// Static method to get the singleton instance
	static shared_ptr<UserService> getInstance();

	// Static method to initialize the UserService with an Admin instance
	//Before using UserService, you need to initialize it with an Admin instance.
	static void initialize(const shared_ptr<Admin>& admin);

	// Static method to get all doctors
	static unordered_map<int, shared_ptr<User>> getAllDoctors();

	// static method to cancel appointment
	static void cancelAppointment(shared_ptr<User> user, int appointmentID, Role title);

	// static method to add an appointment to the doctors schedule
	static void addAppointment(shared_ptr<Doctor> doc, shared_ptr<Appointment> appointment, int appointmentID);

	// static method for doctor to add medical record of patient
	static void addMedicalRecord(shared_ptr<Patient> patient, shared_ptr<Doctor> doc, string diagnosis, string treatment);

	// static method for doctor to update an exisiting medical record of patient
	static void updateMedicalRecord(shared_ptr<Patient> patient, string diagnosis, string treatment);


	// static Method to return patients profile
	static shared_ptr<PatientProfile> viewProfile(const int patientID);

};

	

