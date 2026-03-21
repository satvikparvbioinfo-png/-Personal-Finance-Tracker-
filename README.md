# 💰 Personal Finance Tracker

**C++ OOP Group Project — 2nd Semester**

A menu-driven Personal Finance Tracker built in C++ using Object Oriented Programming concepts. Allows users to track income and expenses, generate reports, set budgets and track savings goals.

---

## 👥 Team Members

| Name | Role | Files |
|------|------|-------|
| Satvik Parv | Project Leader · Storage & File Handling | Account.h, SavingsAccount.h, Notification.h |
| Rishav Raj | Reports & Main Menu | ReportEngine.h, StudentProfile.h, main.cpp |
| Anvi Mahajan | Core OOP Classes | Transaction.h, User.h, Budget.h |

---

## 📁 Project Structure
```
PersonalFinanceTracker/
├── Transaction.h       → Core data unit — Anvi Mahajan
├── User.h              → User profile class — Anvi Mahajan
├── Budget.h            → Spending limits + alerts — Anvi Mahajan
├── Account.h           → Balance + file storage — Satvik Parv
├── SavingsAccount.h    → Savings with interest — Satvik Parv
├── Notification.h      → Smart alerts system — Satvik Parv
├── ReportEngine.h      → Financial reports — Rishav Raj
├── StudentProfile.h    → Student finance tips — Rishav Raj
├── main.cpp            → Main menu — Rishav Raj
├── README.md           → Project documentation
├── .gitignore          → Git ignore rules
└── data.txt            → Auto-generated when data is saved
```

---

## 🧱 Classes Used

| Class | Owner | Description |
|-------|-------|-------------|
| `Transaction` | Anvi Mahajan | Blueprint for one income or expense record with 5 fields |
| `User` | Anvi Mahajan | Stores name and email with profile display |
| `Budget` | Anvi Mahajan | Set spending limit per category with overspend warnings |
| `Account` | Satvik Parv | Manages all transactions in a vector and tracks balance |
| `SavingsAccount` | Satvik Parv | Separate savings pot with simple interest calculation |
| `Notification` | Satvik Parv | Checks 8 financial conditions and shows alerts on startup |
| `ReportEngine` | Rishav Raj | Full financial report with category breakdown and savings advice |
| `StudentProfile` | Rishav Raj | Student finance tracking with monthly allowance split tips |
| `main()` | Rishav Raj | Menu system that connects all 9 classes together |

---

## ⚙️ How to Run

**Step 1 — Clone the project:**
```
git clone https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-
```

**Step 2 — Open the folder in VS Code**

**Step 3 — Open terminal and compile:**
```
g++ main.cpp -o finance
```

**Step 4 — Run the program:**
```
.\finance
```

---

## 💡 Features

- Add income and expense transactions
- View all transactions with full details
- Save data permanently to file (data.txt)
- Load previous data when program starts
- Generate full financial report
- Category-wise spending breakdown
- Set budget limits with overspending alerts
- Track savings goals with progress percentage
- Separate savings account with interest calculator
- Smart notifications checking financial health on startup
- Student profile with personalized monthly budget tips
- Smart savings advice based on your spending rate

---

## 🛠️ Built With

- Language: C++
- Concepts: OOP, Classes, Vectors, File Handling
- Tools: VS Code, Git, GitHub
- Compiler: g++ (MinGW)

---

## 🔗 Repository

https://github.com/satvikparvbioinfo-png/-Personal-Finance-Tracker-
