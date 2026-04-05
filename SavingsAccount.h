// ─────────────────────────────────────────
// File    : SavingsAccount.h
// Author  : Satvik Parv
// Purpose : Savings pot with goal tracking
//           and simple interest calculator
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// SavingsAccount inherits from Account
// gets all Account features and adds savings specific stuff on top
class SavingsAccount : public Account {

private:
    // savings specific data
    string goalName;    // name of the savings goal
    float goalAmount;   // target amount to reach
    float savedAmount;  // how much has been saved so far
    float interestRate; // annual interest rate in %

public:

    // constructor - zeros everything out
    SavingsAccount() {
        goalName     = "";
        goalAmount   = 0;
        savedAmount  = 0;
        interestRate = 0;
    }

    // destructor - nothing to do here
    ~SavingsAccount() {}

    // getters - for reading savings data from outside
    string getGoalName()    { return goalName; }
    float  getGoalAmount()  { return goalAmount; }
    float  getSavedAmount() { return savedAmount; }

    // takes savings goal details from the user
    void setup() {
        cin.ignore(); // clearing buffer before getline
        cout << "\n  Enter goal name : ";
        getline(cin, goalName);

        cout << "  Enter target amount (Rs.) : ";
        cin >> goalAmount;

        // keep asking if its not a valid amount
        while (goalAmount <= 0) {
            cout << "  Enter a valid amount : ";
            cin >> goalAmount;
        }

        cout << "  Enter interest rate (%) : ";
        cin >> interestRate;

        // same for interest rate
        while (interestRate <= 0) {
            cout << "  Enter a valid rate : ";
            cin >> interestRate;
        }

        savedAmount = 0; // starting fresh
        cout << "\n  Savings goal set!" << endl;
    }

    // adds money into the savings pot
    void deposit() {
        float amount;
        cout << "\n  Enter amount to deposit (Rs.) : ";
        cin >> amount;

        if (amount <= 0) {
            cout << "  Invalid amount." << endl;
            return;
        }

        savedAmount = savedAmount + amount;
        cout << "  Rs. " << amount << " deposited!" << endl;

        // let them know if they've hit the goal
        if (savedAmount >= goalAmount) {
            cout << "  You have reached your savings goal!" << endl;
        }
    }

    // takes money out of the savings pot
    void withdraw() {
        float amount;
        cout << "\n  Enter amount to withdraw (Rs.) : ";
        cin >> amount;

        if (amount <= 0) {
            cout << "  Invalid amount." << endl;
            return;
        }

        // cant withdraw more than whats saved
        if (amount > savedAmount) {
            cout << "  Not enough savings. You have Rs. "
                 << savedAmount << endl;
            return;
        }

        savedAmount = savedAmount - amount;
        cout << "  Rs. " << amount << " withdrawn." << endl;
    }

    // simple interest formula - P * R * T / 100
    float calculateInterest(float time) {
        return (savedAmount * interestRate * time) / 100;
    }

    // shows current savings status and goal progress
    void showBalance() {
        cout << "\n  ==============================" << endl;
        cout << "       SAVINGS ACCOUNT"            << endl;
        cout << "  ==============================" << endl;
        cout << "  Goal     : " << goalName         << endl;
        cout << "  Target   : Rs. " << goalAmount   << endl;
        cout << "  Saved    : Rs. " << savedAmount  << endl;
        cout << "  Remaining: Rs. " << goalAmount - savedAmount << endl;
        cout << "  ==============================" << endl;
    }

    // asks for a time period and shows the interest breakdown
    void showInterest() {
        float time;
        cout << "\n  Enter time in years : ";
        cin >> time;

        if (time <= 0) {
            cout << "  Invalid time." << endl;
            return;
        }

        float interest = calculateInterest(time);

        cout << "\n  ==============================" << endl;
        cout << "    INTEREST CALCULATOR"           << endl;
        cout << "  ==============================" << endl;
        cout << "  Principal : Rs. " << savedAmount    << endl;
        cout << "  Rate      : " << interestRate << "%" << endl;
        cout << "  Time      : " << time << " year(s)"  << endl;
        cout << "  Interest  : Rs. " << interest        << endl;
        cout << "  Total     : Rs. " << savedAmount + interest << endl;
        cout << "  ==============================" << endl;
    }

    // returns true if a savings goal has been set up already
    bool isGoalSet() {
        return goalName != "";
    }
};