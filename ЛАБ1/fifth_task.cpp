#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

// узел односвязного списка - хранит данные одного студента
// и указатель на следующий узел
struct Student {
    std::string famil;
    std::string name;
    std::string facult;
    int kurs;
    double ball;
    Student* next;
};

// убирает пробелы и служебные символы конца строки (\r, \n) по краям строки
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// читает целое число, пока пользователь не введёт корректное значение
int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод, нужно целое число. Повторите.\n";
            continue;
        }
        return value;
    }
}

// читает дробное число, пока пользователь не введёт корректное значение
double readDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод, нужно число. Повторите.\n";
            continue;
        }
        return value;
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    Student* head = nullptr;   // указатель на первый элемент списка
    Student* tail = nullptr;   // указатель на последний элемент (для быстрого добавления в конец)
    int kolvoStudentov = 0;    // счётчик введённых студентов - для контроля на экране

    std::cout << "Ввод студентов (для окончания ввода фамилии введите * и нажмите Enter)\n\n";

    while (true) {
        std::string famil;
        std::cout << "Фамилия: ";
        std::cin >> famil;
        famil = trim(famil);   // убираем случайные пробелы/спецсимволы

        if (famil == "*") {
            std::cout << "\n--- Ввод завершён. Всего студентов: " << kolvoStudentov << " ---\n\n";
            break;
        }

        // динамическое выделение памяти под один узел списка
        Student* node = new Student;
        node->famil = famil;

        std::cout << "Имя: ";
        std::cin >> node->name;
        std::cout << "Факультет: ";
        std::cin >> node->facult;

        node->kurs = readInt("Курс: ");
        node->ball = readDouble("Средний балл: ");

        node->next = nullptr;

        // подключение нового узла в конец списка
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        kolvoStudentov++;
        std::cout << "Студент добавлен. Введите следующего или * для завершения.\n\n";
    }

    if (head == nullptr) {
        std::cout << "Список пуст, поиск невозможен.\n";
        return 0;
    }

    // поиск: подстрока ищется сразу по всем текстовым полям
    std::string zapros;
    std::cout << "Введите строку для поиска (ищем по фамилии, имени и факультету): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, zapros);
    zapros = trim(zapros);

    int kolvo = 0;
    Student* cur = head;
    while (cur != nullptr) {
        bool est = (cur->famil.find(zapros) != std::string::npos) ||
                   (cur->name.find(zapros)  != std::string::npos) ||
                   (cur->facult.find(zapros) != std::string::npos);

        if (est) {
            std::cout << cur->famil << " " << cur->name
                      << ", факультет " << cur->facult
                      << ", курс " << cur->kurs
                      << ", балл " << cur->ball << "\n";
            kolvo++;
        }
        cur = cur->next;
    }

    if (kolvo == 0) std::cout << "Совпадений нет\n";
    else std::cout << "Найдено: " << kolvo << "\n";

    // освобождение памяти всех узлов списка
    cur = head;
    while (cur != nullptr) {
        Student* next = cur->next;
        delete cur;
        cur = next;
    }
}
//огранизовать односвязный список элементом которого является запись о студенте динамическе выдление памяти для студента окончание ввода звездочкой 
//поиск осуществляем сразу по всем полям структуры с неполным совпавдением 

