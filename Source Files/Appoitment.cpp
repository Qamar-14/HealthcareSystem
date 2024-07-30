#include "Appointment.h"

static int appointmentIDs =1;

// Constructor
Appointment::Appointment(DateTime dateTime, shared_ptr<Doctor> doctor, shared_ptr<Patient> client)
    : dateAndTime(dateTime), doctor(doctor), client(client), status(Booked) 
{
    this->appointmentID = appointmentIDs;
    appointmentIDs++;
}

// setter methods
void Appointment::setDateAndTime(DateTime date) {
    dateAndTime = date;
}

void Appointment::setPatient(std::shared_ptr<Patient> patient) {
    client = patient;
}

void Appointment::setDoctor(std::shared_ptr<Doctor> doctor) {
    this->doctor = doctor;
}

void Appointment::setStatus(Status status) {
    this->status = status;
}


// getter methods
int Appointment::getAppointmentId() const {
    return appointmentID;
}

DateTime Appointment::getDateAndTime() const {
    return dateAndTime;
}

shared_ptr<Patient> Appointment::getPatient() const {
    return client;
}
shared_ptr<Doctor> Appointment::getDoctor() const {
    return doctor;
}

Status Appointment::getStatus() const {
    return status;
}
