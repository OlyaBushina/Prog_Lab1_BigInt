// Lab1_Demo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include "BigInt.h" 

BigInt factorial(int n) {
    BigInt res(1);
    for (int i = 2; i <= n; ++i) {
        res = res * BigInt(i);
    }
    return res;
}

void printMenu() {
    std::cout << "\n----- МЕНЮ ЛАБОРАТОРНОЇ РОБОТИ -----\n";
    std::cout << "1. Створити нове велике число (у довільній кількості)\n";
    std::cout << "2. Візуалізувати (вивести) всі створені числа\n";
    std::cout << "3. Зберегти останнє створене число на диск (у файл)\n";
    std::cout << "4. Відновити число з диска (з файлу)\n";
    std::cout << "5. Виконати операцію: Додати два останні числа\n";
    std::cout << "6. Виконати операцію: Перемножити два останні числа\n";
    std::cout << "7. Демонстрація 'Розумного доступу' (->) та 'Псевдозмінної'\n";
    std::cout << "8. Розв'язати типову задачу (Обчислити великий факторіал n!)\n";
    std::cout << "0. Вихід\n";
    std::cout << "Ваш вибір: ";
}

int main() {
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "uk_UA.1251");

    std::vector<BigInt> myNumbers; 
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            std::string s;
            std::cout << "Введіть велике число: ";
            std::cin >> s;
            myNumbers.push_back(BigInt(s));
            std::cout << "Число успішно додано до сховища!\n";
            break;
        }
        case 2: {
            if (myNumbers.empty()) {
                std::cout << "Сховище порожнє.\n";
            }
            else {
                std::cout << "Список чисел у сховищі:\n";
                for (size_t i = 0; i < myNumbers.size(); ++i) {
                    std::cout << "Число [" << i << "]: " << myNumbers[i] << "\n";
                }
            }
            break;
        }
        case 3: {
            if (myNumbers.empty()) {
                std::cout << "Немає чисел для збереження!\n";
            }
            else {
                myNumbers.back().saveToFile("number.txt");
                std::cout << "Останнє число збережено у файл 'number.txt'\n";
            }
            break;
        }
        case 4: {
            BigInt temp;
            temp.loadFromFile("number.txt");
            myNumbers.push_back(temp);
            std::cout << "Число завантажено з файлу і додано до сховища: " << temp << "\n";
            break;
        }
        case 5: {
            if (myNumbers.size() < 2) {
                std::cout << "Для операції потрібно мінімум 2 числа у сховищі!\n";
            }
            else {
                BigInt sum = myNumbers[myNumbers.size() - 1] + myNumbers[myNumbers.size() - 2];
                std::cout << "Результат додавання двох останніх чисел: " << sum << "\n";
            }
            break;
        }
        case 6: {
            if (myNumbers.size() < 2) {
                std::cout << "Для операції потрібно мінімум 2 числа у сховищі!\n";
            }
            else {
                BigInt product = myNumbers[myNumbers.size() - 1] * myNumbers[myNumbers.size() - 2];
                std::cout << "Результат множення двох останніх чисел: " << product << "\n";
            }
            break;
        }
        case 7: {
            if (myNumbers.empty()) {
                std::cout << "Спочатку додайте хоча б одне число (Пункт 1).\n";
                break;
            }
            std::cout << "Початкове число: " << myNumbers[0] << "\n";

            std::cout << "1. Виклик методу через оператор (->): ";
            myNumbers[0]->print();
            std::cout << "\n";

            
            std::cout << "2. Змінюємо першу цифру числа на 7 за допомогою конструкції виду num(0) = 7...\n";
            myNumbers[0](0) = 7;
            std::cout << "Нове значення числа: " << myNumbers[0] << "\n";
            break;
        }
        case 8: {
            int n;
            std::cout << "Введіть число n для обчислення факторіалу (наприклад, 50): ";
            std::cin >> n;
            if (n < 0) {
                std::cout << "Помилка! Число має бути додатним.\n";
            }
            else {
                std::cout << n << "! = " << factorial(n) << "\n";
            }
            break;
        }
        default:
            std::cout << "Неправильний пункт меню!\n";
        }
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
