#pragma once
#include "User.h"
#include "UserManager.h"

class Doctor;  // Forward declaration of Doctor class
class Patient; // Forward declaration of Patient class

// Class for managing users (Doctors and Patients)
class Admin : public User {
private:
    int adminID;
    static UserManager<Doctor> doctorManager; // Manages Doctor objects
    static UserManager<Patient> patientManager; // Manages Patient objects


public:
    // Constructor to initialize a Patient object
    Admin(string username, string email, string password, string phone, Role title);

    // Getter for the Admin ID (override base class Id getter method)
    int getID() override;
 
    // Add a user to the appropriate manager based on user type
    void addUser(shared_ptr<User> user);

    // Delete a user by their ID from both managers
    void deleteUser(shared_ptr<User> user);

    // Retrieve a user by their ID from either manager
    shared_ptr<User> getUser(int userID);

    // Retrieve all users of a specific role (doctor or patient)
    unordered_map<int, shared_ptr<User>> getAllUsers(Role title);


};
