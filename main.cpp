#include <iostream>
#include "string_utils.h"

int main() {
    int choice;

    do {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1. Завдання 1 (string::append)\n";
        std::cout << "2. Завдання 2 (Подвоєння символів у рядку)\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        std::cin.ignore(); // очистити буфер

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                std::cout << "Вихід з програми...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    return 0;
}
