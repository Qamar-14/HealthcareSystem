#include "User.h"

// Constructor to initialize a User object
User::User(string username, string email, string password, string phone, Role title) {
    this->userName = username;
    this->email = email;
    this->title = title;
    this->phone = phone;
    setPassword(password); // Use setter for hashing
    this->userID = UserIDs;
    UserIDs++;
}

//Copy constructer
User::User(const User& other)
{
    this->userName = other.userName;
    this->email = other.email;
    this->title = other.title;
    this->phone = other.phone;
    this->userID = other.userID;
    this->password = other.password;
}

// Copy assignment operator.
User& User::operator=(const User& other)
{
    if (this != &other)
    {
        // Free the existing resource.


        this->userName = other.userName;
        this->email = other.email;
        this->title = other.title;
        this->phone = other.phone;
        this->userID = other.userID;
        this->password = other.password;
    }
    return *this;
}

int User::getID() {
    return this->userID;
}