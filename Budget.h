// ─────────────────────────────────────────
// File    : Budget.h
// Author  : Anvi Mahajan
// Purpose : Lets the user set a spending limit for a
//           category and warns them if they go over it
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Budget {

private:
    // keeping these private as usual
    string category;  // which category this budget is for e.g. Food, Rent
    float limit;      // max amount allowed to spend
    float spent;      // how much has been spent so far

public:

    // default constructor - empty object, nothing set yet
    Budget() {
        category = "";
        limit    = 0;
        spent    = 0;
    }

    // parameterized constructor - category and limit given directly
    Budget(string c, float l) {
        category = c;
        limit    = l;
        spent    = 0; // spent always starts at zero
    }

    // destructor - nothing special here
    ~Budget() {}

    // getters - for reading private data from outside
    string getCategory() { return category; }
    float  getLimit()    { return limit; }
    float  getSpent()    { return spent; }

    // setters - for updating category and limit
    void setCategory(string c) { category = c; }
    void setLimit(float l)     { limit = l; }

    // adds an expense amount to the running spent total
    // Account class calls this whenever a new expense is recorded
    void addSpending(float amount) {
        spent = spent + amount;
    }

    // returns how much budget is still left
    float getRemainingLimit() {
        return limit - spent;
    }

    // returns true if spending has crossed the limit
    bool isExceeded() {
        return spent > limit;
    }

    // takes budget details from the user via keyboard
    void setLimit() {
        cout << "\n  Enter category to set budget for : ";
        cin >> category;

        cout << "  Enter spending limit (Rs.) : ";
        cin >> limit;

        // limit has to be a positive number, keep asking if not
        while (limit <= 0) {
            cout << "  Limit must be greater than 0. Enter again : ";
            cin >> limit;
        }

        spent = 0; // resetting spent whenever a new budget is set
        cout << "\n  Budget set! Category: " << category
             << " | Limit: Rs. " << limit << endl;
    }

    // checks how much is spent vs the limit and shows the status
    // using exception handling here to flag if budget is exceeded
    void checkBudget() {
        cout << "\n  ==============================" << endl;
        cout << "  Category  : " << category        << endl;
        cout << "  Limit     : Rs. " << limit       << endl;
        cout << "  Spent     : Rs. " << spent       << endl;
        cout << "  Remaining : Rs. " << getRemainingLimit() << endl;

        try {
            if (isExceeded()) {
                // throwing the overspent amount as the exception message
                throw string("Budget exceeded by Rs. " +
                      to_string(spent - limit));
            }
            cout << "  Status    : OK - Within budget" << endl;
        }
        catch (string message) {
            // catching it here and showing the warning
            cout << "  Status    : WARNING! " << message << endl;
        }

        cout << "  ==============================" << endl;
    }

    // shows a quick one line summary of this budget
    void showBudget() {
        cout << "  " << category << " | Limit: Rs. " << limit
             << " | Spent: Rs. " << spent
             << " | Remaining: Rs. " << getRemainingLimit();

        // adding a little warning tag if they've gone over
        if (isExceeded()) {
            cout << " | [EXCEEDED]";
        }
        cout << endl;
    }
};