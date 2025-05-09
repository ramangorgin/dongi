# 🧮 Dongi - Group Expense Splitter in C++

Dongi is a C++ console application that helps groups fairly split shared expenses and settle debts with the minimum number of transactions.

Whether you're going out with friends, sharing rent, or splitting bills, Dongi calculates each person's balance and generates a simple, optimized list of who owes whom.

---

## 🚀 Features

- Add participants to the group
- Record expenses: who paid, how much, and for whom
- Automatically calculate:
  - Total paid per person
  - Actual share per person
  - Final net balance (debt or credit)
- **Smart debt settlement**: minimizes the number of money transfers between members

---

## 🛠 Technologies

- C++17
- Standard Library (no external dependencies)
- Designed to be cross-platform (tested on Linux)

---

## 📦 Usage

### Compile:

```bash
g++ -o dengi main.cpp Person.cpp Expense.cpp ExpenseManager.cpp
```

## 📸Example:

```
Enter number of people: 3
Enter name of person #1: Ali
Enter name of person #2: Sara
Enter name of person #3: Reza

Enter number of expenses: 2

--- Expense 1 ---
Payer: Ali
Amount: 90
Number of participants: 3
Participant 1: Ali
Participant 2: Sara
Participant 3: Reza

--- Expense 2 ---
Payer: Sara
Amount: 60
Number of participants: 2
Participant 1: Sara
Participant 2: Reza

--- Final Balances ---
Ali → Creditor: 15.00
Sara → Debtor: 10.00
Reza → Debtor: 5.00

--- Simplified Transactions ---
Sara should pay 10 to Ali
Reza should pay 5 to Ali
```
## 📁Structure:
```
.
├── main.cpp
├── Person.h / Person.cpp
├── Expense.h / Expense.cpp
├── ExpenseManager.h / ExpenseManager.cpp
└── README.md
```

## 📜 License
This project is open source

Made with ❤️ by Raman Gorgin Paveh
