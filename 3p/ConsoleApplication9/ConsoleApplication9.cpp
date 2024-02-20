#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "RUS");

    int dvuMerniyMassiv[2][4];
    int otvetik = 0;

    cout << "Введите числа в эту строчечку :3:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> dvuMerniyMassiv[0][i];
    }

    cout << "Введите числа теперь в эту строчечку :):\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> dvuMerniyMassiv[1][i];
    }

    cout << "Введите числа теперь в эту супер строчечку :) \n";

    for (int i = 0; i < 5; i++)
    {
        cin >> dvuMerniyMassiv[2][i];
    }

    for (int i = 0; i < 5; i++)
    {
        otvetik += dvuMerniyMassiv[0][i];
    }

    cout << "Промежуточное значение первой строки балин:" << otvetik / 5;
    otvetik = 0;
    for (int i = 0; i < 5; i++)
    {
        otvetik += dvuMerniyMassiv[1][i];
    }

    cout << "\nСреднее значение второй этой строки:" << otvetik / 5;
    otvetik = 0;
    for (int i = 0; i < 5; i++)
    {
        otvetik += dvuMerniyMassiv[2][i];
    }

    cout << "\nТеперь значение третьей среднее:" << otvetik / 5;

    return 0;
}
