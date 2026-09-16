#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    const int n = 15;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101 - 50;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int maxi = arr[0], mini = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxi) maxi = arr[i];
        else if (arr[i] < mini) mini = arr[i];
    }

    std::cout << "Max = " << maxi << ", Min = " << mini << "\n";
    std::cout << "Разница = " << maxi - mini << "\n";
}
