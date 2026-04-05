// ─────────────────────────────────────────
// File    : Account.h
// Author  : Satvik Parv
// Purpose : Manages all transactions, tracks balance,
//           and saves/loads data to file
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Budget.h"
using namespace std;

class Account {

private:
    vector<Transaction> transactions; // all transactions stored here
    vector<Budget> budgets;           // all budgets stored here
    float totalIncome;                // running total of all income
    float totalExpense;               // running total of all expenses
    int nextId;                       // increments automatically for each new transaction

public:

    // constructor - zeros everything out when Account is created
    Account() {
        totalIncome  = 0;
        totalExpense = 0;
        nextId       = 1; // ids start from 1
    }

    // destructor - nothing to clean up here
    ~Account() {}

    // getters - for reading totals from outside the class
    float getTotalIncome()  { return totalIncome; }
    float getTotalExpense() { return totalExpense; }

    // calculates current balance from the two running totals
    float getBalance() {
        return totalIncome - totalExpense;
    }

    // takes a new transaction from user input and adds it to the list
    void addTransaction() {
        Transaction t;
        t.input(nextId);
        transactions.push_back(t);
        nextId++;

        // update income or expense total depending on what was entered
        if (t.isIncome()) {
            totalIncome = totalIncome + t.getAmount();
        }
        else {
            totalExpense = totalExpense + t.getAmount();

            // check if this expense pushes any matching budget over the limit
            for (int i = 0; i < budgets.size(); i++) {
                if (budgets[i].getCategory() == t.getCategory()) {
                    budgets[i].addSpending(t.getAmount());
                    if (budgets[i].isExceeded()) {
                        cout << "\n  WARNING! " << t.getCategory()
                             << " budget exceeded!" << endl;
                    }
                }
            }
        }

        cout << "\n  Transaction added!" << endl;
    }

    // displays all transactions with a balance summary at the bottom
    void showAll() {
        if (transactions.size() == 0) {
            cout << "\n  No transactions yet." << endl;
            return;
        }

        cout << "\n  ==============================" << endl;
        cout << "      ALL TRANSACTIONS"            << endl;
        cout << "  ==============================" << endl;

        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].summary();
        }

        cout << "  ==============================" << endl;
        cout << "  Income  : Rs. " << totalIncome  << endl;
        cout << "  Expense : Rs. " << totalExpense << endl;
        cout << "  Balance : Rs. " << getBalance() << endl;
        cout << "  ==============================" << endl;
    }

    // lets user set a spending limit for a category
    void setBudget() {
        Budget b;
        b.setLimit();
        budgets.push_back(b);
        cout << "\n  Budget set!" << endl;
    }

    // shows current status of all budgets - whether within limit or exceeded
    void checkBudgets() {
        if (budgets.size() == 0) {
            cout << "\n  No budgets set yet." << endl;
            return;
        }

        cout << "\n  ==============================" << endl;
        cout << "        BUDGET STATUS"             << endl;
        cout << "  ==============================" << endl;

        for (int i = 0; i < budgets.size(); i++) {
            budgets[i].checkBudget();
        }
    }

    // writes all transactions to data.txt, one per line
    // fields separated by | so they can be parsed back easily
    void saveToFile() {
        ofstream file("data.txt");

        if (!file) {
            cout << "\n  Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < transactions.size(); i++) {
            file << transactions[i].getId()          << "|"
                 << transactions[i].getType()        << "|"
                 << transactions[i].getCategory()    << "|"
                 << transactions[i].getAmount()      << "|"
                 << transactions[i].getDate()        << "|"
                 << transactions[i].getDescription() << "\n";
        }

        file.close();
        cout << "\n  Data saved to data.txt!" << endl;
    }

    // reads transactions from data.txt when the program starts
    void loadFromFile() {
        ifstream file("data.txt");

        // no file yet means nothing to load, just return quietly
        if (!file) {
            return;
        }

        transactions.clear();
        totalIncome  = 0;
        totalExpense = 0;

        int   id;
        float amount;
        string type, category, date, description, temp;

        // reading each field using | as the delimiter
        while (getline(file, temp, '|')) {
            id = stoi(temp);
            getline(file, type,        '|');
            getline(file, category,    '|');
            getline(file, temp,        '|'); amount = stof(temp);
            getline(file, date,        '|');
            getline(file, description       );

            // building the transaction straight from the parameterized constructor
            Transaction t(id, type, category, amount, date, description);
            transactions.push_back(t);

            // update totals from whatever was loaded
            if (t.isIncome()) totalIncome  = totalIncome  + t.getAmount();
            else              totalExpense = totalExpense + t.getAmount();

            // keep nextId ahead of all loaded ids
            if (t.getId() >= nextId) nextId = t.getId() + 1;
        }

        file.close();
        cout << "  " << transactions.size()
             << " transactions loaded." << endl;
    }

    // returns full transactions vector - used by ReportEngine and Notification
    vector<Transaction> getTransactions() {
        return transactions;
    }

    // returns full budgets vector - used by Notification
    vector<Budget> getBudgets() {
        return budgets;
    }
};