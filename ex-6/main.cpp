#include <iostream>

int main() {
    int arr[5][5];
    int number = 0;
    int multiplier = 1;

    for (auto &i : arr) {
        for (int j = 2-(2*multiplier); j >= 0 && j <= 4; j += (1*multiplier)) {
            i[j] = number;
            number += 1;
        }
        multiplier *= -1;
    }

    for (auto &i : arr) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
