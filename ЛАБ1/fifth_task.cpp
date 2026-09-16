#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#define N 6

struct Student {
    std::string famil;
    std::string name;
    std::string facult;
    int kurs;
    double ball;
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    Student gruppa[N] = {
        {"Ильин","Кирилл","ФВТ",1,4.2},
        {"Романов","Артём","ФМТ",2,3.7},
        {"Гусева","Алина","ФВТ",1,4.9},
        {"Лапшин","Никита","ФЭ",3,3.1},
        {"Морозов","Артём","ФВТ",2,4.5},
        {"Титова","Вера","ФМТ",4,5.0}
    };

    int punkt;
    std::cout << "Искать по:\n";
    std::cout << "1 - фамилии\n";
    std::cout << "2 - имени\n";
    std::cout << "3 - факультету\n";
    std::cout << "4 - курсу\n";
    std::cout << "5 - среднему баллу\n";
    std::cout << "Пункт: ";
    std::cin >> punkt;

    if (punkt < 1 || punkt > 5) {
        std::cout << "Такого пункта нет\n";
        return 0;
    }

    std::string slovo;
    int kurs = 0;
    double ball = 0;

    if (punkt <= 3) {
        std::cout << "Значение: ";
        std::cin >> slovo;
    } else if (punkt == 4) {
        std::cout << "Курс: ";
        std::cin >> kurs;
    } else {
        std::cout << "Балл: ";
        std::cin >> ball;
    }

    int kolvo = 0;
    for (int i = 0; i < N; i++) {
        bool est = false;
        switch (punkt) {
            case 1: est = (gruppa[i].famil == slovo); break;
            case 2: est = (gruppa[i].name == slovo); break;
            case 3: est = (gruppa[i].facult == slovo); break;
            case 4: est = (gruppa[i].kurs == kurs); break;
            case 5: est = (gruppa[i].ball == ball); break;
        }

        if (est) {
            std::cout << gruppa[i].famil << " " << gruppa[i].name
                      << ", факультет " << gruppa[i].facult
                      << ", курс " << gruppa[i].kurs
                      << ", балл " << gruppa[i].ball << "\n";
            kolvo++;
        }
    }

    if (kolvo == 0) std::cout << "Совпадений нет\n";
    else std::cout << "Найдено: " << kolvo << "\n";
}
