#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    double paid;
    double share;

public:
    Person(const std::string& name);

    double getShare() const;
    void addPayment(double amount);
    void setShare(double amount);
    double getNetBalance() const;
    std::string getName() const;
};

#endif // PERSON_H
