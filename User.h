// ─────────────────────────────────────────
// File    : User.h
// Author  : Anvi Mahajan
// Purpose : Stores basic profile info of the person
//           using this finance tracker
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {

private:
    // keeping these private, getters/setters handle access
    string name;   // full name of the user
    string email;  // their email address
    int age;       // their age

public:

    // default constructor - empty object, nothing filled yet
    User() {
        name  = "";
        email = "";
        age   = 0;
    }

    // parameterized constructor - used when we already have the values
    User(string n, string e, int a) {
        name  = n;
        email = e;
        age   = a;
    }

    // destructor - not doing anything but keeping it here
    ~User() {}

    // getters - so other parts of the program can read user data
    string getName()  { return name; }
    string getEmail() { return email; }
    int    getAge()   { return age; }

    // setters - for updating user data in a controlled way
    void setName(string n)  { name = n; }
    void setEmail(string e) { email = e; }
    void setAge(int a)      { age = a; }

    // asks the user to enter their profile details from keyboard
    void setup() {
        cin.ignore(); // clearing buffer before getline, otherwise it skips the input
        cout << "\n  Enter your full name  : ";
        getline(cin, name);
        cout << "  Enter your email      : ";
        getline(cin, email);
        cout << "  Enter your age        : ";
        cin >> age;

        // age has to make sense, so keep asking if its weird
        while (age <= 0 || age > 120) {
            cout << "  That doesn't look right. Enter age again : ";
            cin >> age;
        }

        cout << "\n  Profile saved!" << endl;
    }

    // prints the saved profile nicely on screen
    // marked virtual so StudentProfile can override this if needed
    virtual void showProfile() {
        cout << "\n  ==============================" << endl;
        cout << "        USER PROFILE"               << endl;
        cout << "  ==============================" << endl;
        cout << "  Name  : " << name                << endl;
        cout << "  Email : " << email               << endl;
        cout << "  Age   : " << age                 << endl;
        cout << "  ==============================" << endl;
    }

    // returns true if profile has been filled in already
    // just checking if name isnt empty
    bool isProfileSet() {
        return name != "";
    }
};