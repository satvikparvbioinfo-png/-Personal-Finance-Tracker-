// ─────────────────────────────────────────
// File    : Notification.h
// Author  : Satvik Parv
// Purpose : Checks financial conditions on startup
//           and shows smart alerts to the user
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

class Notification {

private:
    // all alert messages collected here before displaying
    vector<string> messages;

public:

    // constructor and destructor - nothing special needed
    Notification() {}
    ~Notification() {}

    // adds a single alert message to the vector
    void addMessage(string msg) {
        messages.push_back(msg);
    }

    // runs all 8 financial checks using Account and SavingsAccount data
    void checkAll(Account& acc, SavingsAccount& sav) {
        messages.clear(); // clearing old messages before a fresh check

        // check 1 - is balance positive or negative
        if (acc.getBalance() < 0) {
            addMessage("ALERT: Your balance is negative! Rs. "
                + to_string(acc.getBalance()));
        }
        else {
            addMessage("OK: Balance is positive. Rs. "
                + to_string(acc.getBalance()));
        }

        // check 2 - are expenses greater than income
        if (acc.getTotalExpense() > acc.getTotalIncome()) {
            addMessage("ALERT: Your expenses are more than your income!");
        }
        else {
            addMessage("OK: Income is greater than expenses.");
        }

        // check 3 - is balance dangerously low (less than 10% of income)
        if (acc.getTotalIncome() > 0) {
            float tenPercent = acc.getTotalIncome() * 0.10;
            if (acc.getBalance() < tenPercent) {
                addMessage("WARNING: Balance is less than 10% of your income!");
            }
        }

        // check 4 - are any budgets exceeded
        vector<Budget> budgets = acc.getBudgets();
        bool anyExceeded = false;
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i].isExceeded()) {
                addMessage("ALERT: Budget exceeded for category: "
                    + budgets[i].getCategory());
                anyExceeded = true;
            }
        }
        if (!anyExceeded && budgets.size() > 0) {
            addMessage("OK: All budgets are within limits.");
        }

        // check 5 - has user set any budgets at all
        if (budgets.size() == 0) {
            addMessage("TIP: You have not set any budgets yet. Consider setting some!");
        }

        // check 6 - has user set a savings goal
        if (!sav.isGoalSet()) {
            addMessage("TIP: You have not set a savings goal yet.");
        }

        // check 7 - has savings goal been reached
        if (sav.isGoalSet() && sav.getSavedAmount() >= sav.getGoalAmount()) {
            addMessage("Congratulations! You have reached your savings goal!");
        }

        // check 8 - are there any transactions recorded at all
        if (acc.getTransactions().size() == 0) {
            addMessage("TIP: No transactions yet. Start by adding income or expense.");
        }
    }

    // displays all collected alert messages on screen
    void showNotifications() {
        if (messages.size() == 0) {
            cout << "\n  No notifications." << endl;
            return;
        }

        cout << "\n  ==============================" << endl;
        cout << "       SMART NOTIFICATIONS"       << endl;
        cout << "  ==============================" << endl;

        // printing each message with a number
        for (int i = 0; i < messages.size(); i++) {
            cout << "  [" << i + 1 << "] " << messages[i] << endl;
        }

        cout << "  ==============================" << endl;
    }
};