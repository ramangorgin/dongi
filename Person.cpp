#include "Person.h"

Person::Person(const std::string& name) : name(name), paid(0.0), share(0.0) {}

void Person::addPayment(double amount) {
    paid += amount;
}

void Person::setShare(double amount) {
    share = amount;
}

double Person::getNetBalance() const {
    return paid - share;
}

double Person::getShare() const {
    return share;
}


std::string Person::getName() const {
    return name;
}
