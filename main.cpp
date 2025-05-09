#include <iostream>
#include <vector>
#include <string>
#include "ExpenseManager.h"

using namespace std;

int main() {
    ExpenseManager manager;

    int numPeople;
    cout << "تعداد افراد را وارد کنید: ";
    cin >> numPeople;

    cin.ignore(); // حذف newline بعد از عدد

    // گرفتن نام افراد
    for (int i = 0; i < numPeople; ++i) {
        string name;
        cout << "نام فرد شماره " << i + 1 << ": ";
        getline(cin, name);
        manager.addPerson(name);
    }

    // گرفتن هزینه‌ها
    int numExpenses;
    cout << "\nتعداد پرداخت‌ها را وارد کنید: ";
    cin >> numExpenses;
    cin.ignore();

    for (int i = 0; i < numExpenses; ++i) {
        string payerName;
        double amount;
        int numParticipants;

        cout << "\n--- پرداخت " << i + 1 << " ---" << endl;

        cout << "نام پرداخت‌کننده: ";
        getline(cin, payerName);

        cout << "مقدار مبلغ پرداختی: ";
        cin >> amount;

        cout << "تعداد افراد شرکت‌کننده در این پرداخت: ";
        cin >> numParticipants;
        cin.ignore();

        vector<string> participants;

        for (int j = 0; j < numParticipants; ++j) {
            string participant;
            cout << "نام فرد " << j + 1 << ": ";
            getline(cin, participant);
            participants.push_back(participant);
        }

        manager.addExpense(payerName, amount, participants);
    }

    // چاپ وضعیت مالی نهایی
    cout << "\n--- وضعیت مالی افراد ---" << endl;
    manager.printBalances();

    // چاپ تسویه
    cout << "\n--- تسویه بدهی‌ها با کمترین تراکنش ---" << endl;
    manager.settleDebts();

    return 0;
}
