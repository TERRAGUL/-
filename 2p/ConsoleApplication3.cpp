#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int chislo, chislo2, operacia, OTVET;

    std::cout << "Крч, это лучший калькулятор, который вы видели в своей жизни :)\n";

    while (true) {
        std::cout << "1.Сложение\n2.Вычитание\n3.Частное\n4.Произведение\n5.Возведение в степень\n6.Нахождения квадратного корня\n7.Нахождение 1 процента от числа\n8.Найти факториал числа\n9.Выйти из программы.\n";
        std::cout << "Введите операцию пж:\n";
        std::cin >> operacia;

        if (operacia == 9) {
            exit(0);
        }

        std::cout << "Мне нужно твое первое число:\n";
        std::cin >> chislo;

        if (operacia != 6 && operacia != 7 && operacia != 8) {
            std::cout << "БЫСТРЕЕ ВТОРОЕ ЧИСЛО:\n";
            std::cin >> chislo2;
        }

        std::cout << "Вот твоя результата:\n";

        if (operacia == 1)
        {
            std::cout << chislo + chislo2;
        }
        else if (operacia == 2)
        {
            std::cout << chislo - chislo2;
        }
        else if (operacia == 3)
        {
            std::cout << chislo / chislo2;
        }
        else if (operacia == 4)
        {
            std::cout << chislo * chislo2;
        }
        else if (operacia == 5)
        {
            std::cout << pow(chislo, chislo2);
        }
        else if (operacia == 6)
        {
            std::cout << sqrt(chislo);
        }
        else if (operacia == 7)
        {
            std::cout << chislo / 100;
        }
        else if (operacia == 8)
        {
            OTVET = 1;
            int i;

            for (i = 1; i <= chislo; i++)
            {
                OTVET *= i;
            }

            std::cout << OTVET;
        }

        std::cout << "\n";
    }
}

