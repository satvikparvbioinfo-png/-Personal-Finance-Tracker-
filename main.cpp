// ─────────────────────────────────────────
// File    : main.cpp
// Author  : Rishav Raj
// Purpose : Main menu that connects all classes
//           and runs the finance tracker program
// ─────────────────────────────────────────

#include <iostream>
#include "User.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "Notification.h"
#include "ReportEngine.h"
#include "StudentProfile.h"
using namespace std;

int main() {

    // one object of each class
    Account        acc;   // manages all transactions
    SavingsAccount sav;   // manages savings goal
    Notification   notif; // handles smart alerts
    ReportEngine   rep;   // generates financial report
    StudentProfile stu;   // manages student allowance

    // load any previously saved transactions from file
    acc.loadFromFile();

    // run notifications on startup so user sees alerts right away
    notif.checkAll(acc, sav);
    notif.showNotifications();

    int choice; // stores whatever the user picks from the menu

    // main loop - keeps running until user chooses 0
    do {
        cout << "\n  ==============================" << endl;
        cout << "    PERSONAL FINANCE TRACKER"     << endl;
        cout << "  ==============================" << endl;
        cout << "  1.  Add Transaction"            << endl;
        cout << "  2.  View All Transactions"      << endl;
        cout << "  3.  Set Budget"                 << endl;
        cout << "  4.  Check Budgets"              << endl;
        cout << "  5.  View Financial Report"      << endl;
        cout << "  6.  Savings Account Setup"      << endl;
        cout << "  7.  Deposit to Savings"         << endl;
        cout << "  8.  Withdraw from Savings"      << endl;
        cout << "  9.  View Savings & Interest"    << endl;
        cout << "  10. Student Profile Setup"      << endl;
        cout << "  11. Spend from Needs"           << endl;
        cout << "  12. Spend from Wants"           << endl;
        cout << "  13. View Student Profile"       << endl;
        cout << "  14. Reset Monthly Allowance"    << endl;
        cout << "  15. Show Notifications"         << endl;
        cout << "  16. Save Data"                  << endl;
        cout << "  0.  Exit"                       << endl;
        cout << "  ==============================" << endl;
        cout << "  Enter choice : ";
        cin  >> choice;

        switch (choice) {

            case 1:
                // add a new income or expense transaction
                acc.addTransaction();
                break;

            case 2:
                // show all recorded transactions with balance summary
                acc.showAll();
                break;

            case 3:
                // set a spending limit for a category
                acc.setBudget();
                break;

            case 4:
                // check all budgets and see if any are exceeded
                acc.checkBudgets();
                break;

            case 5:
                // full financial report with category breakdown and advice
                rep.generateReport(acc);
                break;

            case 6:
                // set up savings goal and interest rate
                sav.setup();
                break;

            case 7:
                // add money to the savings pot
                sav.deposit();
                break;

            case 8:
                // take money out of savings
                sav.withdraw();
                break;

            case 9:
                // view savings balance and calculate interest
                sav.showBalance();
                sav.showInterest();
                break;

            case 10:
                // set up student profile with allowance split
                stu.setup();
                break;

            case 11:
                // spend from the Needs pot
                stu.spendFromNeeds();
                break;

            case 12:
                // spend from the Wants pot
                stu.spendFromWants();
                break;

            case 13:
                // view student profile with all pot balances
                stu.showProfile();
                break;

            case 14:
                // reset allowance pots for the new month
                stu.resetMonth();
                break;

            case 15:
                // re run all checks and show latest notifications
                notif.checkAll(acc, sav);
                notif.showNotifications();
                break;

            case 16:
                // save all transactions to data.txt
                acc.saveToFile();
                break;

            case 0:
                // auto save before exiting
                acc.saveToFile();
                cout << "\n  Thank you for using Personal Finance Tracker!"
                     << endl;
                break;

            default:
                // invalid input - ask again
                cout << "\n  Invalid choice. Please enter a valid option."
                     << endl;
        }

    } while (choice != 0);

    return 0;
}