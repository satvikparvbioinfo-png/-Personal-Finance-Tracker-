// ─────────────────────────────────────────
// File    : ReportEngine.h
// Author  : Rishav Raj
// Purpose : Generates a full financial report
//           with category wise breakdown and
//           savings advice based on spending
// ─────────────────────────────────────────

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

class ReportEngine {

public:

    // constructor and destructor - nothing needed here
    ReportEngine() {}
    ~ReportEngine() {}

    // main function that produces the full financial report
    // takes Account by reference so it can access all the data
    void generateReport(Account& acc) {

        // cant generate a report if there are no transactions
        if (acc.getTransactions().size() == 0) {
            cout << "\n  No transactions found to generate report." << endl;
            return;
        }

        cout << "\n  ==============================" << endl;
        cout << "      FULL FINANCIAL REPORT"      << endl;
        cout << "  ==============================" << endl;

        // overall summary at the top
        cout << "\n  SUMMARY" << endl;
        cout << "  Total Income  : Rs. " << acc.getTotalIncome()  << endl;
        cout << "  Total Expense : Rs. " << acc.getTotalExpense() << endl;
        cout << "  Balance       : Rs. " << acc.getBalance()      << endl;

        // savings rate as a percentage of income
        if (acc.getTotalIncome() > 0) {
            float savingsRate = (acc.getBalance() / acc.getTotalIncome()) * 100;
            cout << "  Savings Rate  : " << savingsRate << "%" << endl;
        }

        cout << "\n  ==============================" << endl;

        // category wise expense breakdown
        categoryBreakdown(acc);

        cout << "\n  ==============================" << endl;

        // savings advice based on current spending patterns
        savingsAdvice(acc);

        cout << "  ==============================" << endl;
    }

    // shows how much was spent in each unique category
    void categoryBreakdown(Account& acc) {
        vector<Transaction> trans = acc.getTransactions();

        cout << "\n  EXPENSE BREAKDOWN BY CATEGORY" << endl;

        // collecting unique categories manually using two parallel vectors
        vector<string> categories;
        vector<float>  amounts;

        for (int i = 0; i < trans.size(); i++) {

            // only looking at expenses here
            if (!trans[i].isExpense()) continue;

            string cat = trans[i].getCategory();
            bool found = false;

            // check if this category already exists in our list
            for (int j = 0; j < categories.size(); j++) {
                if (categories[j] == cat) {
                    amounts[j] = amounts[j] + trans[i].getAmount();
                    found = true;
                    break;
                }
            }

            // if not found yet, add it as a new entry
            if (!found) {
                categories.push_back(cat);
                amounts.push_back(trans[i].getAmount());
            }
        }

        if (categories.size() == 0) {
            cout << "  No expenses recorded yet." << endl;
            return;
        }

        // print each category with its total
        for (int i = 0; i < categories.size(); i++) {
            cout << "  " << categories[i]
                 << " : Rs. " << amounts[i] << endl;
        }
    }

    // gives simple advice based on how much the user is saving
    void savingsAdvice(Account& acc) {
        cout << "\n  SAVINGS ADVICE" << endl;

        // cant give advice without any income data
        if (acc.getTotalIncome() == 0) {
            cout << "  Add income transactions to get advice." << endl;
            return;
        }

        // what percentage of income is actually being saved
        float savingsRate = (acc.getBalance() / acc.getTotalIncome()) * 100;

        // advice changes depending on how well they're doing
        if (savingsRate >= 20) {
            cout << "  Great job! You are saving " << savingsRate
                 << "% of your income." << endl;
            cout << "  Keep it up and you will reach your goals soon!" << endl;
        }
        else if (savingsRate >= 10) {
            cout << "  You are saving " << savingsRate
                 << "% of your income." << endl;
            cout << "  Try to save at least 20% for better financial health." << endl;
        }
        else if (savingsRate >= 0) {
            cout << "  You are saving only " << savingsRate
                 << "% of your income." << endl;
            cout << "  Try to cut down on wants and save more each month." << endl;
        }
        else {
            cout << "  WARNING: You are spending more than you earn!" << endl;
            cout << "  Review your expenses immediately." << endl;
        }
    }
};