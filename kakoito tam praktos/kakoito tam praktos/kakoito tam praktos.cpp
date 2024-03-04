#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale> // Для использования setlocale
#include <cstring>

using namespace std;

// Функция для переворачивания строки задом наперед
string reverse(const string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string removeGlasniye(const string str) {
    string result;
    for (char ch : str) {
        if (!strchr("аеёиоуыэюяАЕЁИОУЫЭЮЯ", ch)) {
            result += ch;
        }
    }
    return result;
}

string removeSoglasniye(const string str) {
    string result;
    for (char ch : str) {
        if (!strchr("йцкнгшщзхфвпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖЧМТБ", ch)) {
            result += ch;
        }
    }
    return result;
}

string random(const string str) {
    string random = str;
    random_shuffle(random.begin(), random.end());
    return random;
}

int main() {
    setlocale(LC_ALL, "Russian"); // Установка русской локали

    cout << "Введите слово: ";
    string word;
    cin >> word;

    int choice;
    cout << "Выберите действие:\n";
    cout << "1. Вывести слово задом наперед\n";
    cout << "2. Вывести слово без гласных\n";
    cout << "3. Вывести слово без согласных\n";
    cout << "4. Рандомно раскидывать буквы заданного слова\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Результат: " << reverse(word) << endl;
        break;
    case 2:
        cout << "Результат: " << removeGlasniye(word) << endl;
        break;
    case 3:
        cout << "Результат: " << removeSoglasniye(word) << endl;
        break;
    case 4:
        cout << "Результат: " << random(word) << endl;
        break;
    default:
        cout << "Неверный выбор." << endl;
    }

    return 0;
}
