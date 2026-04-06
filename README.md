<<<<<<< HEAD
💰 Personal Finance Tracker
C++ OOP Group Project — 2nd Semester | B.Tech Bioinformatics
A menu-driven Personal Finance Tracker built in C++ using Object Oriented Programming concepts. Allows users to track income and expenses, generate financial reports, set budgets, manage savings goals and track monthly student allowance.

👥 Team Members
NameRoleFilesSatvik ParvProject Leader · Storage & File HandlingAccount.h, SavingsAccount.h, Notification.hRishav RajReports & Main MenuReportEngine.h, StudentProfile.h, main.cppAnvi MahajanCore OOP ClassesTransaction.h, User.h, Budget.h

📁 Project Structure
PersonalFinanceTracker/
├── Transaction.h       → Core data unit — Anvi Mahajan
├── User.h              → User profile class — Anvi Mahajan
├── Budget.h            → Spending limits + alerts — Anvi Mahajan
├── Account.h           → Balance + file storage — Satvik Parv
├── SavingsAccount.h    → Savings with interest — Satvik Parv
├── Notification.h      → Smart alerts system — Satvik Parv
├── ReportEngine.h      → Financial reports — Rishav Raj
├── StudentProfile.h    → Student allowance tracker — Rishav Raj
├── main.cpp            → Main menu — Rishav Raj
├── README.md           → Project documentation
├── .gitignore          → Git ignore rules
└── data.txt            → Auto generated when data is saved

🧱 Classes Used
ClassOwnerDescriptionTransactionAnvi MahajanBlueprint for one income or expense record with 6 fieldsUserAnvi MahajanStores name, email and age with profile displayBudgetAnvi MahajanSet spending limit per category with overspend warnings using exception handlingAccountSatvik ParvManages all transactions in a vector, tracks balance and handles file saving and loadingSavingsAccountSatvik ParvInherits from Account — separate savings pot with simple interest calculator and goal trackingNotificationSatvik ParvChecks 8 financial conditions on startup and shows smart alertsReportEngineRishav RajFull financial report with category breakdown and savings adviceStudentProfileRishav RajInherits from User — splits monthly allowance into Needs, Wants and Savings potsmain()Rishav RajMenu system that connects all 9 classes together using do-while and switch case

🔗 Class Relationships
User  <──────────────  StudentProfile
(parent)                (child — inherits name, email, age, setup(), showProfile())

Account  <───────────  SavingsAccount
(parent)                (child — inherits all transaction and balance functions)
StudentProfile extends User

Gets name, email, age automatically from User
Adds course, allowance and the 50/30/20 pot system on top
Overrides showProfile() to show allowance breakdown — this is polymorphism

SavingsAccount extends Account

Gets all transaction, balance and file handling from Account
Adds savings goal, deposit, withdraw and interest calculator on top


💡 Features
Transactions

Add income and expense transactions with category, amount, date and description
View all transactions with running balance summary
Data is saved permanently to data.txt
Previous data loads automatically when program starts

Budget Management

Set spending limits for any category
Instant warning when budget is exceeded
View status of all budgets at once

Savings Account

Separate savings pot independent of main account
Set a savings goal with a target amount
Deposit and withdraw from savings
Simple interest calculator using P x R x T / 100

Smart Notifications

8 automatic financial health checks on every startup
Alerts for low balance, exceeded budgets, negative balance
Tips if no budget or savings goal has been set

Financial Report

Full income and expense summary
Category wise expense breakdown
Savings rate calculation with personalised advice

Student Profile

Set monthly allowance and auto split using 50/30/20 rule
50% goes to Needs, 30% to Wants, 20% to Savings
Spend from Needs and Wants separately
Savings pot is locked and cannot be spent
Warning when Needs balance gets too low
Reset all pots at start of new month


⚙️ How to Run
Step 1 — Clone the project:
git clone https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-
Step 2 — Open the folder in VS Code
Step 3 — Open terminal and compile:
g++ main.cpp -o finance
Step 4 — Run the program:
.\finance

🛠️ OOP Concepts Used
ConceptWhere UsedClasses & ObjectsAll 9 filesConstructors & DestructorsAll 9 filesEncapsulationPrivate data with public getters and setters in every classInheritanceSavingsAccount extends Account, StudentProfile extends UserPolymorphismshowProfile() overridden in StudentProfileOperator Overloadingoperator > in Transaction to compare amountsException HandlingcheckBudget() in Budget throws and catches overspend errorFile HandlingsaveToFile() and loadFromFile() in Account using fstreamVectorsTransaction and Budget lists stored in vectors in Account

🛠️ Built With

Language — C++
Concepts — OOP, Classes, Vectors, File Handling, Inheritance, Polymorphism
Tools — VS Code, Git, GitHub
Compiler — g++ MinGW on Windows


🔗 Repository
https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-
=======

>>>>>>> 2a38b247aa3b46e4efb33a56f52498adb53b4385
