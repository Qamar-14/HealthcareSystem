#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include "ExternalDataTypes.h"

using namespace std;

static int UserIDs;

class User {

private:
	// Method to hash the password (placeholder for actual hashing logic)
	string hashPassword(string password) {
		// Implement your hashing logic here (e.g., using BCrypt)
		return password; // Placeholder, replace with hashed password
	}

protected:
	int userID;              // Unique identifier for the user
	string userName;         // User's name
	string phone;            // User's phone number
	string email;            // User's email address
	string password;         // User's hashed password
	Role title;              // User's role (e.g., admin, patient, doctor)

	// Set and hash the password
	void setPassword(string password) {
		this->password = hashPassword(password); // Ensure password is hashed
	}

public:
	// Constructor to initialize a User object
	User(string username, string email, string password, string phone, Role title);

	// copy constructer
	User(const User& other);

	// Copy assignment operator overloading
	User& operator=(const User& other);

	// Method for user login (checks email and password)
	bool login(string email, string password);

	// Setters
	void setPhone(string newPhone);
	void setUserName(string name);
	void setEmail(string email);
	void setTitle(Role title);

	// Getters
	string getPhone();
	string getUserName();
	string getEmail();
	Role getTitle();
	virtual int	getID();
};
