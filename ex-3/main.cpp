#include <iostream>

void fillMatrix(int arr[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            std::cin >> arr[i][j];
        }
    }
}

void printArr(const int arr[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool isMatricesSame(const int arr1[][4], const int arr2[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (arr1[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}

void createDiagonalMatrix(int arr[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (i != j)
                arr[i][j] = 0;
        }
    }
}

int main() {
    int firstArr[4][4];
    int secondArr[4][4];
    std::cout << "Input first 4x4 matrix:" << std::endl;
    fillMatrix(firstArr);
    std::cout << "Your first matrix:" << std::endl;
    printArr(firstArr);

    std::cout << "Input second 4x4 matrix:" << std::endl;
    fillMatrix(secondArr);
    std::cout << "Your second matrix:" << std::endl;
    printArr(secondArr);

    if (isMatricesSame(firstArr, secondArr)){
        createDiagonalMatrix(firstArr);
        std::cout << "Your matrices are same!" << std::endl;
        std::cout << "Diagonal matrix:" << std::endl;
        printArr(firstArr);
    } else std::cout << "Your matrices are NOT same!" << std::endl;

}
