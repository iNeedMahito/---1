#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    const int rows = 6, cols = 8;
    int mass[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mass[i][j] = rand() % 30;
            std::cout << mass[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += mass[i][j];
        }
        std::cout << "Строка " << i + 1 << " - " << sum << "\n";
    }
    std::cout << "\n";

    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += mass[i][j];
        }
        std::cout << "Столбец " << j + 1 << " - " << sum << "\n";
    }
}
