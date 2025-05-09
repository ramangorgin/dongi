#ifndef EXPENSE_H
#define EXPENSE_H

#include <vector>
#include "Person.h"

class Expense {
private:
    Person* payer;
    double amount;
    std::vector<Person*> participants;

public:
    Expense(Person* payer, double amount, const std::vector<Person*>& participants);
    void split();
};

#endif // EXPENSE_H
