#include <iostream>
#include <string>
using namespace std;

// Функція авторської заміни символів у масиві
void replace_char_array(char str[], size_t size, size_t pos, size_t len, const char s[]) {
    // Поточна довжина рядка
    size_t str_len = 0;
    while (str[str_len] != '\0') str_len++;

    // Довжина нового рядка
    size_t s_len = 0;
    while (s[s_len] != '\0') s_len++;

    // Перевірка позиції
    if (pos > str_len) {
        cout << "Помилка: позиція заміни більша за довжину рядка!" << endl;
        return;
    }

    // Якщо довжина заміни виходить за межі рядка
    if (pos + len > str_len) len = str_len - pos;

    // Перевірка, чи вистачає місця в масиві
    if (str_len - len + s_len >= size) {
        cout << "Помилка: новий рядок занадто довгий для масиву!" << endl;
        return;
    }

    // Зсув символів
    if (s_len != len) {
        if (s_len > len) {
            for (size_t i = str_len; i >= pos + len; i--)
                str[i + s_len - len] = str[i];
        }
        else {
            for (size_t i = pos + len; i <= str_len; i++)
                str[i - (len - s_len)] = str[i];
        }
    }

    // Копіюємо новий рядок
    for (size_t i = 0; i < s_len; i++)
        str[pos + i] = s[i];
}

// Функція для завдання 1
void task1() {
    const size_t SIZE = 100;
    char char_array[SIZE];
    string str;

    cout << "--- Завдання 1 ---" << endl;
    cin.ignore(); // очищаємо буфер перед getline
    cout << "Введіть рядок: ";
    cin.getline(char_array, SIZE);
    str = char_array;

    size_t pos, len;
    char s[50];
    cout << "Введіть позицію заміни: ";
    cin >> pos;
    cout << "Введіть довжину заміни: ";
    cin >> len;
    cin.ignore();
    cout << "Введіть новий рядок: ";
    cin.getline(s, 50);

    // Копія масиву
    char char_array_copy[SIZE];
    for (size_t i = 0; i < SIZE; i++) char_array_copy[i] = char_array[i];

    replace_char_array(char_array_copy, SIZE, pos, len, s);

    // Використання стандартного string
    string str_copy = str;
    if (pos <= str_copy.size()) {
        if (pos + len > str_copy.size()) len = str_copy.size() - pos;
        str_copy.replace(pos, len, s);
    }

    cout << "Результат для масиву символів: " << char_array_copy << endl;
    cout << "Результат для string: " << str_copy << endl;
}
