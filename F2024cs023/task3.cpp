#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PasswordManager {
private:
    vector<string> usernames;
    vector<unsigned long> hashes;
    
    unsigned long hashFunction(string password) {
        unsigned long hash = 5381;
        for (int i = 0; i < password.length(); i++) {
            hash = ((hash << 5) + hash) + password[i];
        }
        return hash;
    }
    
    int findUser(string username) {
        for (int i = 0; i < usernames.size(); i++) {
            if (usernames[i] == username) return i;
        }
        return -1;
    }

public:
    void addUser(string username, string password) {
        if (findUser(username) != -1) {
            cout << "Username already exists." << endl;
            return;
        }
        if (username.empty() || password.empty()) {
            cout << "Invalid input." << endl;
            return;
        }
        usernames.push_back(username);
        hashes.push_back(hashFunction(password));
        cout << "User added." << endl;
    }
    
    bool verifyUser(string username, string password) {
        int index = findUser(username);
        if (index == -1) return false;
        return hashes[index] == hashFunction(password);
    }
    
    void displayUsers() {
        if (usernames.empty()) {
            cout << "No users." << endl;
            return;
        }
        cout << "Users:" << endl;
        for (int i = 0; i < usernames.size(); i++) {
            cout << usernames[i] << endl;
        }
    }
};

int main() {
    PasswordManager pm;
    int option;
    string user, pass;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Login\n";
        cout << "3. Display Users\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> option;
        
        switch(option) {
            case 1:
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter password: ";
                cin >> pass;
                pm.addUser(user, pass);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter password: ";
                cin >> pass;
                if (pm.verifyUser(user, pass)) {
                    cout << "Login successful." << endl;
                } else {
                    cout << "Invalid credentials." << endl;
                }
                break;
            case 3:
                pm.displayUsers();
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (option != 0);
    
    return 0;
}