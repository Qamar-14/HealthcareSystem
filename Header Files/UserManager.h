#pragma once
#include <unordered_map>
#include <memory>

using namespace std;

// Template class to manage users of type T
template <typename T>
class UserManager {
private:
    unordered_map<int, shared_ptr<T>> users; // Map of user IDs to user objects

public:
    // Add a user to the manager
    void addUser(shared_ptr<T> user) {
        users[user->getID()] = user; // Add user to the map using their ID
    }

    // Retrieve a user by their userID
    shared_ptr<T> getUser(int userID) {
        for (const auto& pair : users) {
            if (pair.second->User::getID() == userID)
            {
                return pair.second;
            }
        }
        return nullptr; // Return user if found, otherwise nullptr
    }

    // Get all users managed by this UserManager
    unordered_map<int, shared_ptr<T>> getAllUsers() {
        return users; // Return the entire map of users
    }

    // Delete a user by their ID
    void deleteUser(int userID) {
        users.erase(userID); // Remove user from the map by ID
    }
};
