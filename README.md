# 💰 PERSONAL FINANCE TRACKER

```
╔══════════════════════════════════════════════════════════════════════╗
║        C++ OOP GROUP PROJECT — 2nd Semester | Bioinformatics         ║
╚══════════════════════════════════════════════════════════════════════╝
```

A menu-driven Personal Finance Tracker built in **C++ using OOP concepts**.
Track income, expenses, savings, budgets, and student allowance — all in one system.

---

# 👥 TEAM MEMBERS

```
┌───────────────┬──────────────────────────────┬──────────────────────────────┐
│ Name          │ Role                         │ Files                        │
├───────────────┼──────────────────────────────┼──────────────────────────────┤
│ Satvik Parv   │ Project Leader               │ Account.h                    │
│               │ Storage & File Handling      │ SavingsAccount.h             │
│               │                              │ Notification.h               │
├───────────────┼──────────────────────────────┼──────────────────────────────┤
│ Rishav Raj    │ Reports & Main Menu          │ ReportEngine.h               │
│               │                              │ StudentProfile.h             │
│               │                              │ main.cpp                     │
├───────────────┼──────────────────────────────┼──────────────────────────────┤
│ Anvi Mahajan  │ Core OOP Classes             │ Transaction.h                │
│               │                              │ User.h                       │
│               │                              │ Budget.h                     │
└───────────────┴──────────────────────────────┴──────────────────────────────┘
```

---

# 📁 PROJECT STRUCTURE

```
PersonalFinanceTracker/
│
├── Transaction.h      → Core data unit
├── User.h             → User profile class
├── Budget.h           → Spending limits + alerts
│
├── Account.h          → Balance + file storage
├── SavingsAccount.h   → Savings with interest
├── Notification.h     → Smart alerts system
│
├── ReportEngine.h     → Financial reports
├── StudentProfile.h   → Student allowance tracker
├── main.cpp           → Main menu
│
├── README.md
├── .gitignore
└── data.txt           → Auto-generated data file
```

---

# 🧱 CLASSES OVERVIEW

```
┌────────────────────┬───────────────┬──────────────────────────────────────────────┐
│ Class              │ Owner         │ Description                                  │
├────────────────────┼───────────────┼──────────────────────────────────────────────┤
│ Transaction        │ Anvi          │ Stores one income/expense (6 fields)         │
│ User               │ Anvi          │ Name, email, age profile                     │
│ Budget             │ Anvi          │ Category limits + overspend alerts           │
│ Account            │ Satvik        │ Manages transactions + file handling         │
│ SavingsAccount     │ Satvik        │ Savings + interest + goal tracking           │
│ Notification       │ Satvik        │ Smart financial alerts (8 checks)            │
│ ReportEngine       │ Rishav        │ Generates full financial report              │
│ StudentProfile     │ Rishav        │ Allowance split (50/30/20 rule)              │
│ main()             │ Rishav        │ Menu system                                  │
└────────────────────┴───────────────┴──────────────────────────────────────────────┘
```

---

# 🔗 CLASS RELATIONSHIPS

```
User
  │
  └───► StudentProfile
         (inherits name, email, age)
         + adds allowance system (50/30/20)
         + overrides showProfile()  → polymorphism

Account
  │
  └───► SavingsAccount
         (inherits transactions + balance)
         + adds savings goal & interest
```

---

# 💡 FEATURES

## 🔹 Transactions

* Add income & expenses (category, amount, date, description)
* View all transactions with balance summary
* Auto-save to `data.txt`
* Auto-load previous data

## 🔹 Budget Management

* Set category spending limits
* Instant overspend warnings
* View all budgets together

## 🔹 Savings Account

* Separate savings pot
* Set savings goal
* Deposit & withdraw
* Interest formula: **P × R × T / 100**

## 🔹 Smart Notifications

* 8 financial health checks
* Alerts for:

  * Low balance
  * Budget exceeded
  * Negative balance
* Suggestions if no budget/savings goal

## 🔹 Financial Reports

* Income vs expense summary
* Category-wise breakdown
* Savings rate calculation
* Personalized advice

## 🔹 Student Profile

* Monthly allowance split:

  * 50% Needs
  * 30% Wants
  * 20% Savings
* Needs/Wants spending control
* Savings locked
* Monthly reset system

---

# ⚙️ HOW TO RUN

```
Step 1: Clone
git clone https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-

Step 2: Open in VS Code

Step 3: Compile
g++ main.cpp -o finance

Step 4: Run
./finance
```

---

# 🛠️ OOP CONCEPTS USED

```
✔ Classes & Objects        → All files
✔ Constructors             → All classes
✔ Encapsulation            → Private data + getters/setters
✔ Inheritance              → SavingsAccount, StudentProfile
✔ Polymorphism             → showProfile() override
✔ Operator Overloading     → Transaction comparison
✔ Exception Handling       → Budget overspend
✔ File Handling            → fstream in Account
✔ Vectors                  → Transaction storage
```

---

# 🛠️ BUILT WITH

```
Language  : C++
Concepts  : OOP, File Handling, Inheritance, Polymorphism
Tools     : VS Code, Git, GitHub
Compiler  : g++ (MinGW)
```

---

# 🔗 REPOSITORY

👉 [https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-](https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-)

---

```
╔══════════════════════════════════════════════════════════════════════╗
║        Clean Code. Smart Finance. Student Friendly System.           ║
╚══════════════════════════════════════════════════════════════════════╝
```
