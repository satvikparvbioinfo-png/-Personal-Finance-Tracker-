// ─────────────────────────────────────────
// File    : Transaction.h
// Author  : Anvi Mahajan
// Purpose : Defines the Transaction class which stores
//           one single income or expense record
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transaction {

private:
    // Private data members — cannot be accessed directly from outside
    int id;             // Unique number for each transaction
    string type;        // "income" or "expense"
    string category;    // e.g. Food, Rent, Salary, Transport
    float amount;       // Money amount in Rupees
    string date;        // Format: DD-MM-YYYY
    string description; // Short note about this transaction

public:

    // --- Default Constructor ---
    // Creates an empty Transaction when no values are given
    Transaction() {
        id          = 0;
        type        = "";
        category    = "";
        amount      = 0;
        date        = "";
        description = "";
    }

    // --- Parameterized Constructor ---
    // Creates a Transaction with all values provided directly
    // Used when loading saved data from file
    Transaction(int i, string t, string c, float a, string d, string desc) {
        id          = i;
        type        = t;
        category    = c;
        amount      = a;
        date        = d;
        description = desc;
    }

    // --- Destructor ---
    // Runs automatically when object is destroyed
    ~Transaction() {}

    // --- Getter Functions ---
    // Other classes use these to read private data safely
    int    getId()          { return id; }
    string getType()        { return type; }
    string getCategory()    { return category; }
    float  getAmount()      { return amount; }
    string getDate()        { return date; }
    string getDescription() { return description; }

    // --- Setter Functions ---
    // Used when loading data from file to set values one by one
    void setId(int i)             { id = i; }
    void setType(string t)        { type = t; }
    void setCategory(string c)    { category = c; }
    void setAmount(float a)       { amount = a; }
    void setDate(string d)        { date = d; }
    void setDescription(string s) { description = s; }

    // --- Operator Overloading > ---
    // Naturally useful — lets Account find the highest expense
    // Example: if (t1 > t2) then t1 has higher amount
    bool operator>(Transaction other) {
        return amount > other.amount;
    }

    // --- input() ---
    // Takes all transaction details from the user
    void input(int newId) {
        id = newId; // ID is assigned by Account, not entered by user

        cout << "\n  Enter type (income/expense) : ";
        cin >> type;

        // Keep asking until user enters a valid type
        while (type != "income" && type != "expense") {
            cout << "  Invalid! Please enter income or expense : ";
            cin >> type;
        }

        cout << "  Enter category (Food/Rent/Salary/Transport/Other) : ";
        cin >> category;

        cout << "  Enter amount (Rs.) : ";
        cin >> amount;

        // Amount must be greater than zero
        while (amount <= 0) {
            cout << "  Amount must be greater than 0. Enter again : ";
            cin >> amount;
        }

        cout << "  Enter date (DD-MM-YYYY) : ";
        cin >> date;

        cin.ignore(); // Clear leftover newline before getline
        cout << "  Enter description : ";
        getline(cin, description);
    }

    // --- display() ---
    // Prints all details of this transaction neatly
    void display() {
        cout << "\n  ==============================" << endl;
        cout << "  ID          : " << id          << endl;
        cout << "  Type        : " << type        << endl;
        cout << "  Category    : " << category    << endl;
        cout << "  Amount      : Rs. " << amount  << endl;
        cout << "  Date        : " << date        << endl;
        cout << "  Description : " << description << endl;
        cout << "  ==============================" << endl;
    }

    // --- summary() ---
    // Prints a short one line view — used when showing all transactions
    void summary() {
        cout << "  [" << id << "] " << date << " | "
             << type << " | " << category
             << " | Rs. " << amount << endl;
    }

    // --- isExpense() ---
    // Returns true if this transaction is an expense
    // Used in Account to calculate total expenses
    bool isExpense() {
        return type == "expense";
    }

    // --- isIncome() ---
    // Returns true if this transaction is an income
    // Used in Account to calculate total income
    bool isIncome() {
        return type == "income";
    }
};