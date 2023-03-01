#include <iostream>

void fillMatrix(float arr[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            std::cin >> arr[i][j];
        }
    }
}

void fillArr(float arr[]){
    for (int i = 0; i < 4; ++i){
        std::cin >> arr[i];
    }
}

void printMatrix(const float arr[][4]){
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void printArr(const float arr[]){
    for (int i = 0; i < 4; ++i){
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void multiplyMatrixToVector(const float matrix[][4], const float vector[], float result[]){
    float sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; ++j){
            sum += matrix[i][j] * vector[j];
        }
        result[i] = sum;
        sum = 0;
    }
}

int main() {
    float matrix[4][4];
    float vector[4], result[4];
    std::cout << "Input 4x4 matrix:" << std::endl;
    fillMatrix(matrix);
    std::cout << "Your matrix:" << std::endl;
    printMatrix(matrix);

    std::cout << "Input 4-elems vector:" << std::endl;
    fillArr(vector);
    std::cout << "Your vector:" << std::endl;
    printArr(vector);

    multiplyMatrixToVector(matrix, vector, result);
    std::cout << "Multiply result vector:" << std::endl;
    printArr(result);

}
