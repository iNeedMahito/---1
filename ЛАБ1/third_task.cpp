#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    int razmer;
    std::cout << "Размер массива: ";
    std::cin >> razmer;

    if (razmer <= 0) {
        std::cout << "Некорректный размер\n";
        return 0;
    }

    int* a = new int[razmer];

    int sum = 0;
    for (int i = 0; i < razmer; i++) {
        a[i] = rand() % 100;
        sum += a[i];
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Сумма = " << sum << "\n";
    std::cout << "Среднее = " << (double)sum / razmer << "\n";

    delete[] a;
}
