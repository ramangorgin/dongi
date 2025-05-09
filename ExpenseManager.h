#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <string>
#include "Person.h"
#include "Expense.h"

class ExpenseManager {
private:
    std::vector<Person*> people;      // لیست اشاره‌گر به اشخاص
    std::vector<Expense*> expenses;   // لیست تراکنش‌ها (اشاره‌گر به Expense)

public:
    ~ExpenseManager();                // دِستروکتور برای پاک‌سازی حافظه

    void addPerson(const std::string& name);                        // اضافه کردن شخص جدید
    Person* getPersonByName(const std::string& name);              // پیدا کردن شخص بر اساس نام
    void addExpense(const std::string& payerName, double amount, const std::vector<std::string>& participantNames); // ساخت تراکنش جدید

    void settleDebts();      // تسویه هوشمند بدهی‌ها
    void printBalances();    // نمایش نهایی بدهی یا طلب هر فرد
};

#endif // EXPENSEMANAGER_H
