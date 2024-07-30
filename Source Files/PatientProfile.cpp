#include "PatientProfile.h"


void PatientProfile::setName(string name) {
	this->fullName = name;
}

void PatientProfile::setAddress(string newAddress) {
	this->address = newAddress;
}

void PatientProfile::setGender(Gender gender) {
	this->gender = gender;
}

void PatientProfile::setHeight(double newHeight) {
	this->height = newHeight;
}

void PatientProfile::setWeight(double newWeight) {
	this->weight = newWeight;
}

void PatientProfile::setDateOfBirth(DateTime birth) {
	this->dateOfbirth = birth;
}

void PatientProfile::setBloodType(BloodType bloodtype) {
	this->bloodtype = bloodtype;
}

string PatientProfile::getName() {
	return this->fullName;
}


string PatientProfile::getAddress() {
	return this->address;
}

Gender PatientProfile::getGender() {
	return this->gender;
}

double PatientProfile::getHeight() {
	return this->height;
}

double PatientProfile::getWeight() {
	return this->weight;
}

DateTime PatientProfile::getDateOfBirth() {
	return this->dateOfbirth;
}

BloodType PatientProfile::getBloodType() {
	return this->bloodtype;
}