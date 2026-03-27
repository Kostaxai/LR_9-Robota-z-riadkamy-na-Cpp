#include <iostream>
#include <windows.h>  // Для SetConsoleCP та SetConsoleOutputCP
#include "task1.h"
#include "task2.h"

using namespace std;

int main() {
    // Встановлюємо кодування UTF-8 для консолі
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Виконати Завдання 1\n";
        cout << "2. Виконати Завдання 2\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1(); // викликаємо функцію Завдання 1
            break;
        case 2:
            task2(); // викликаємо функцію Завдання 2
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
