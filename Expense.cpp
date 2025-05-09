#include "Expense.h"

Expense::Expense(Person* payer, double amount, const std::vector<Person*>& participants)
    : payer(payer), amount(amount), participants(participants) {}

// اجرای تقسیم دنگ
void Expense::split() {
    if (participants.empty()) return;

    double sharePerPerson = amount / participants.size();

    // به هر نفر سهمش رو اضافه کن
    for (Person* p : participants) {
        p->setShare(p->getShare() + sharePerPerson);
    }

    // کل مبلغ رو به حساب پرداخت‌کننده اضافه کن
    payer->addPayment(amount);
}
