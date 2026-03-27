#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція перевірки: чи містить рядок символ C
bool check_string(const string& str, char C) {
    for (char ch : str)
        if (ch == C) return true;
    return false;
}

// Функція вставки S0 після кожного входження C
void insert_after_char(string& str, char C, const string& S0) {
    size_t pos = 0;
    while ((pos = str.find(C, pos)) != string::npos) {
        str.insert(pos + 1, S0);
        pos += 1 + S0.length(); // пересуваємо позицію після вставки
    }
}

// Функція Завдання 2
void task2() {
    char C;
    string S0;

    cout << "--- Завдання 2 ---" << endl;
    cout << "Введіть символ C: ";
    cin >> C;
    cin.ignore();
    cout << "Введіть рядок S0 для вставки: ";
    getline(cin, S0);

    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Не вдалося відкрити input.txt" << endl;
        return;
    }

    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cout << "Не вдалося відкрити output.txt" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (check_string(line, C)) {
            insert_after_char(line, C, S0);
        }
        fout << line << endl;
    }

    fin.close();
    fout.close();
    cout << "Обробка завершена. Результат збережено у output.txt" << endl;
}
