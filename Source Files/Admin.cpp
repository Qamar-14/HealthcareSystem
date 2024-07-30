#include "Admin.h"

static int AdminIDs = 1;
static vector<Admin> listOfAdmins;

int Admin::getID(){
    return this->adminID;
}

Admin::Admin(string username, string email, string password, string phone, Role title) :
    User(username, email, password, phone, title) {
    this->adminID = AdminIDs;
    AdminIDs++;
    listOfAdmins.push_back(*this);
}
// Add a user to the appropriate manager based on user type
void Admin::addUser(shared_ptr<User> user) {
    if (user->getTitle() == doctor) {
        auto doc = make_shared<Doctor>(*user);
        doctorManager.addUser(doc); // Add to doctor manager
    }
    else if (user->getTitle() == patient) {
        auto pat = make_shared<Patient>(*user);
        patientManager.addUser(pat); // Add to patient manager
    }
}

// Retrieve a user by their userID from either manager
shared_ptr<User> Admin::getUser(int userID) {
    // First try to find the userID in doctorManager
    auto user = doctorManager.getUser(userID);
    if (user){
        shared_ptr<User> user = dynamic_pointer_cast<User>(user);
        return user;

    }
    // If not found, try to find in patientManager
    else {
        auto pat = patientManager.getUser(userID);
        if (pat) {
            shared_ptr<User> pat = dynamic_pointer_cast<User>(pat);
            return pat;
        }
    }  
    return nullptr;
}

// Retrieve all users of a specific role (doctor or patient)
unordered_map<int, shared_ptr<User>> Admin::getAllUsers(Role title) {
    // Return all doctors
    if (title == Role::doctor) {
        // convert from type Doctor to User first
        unordered_map<int, shared_ptr<Doctor>> doctorsMap = doctorManager.getAllUsers();
        unordered_map<int, shared_ptr<User>> users;

        for (const auto& entry : doctorsMap) {
            shared_ptr<User> userPtr = dynamic_pointer_cast<User>(entry.second);
            if (userPtr)
            {
                users[entry.first] = userPtr;
            }
        }
        return users;
    }
    // Return all patients
    if (title == Role::patient) {
        // convert from type Doctor to User first
        unordered_map<int, shared_ptr<Patient>> patientMap = patientManager.getAllUsers();
        unordered_map<int, shared_ptr<User>> users;

        for (const auto& entry : patientMap) {
            shared_ptr<User> userPtr = dynamic_pointer_cast<User>(entry.second);
            if (userPtr)
            {
                users[entry.first] = userPtr;
            }
        }
        return users;
    }
    // Return an empty map if role is invalid
    return {};
}

// Delete a user by their ID from both managers
void Admin::deleteUser(shared_ptr<User> user) {
    if (user->getTitle() == doctor) {
        doctorManager.deleteUser(user->getID()); // Attempt to delete from doctor manager
    }
    if (user->getTitle() == patient) {
        patientManager.deleteUser(user->getID()); // Attempt to delete from patient manager
    }
}