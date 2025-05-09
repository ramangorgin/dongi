#include <iostream>
#include <vector>
#include <string>
#include "ExpenseManager.h"

using namespace std;

int main() {
    ExpenseManager manager;

    int numPeople;
    cout << "Enter the number of people: ";
    cin >> numPeople;
    cin.ignore(); 

    // گرفتن نام افراد
    for (int i = 0; i < numPeople; ++i) {
        string name;
        cout << "\nName of person " << i + 1 << ": ";
        getline(cin, name);
        manager.addPerson(name);
    }

    // گرفتن هزینه‌ها
    int numExpenses;
    cout << "\nEnter the number of payments: ";
    cin >> numExpenses;
    cin.ignore();

    for (int i = 0; i < numExpenses; ++i) {
        string payerName;
        double amount;
        int numParticipants;

        cout << "\n--- payment " << i + 1 << " ---" << endl;

        cout << "\nName of Payer: ";
        getline(cin, payerName);

        cout << "\nAmount of Payment: ";
        cin >> amount;

        cout << "\nNumber of Participants: ";
        cin >> numParticipants;
        cin.ignore();

        vector<string> participants;

        for (int j = 0; j < numParticipants; ++j) {
            string participant;
            cout << "Name of Person" << j + 1 << ": ";
            getline(cin, participant);
            participants.push_back(participant);
        }

        manager.addExpense(payerName, amount, participants);
    }

    // چاپ وضعیت مالی نهایی
    cout << "\n--- Financial Situation ---" << endl;
    manager.printBalances();

    // چاپ تسویه
    cout << "\n--- Debt Settlement ---" << endl;
    manager.settleDebts();

    return 0;
}
