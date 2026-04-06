// ─────────────────────────────────────────
// File    : StudentProfile.h
// Author  : Rishav Raj
// Purpose : Student specific finance tracking.
//           Splits monthly allowance into Needs,
//           Wants and Savings pots. Savings is
//           locked. Needs and Wants can be spent.
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

// StudentProfile inherits from User
// gets name, email, age from User automatically
// and adds student specific allowance tracking on top
class StudentProfile : public User {

private:
    // student specific data
    string course;        // course name e.g. B.Tech Bioinformatics
    float allowance;      // total monthly allowance entered by student

    // three pots split from allowance using the 50/30/20 rule
    float needsTotal;     // 50% — Food, Rent etc
    float wantsTotal;     // 30% — Entertainment etc
    float savingsTotal;   // 20% — locked, cannot be spent

    // remaining balances in each pot after spending
    float needsRemaining;
    float wantsRemaining;

public:

    // constructor - zeros everything out
    StudentProfile() {
        course         = "";
        allowance      = 0;
        needsTotal     = 0;
        wantsTotal     = 0;
        savingsTotal   = 0;
        needsRemaining = 0;
        wantsRemaining = 0;
    }

    // destructor - nothing to do here
    ~StudentProfile() {}

    // takes student details and allowance, then splits it into three pots
    void setup() {
        User::setup(); // calling parent setup first for name, email, age

        cin.ignore(); // clearing buffer before getline
        cout << "  Enter your course name : ";
        getline(cin, course);

        cout << "  Enter your monthly allowance (Rs.) : ";
        cin >> allowance;

        // allowance has to be a positive number
        while (allowance <= 0) {
            cout << "  Amount must be greater than 0. Enter again : ";
            cin >> allowance;
        }

        // automatically splitting using 50/30/20 rule
        needsTotal   = allowance * 0.50; // 50% for Needs
        wantsTotal   = allowance * 0.30; // 30% for Wants
        savingsTotal = allowance * 0.20; // 20% for Savings

        // remaining starts equal to total at the beginning of the month
        needsRemaining = needsTotal;
        wantsRemaining = wantsTotal;

        cout << "\n  Profile created!" << endl;
        cout << "  Your allowance has been split automatically." << endl;
    }

    // deducts an amount from the Needs pot
    // warns if the balance is getting dangerously low
    void spendFromNeeds() {
        float amount;
        cout << "\n  Enter amount spent from Needs (Rs.) : ";
        cin >> amount;

        // cant spend more than whats left in Needs
        if (amount > needsRemaining) {
            cout << "\n  Not enough balance in Needs pot." << endl;
            cout << "  Needs Remaining : Rs. " << needsRemaining << endl;
            return;
        }

        if (amount <= 0) {
            cout << "\n  Amount must be greater than 0." << endl;
            return;
        }

        needsRemaining = needsRemaining - amount;
        cout << "\n  Rs. " << amount << " spent from Needs." << endl;

        // warn if needs balance falls below 20% of the needs total
        if (needsRemaining < needsTotal * 0.20) {
            cout << "  WARNING: Needs balance is getting very low!" << endl;
            cout << "  Only Rs. " << needsRemaining << " remaining in Needs." << endl;
        }
    }

    // deducts an amount from the Wants pot
    void spendFromWants() {
        float amount;
        cout << "\n  Enter amount spent from Wants (Rs.) : ";
        cin >> amount;

        // cant spend more than whats left in Wants
        if (amount > wantsRemaining) {
            cout << "\n  Not enough balance in Wants pot." << endl;
            cout << "  Wants Remaining : Rs. " << wantsRemaining << endl;
            return;
        }

        if (amount <= 0) {
            cout << "\n  Amount must be greater than 0." << endl;
            return;
        }

        wantsRemaining = wantsRemaining - amount;
        cout << "\n  Rs. " << amount << " spent from Wants." << endl;
    }

    // overrides User's showProfile() to include student specific data
    // this is polymorphism - same function name, different behaviour
    void showProfile() override {
        User::showProfile(); // showing base User profile first

        cout << "  Course    : " << course       << endl;
        cout << "  Allowance : Rs. " << allowance << endl;
        cout << "  ==============================" << endl;

        cout << "\n  MONTHLY ALLOWANCE BREAKDOWN" << endl;
        cout << "  ==============================" << endl;

        // Needs pot - can be spent freely
        cout << "  NEEDS (50%)" << endl;
        cout << "  Total     : Rs. " << needsTotal     << endl;
        cout << "  Remaining : Rs. " << needsRemaining << endl;
        cout << "  Spent     : Rs. " << needsTotal - needsRemaining << endl;

        cout << "\n  WANTS (30%)" << endl;
        cout << "  Total     : Rs. " << wantsTotal     << endl;
        cout << "  Remaining : Rs. " << wantsRemaining << endl;
        cout << "  Spent     : Rs. " << wantsTotal - wantsRemaining << endl;

        // Savings pot - locked, not to be touched
        cout << "\n  SAVINGS (20%) [LOCKED]" << endl;
        cout << "  Amount    : Rs. " << savingsTotal << endl;
        cout << "  Status    : Protected - Cannot be spent" << endl;

        cout << "  ==============================" << endl;
    }

    // resets the Needs and Wants pots at the start of a new month
    void resetMonth() {
        needsRemaining = needsTotal;
        wantsRemaining = wantsTotal;
        cout << "\n  Allowance reset for new month!" << endl;
    }
};