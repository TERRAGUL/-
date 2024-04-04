#include <iostream>
#include <stdexcept> // Для std::invalid_argument
#include <cmath>     // Для std::abs

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double initialBalance, double interestRate)
        : accountNumber(accountNumber), balance(initialBalance), interestRate(interestRate) {
        if (initialBalance < 0 || interestRate < 0) {
            throw std::invalid_argument("Начальный баланс и процентная ставка должны быть неотрицательными");
        }
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Сумма вклада должна быть неотрицательной");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Сумма снятия должна быть неотрицательной");
        }
        if (amount > balance) {
            throw std::invalid_argument("Недостаточно средств");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double newInterestRate) {
        if (newInterestRate < 0) {
            throw std::invalid_argument("Процентная ставка должна быть неотрицательной");
        }
        interestRate = newInterestRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Сумма перевода должна быть неотрицательной");
    }
    if (amount > from.balance) {
        return false;
    }
    from.balance -= amount;
    to.balance += amount;
    return true;
}

int main() {
    setlocale(LC_ALL, "RUS");
    try {
        BankAccount account1(123456, 1000.0, 0.05);
        BankAccount account2(654321, 500.0, 0.03);

        std::cout << "Исходные балансы:" << std::endl;
        std::cout << "Счет 1: " << account1.getBalance() << std::endl;
        std::cout << "Счет 2: " << account2.getBalance() << std::endl;

        double depositAmount, withdrawAmount, transferAmount;
        std::cout << "Введите сумму вклада для счета 1: ";
        std::cin >> depositAmount;
        account1.deposit(depositAmount);

        std::cout << "Введите сумму снятия для счета 2: ";
        std::cin >> withdrawAmount;
        account2.withdraw(withdrawAmount);

        std::cout << "Введите сумму перевода со счета 1 на счет 2: ";
        std::cin >> transferAmount;
        if (transfer(account1, account2, transferAmount)) {
            std::cout << "Перевод на сумму " << transferAmount << " со счета 1 на счет 2 выполнен успешно." << std::endl;
        }
        else {
            std::cout << "Перевод на сумму " << transferAmount << " со счета 1 на счет 2 не удался из-за недостаточных средств." << std::endl;
        }

        std::cout << "Балансы после вклада, снятия и перевода:" << std::endl;
        std::cout << "Счет 1: " << account1.getBalance() << std::endl;
        std::cout << "Счет 2: " << account2.getBalance() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
