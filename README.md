# 💰 Personal Finance Tracker
### C++ OOP Group Project — 2nd Semester

A menu-driven Personal Finance Tracker built in C++ using
Object Oriented Programming concepts. Allows users to track
income and expenses, generate reports, set budgets and
track savings goals.

---

## 👥 Team Members

| Member | Name | Role | Files |
|--------|------|------|-------|
| Member 1 | (write your name) | Foundation — Input & Menu | Transaction.h, User.h, main.cpp |
| Member 2 | Satvik | Storage — File Handling | Account.h |
| Member 3 | (write their name) | Brain — Reports & Analysis | Budget.h, ReportEngine.h |

---

## 📁 Project Structure
```
PersonalFinanceTracker/
├── Transaction.h     → Stores one money record (Member 1)
├── User.h            → Stores user profile (Member 1)
├── Account.h         → Manages balance + file saving (Member 2)
├── Budget.h          → Spending limits + alerts (Member 3)
├── ReportEngine.h    → Reports + analysis (Member 3)
├── main.cpp          → Main menu connecting everything (Member 1)
└── data.txt          → Auto-generated when data is saved
```

---

## 🧱 Classes Used

- **Transaction** — Blueprint for one income/expense record
- **User** — Stores name and email of the person using the app
- **Account** — Manages all transactions, balance, save and load
- **Budget** — Set spending limit per category with warnings
- **ReportEngine** — Full financial report with savings advice

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
- Track savings goals with progress
- Smart savings advice based on your spending

---

## 🛠️ Built With

- Language: C++
- Concepts: OOP, Classes, Vectors, File Handling
- Tools: VS Code, Git, GitHub
- Compiler: g++ (MinGW)
