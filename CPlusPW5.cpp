#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initBalance) : accountNumber(accNumber), balance(initBalance), interestRate(0) {}

    void deposit(double amount) {
        if (amount < 0) {
            throw invalid_argument("Сумма должна быть неотрицательной");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            cout << "Вывеленно: " << amount << endl;
        }
        else {
            cout << "Неверная сумма вывода или недостаточный баланс" << endl;
        }
    }

    double getBalance() const {
        return this->balance;
    }

    double getInterest() const {
        return (this->balance * this->interestRate * (1.0 / 12));
    }

    void setInterestRate(double newRate) {
        this->interestRate = newRate;
    }

    int getAccountNumber() const {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount <= 0) {
        cout << "Сумма перевода должна быть положительной" << endl;
        return false;
    }

    if (from.getBalance() >= amount) {
        from.withdraw(amount);
        to.deposit(amount);
        cout << "Перевод успешно выполнен" << endl;
        return true;
    }
    else {
        cout << "Недостаточно средств для перевода" << endl;
        return false;
    }
}

int main() {

    setlocale(0, "");

    double fromAccountBalance, toAccountBalance, amount;

    cout << "Введите баланс счета отправителя: ";
    while (!(cin >> fromAccountBalance)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Пожалуйста, введите число: ";
    }

    cout << "Введите баланс счета получателя: ";
    while (!(cin >> toAccountBalance)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Пожалуйста, введите число: ";
    }

    cout << "Введите сумму для перевода: ";
    while (!(cin >> amount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Пожалуйста, введите число: ";
    }

    BankAccount from(12345, fromAccountBalance);
    BankAccount to(54321, toAccountBalance);

    cout << "Баланс до перевода:" << endl;
    cout << "Счёт отправителя:" << from.getBalance() << endl;
    cout << "Счёт получателя:" << to.getBalance() << endl;

    cout << "Пытаемся перевести " << amount << " руб. со счета " << from.getAccountNumber() << " на счет " << to.getAccountNumber() << endl;
    transfer(from, to, amount);

    cout << "Баланс после перевода:" << endl;
    cout << "Счет отправителя: " << from.getBalance() << endl;
    cout << "Счет получателя: " << to.getBalance() << endl;

    return 0;
}// +1 балл