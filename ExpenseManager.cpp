#include "ExpenseManager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// دِستروکتور → حافظه رو آزاد می‌کنه
ExpenseManager::~ExpenseManager() {
    for (Person* p : people) delete p;
    for (Expense* e : expenses) delete e;
}

// اضافه کردن یک شخص جدید
void ExpenseManager::addPerson(const string& name) {
    people.push_back(new Person(name));
}

// پیدا کردن اشاره‌گر به شخص با اسم خاص
Person* ExpenseManager::getPersonByName(const string& name) {
    for (Person* p : people) {
        if (p->getName() == name) return p;
    }
    return nullptr; // اگر پیدا نشد
}

// اضافه کردن یک تراکنش (Expense) جدید
void ExpenseManager::addExpense(const string& payerName, double amount, const vector<string>& participantNames) {
    Person* payer = getPersonByName(payerName);
    vector<Person*> participants;

    for (const string& name : participantNames) {
        Person* participant = getPersonByName(name);
        if (participant) participants.push_back(participant);
    }

    Expense* e = new Expense(payer, amount, participants);
    e->split();  // محاسبه دنگ‌ها
    expenses.push_back(e);
}

// نمایش وضعیت حساب هر شخص (طلبکار یا بدهکار)
void ExpenseManager::printBalances() {
    cout << fixed << setprecision(2);
    for (Person* p : people) {
        double balance = p->getNetBalance();
        cout << p->getName() << " → ";

        if (balance > 0)
            cout << " creditor: " << balance << endl;
        else if (balance < 0)
            cout << " debtor: " << -balance << endl;
        else
            cout << " debt-free: " << endl;
    }
}

// تسویه‌ی هوشمند بدهی‌ها
void ExpenseManager::settleDebts() {
    struct Balance {
        Person* person;
        double amount;
    };

    vector<Balance> debtors;
    vector<Balance> creditors;

    // جدا کردن طلبکارها و بدهکارها
    for (Person* p : people) {
        double bal = p->getNetBalance();
        if (bal < -0.01) debtors.push_back({p, -bal});    // بدهی‌ها مثبت می‌شن
        else if (bal > 0.01) creditors.push_back({p, bal});
    }

    // تسویه با کمترین تعداد تراکنش
    size_t i = 0, j = 0;
    while (i < debtors.size() && j < creditors.size()) {
        double amount = min(debtors[i].amount, creditors[j].amount);
        cout << debtors[i].person->getName() << " must pay " << amount
             << " to " << creditors[j].person->getName() << endl;

        debtors[i].amount -= amount;
        creditors[j].amount -= amount;

        if (debtors[i].amount < 0.01) i++;
        if (creditors[j].amount < 0.01) j++;
    }
}
