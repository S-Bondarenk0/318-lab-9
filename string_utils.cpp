#include "string_utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// Завдання 1 — реалізація string::append(n, c) вручну
void custom_append(char str[], size_t& len, size_t n, char c) {
    for (size_t i = 0; i < n; ++i) {
        str[len++] = c;
    }
    str[len] = '\0'; // завершити C-рядок
}

// Завдання 1
void task1() {
    std::string std_str;
    char c_str[200];
    size_t len = 0;

    std::cout << "Введіть рядок: ";
    std::getline(std::cin, std_str);
    std::strcpy(c_str, std_str.c_str());
    len = std_str.length();

    // Додати 5 символів '.'
    std_str.append(5, '.');
    custom_append(c_str, len, 5, '.');

    std::cout << "\nСтандартна реалізація string.append: " << std_str << "\n";
    std::cout << "Користувацька реалізація append:      " << c_str << "\n";
}

// Перевірка, чи рядок містить хоча б один символ С
bool contains_char(const std::string& line, char c) {
    return line.find(c) != std::string::npos;
}

// Подвоєння кожного входження символу C
std::string double_char(const std::string& line, char c) {
    std::string result;
    for (char ch : line) {
        result += ch;
        if (ch == c) result += c;
    }
    return result;
}

// Завдання 2
void task2() {
    std::ifstream infile("input_lines.txt");
    std::ofstream outfile("output_lines.txt");

    if (!infile || !outfile) {
        std::cerr << "Не вдалося відкрити файл!\n";
        return;
    }

    char target;
    std::cout << "Введіть символ, який слід подвоїти: ";
    std::cin >> target;

    std::string line;
    while (std::getline(infile, line)) {
        if (contains_char(line, target)) {
            std::string modified = double_char(line, target);
            outfile << modified << "\n";
        } else {
            outfile << line << "\n";
        }
    }

    std::cout << "Обробку завершено. Результат збережено у 'output_lines.txt'.\n";
}
