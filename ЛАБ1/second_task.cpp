#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    const int n = 20;
    int mass[n];
    int nizh = -30, verh = 70;

    for (int i = 0; i < n; i++) {
        mass[i] = nizh + rand() % (verh - nizh + 1);
    }

    std::cout << "Массив из " << n << " случайных чисел [" << nizh << "; " << verh << "]:\n";
    for (int i = 0; i < n; i++) {
        std::cout << mass[i] << " ";
    }
    std::cout << "\n";
}
