#include <iostream>

void getHeights(int heights[][5]){
    int candidate;

    std::cout << "input matrix of heights:" << std::endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cin >> candidate;
            if (candidate < 0 || candidate > 10){
                do{
                    std::cout << "input correct heights(1-10):" << std::endl;
                    std::cin >> candidate;
                }while(candidate < 0 || candidate > 10);
            }
            heights[i][j] = candidate;
        }
    }
}

void print2xMatrix(const int arr[][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void print3xMatrix(const int arr[][5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                std::cout << arr[i][j][k] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------" <<std::endl;
    }
}

void fillWorld(const int heights[][5], bool world[][5][5]){
    for (int i = 0; i < 11; i++){ // ide выдает предупреждение, но если вписать 10 вместо 11, то вверхний слайс не будет заполнен
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (heights[j][k] >= i)
                    world[i][j][k] = true;
                else
                    world[i][j][k] = false;
            }
        }
    }
}

void getSlice(const bool world[][5][5]){
    int slice[5][5];
    int line;

    while(true){
        std::cout << "input height of slice. Input -1 for stop:" << std::endl;
        std::cin >> line;

        if (line == -1) break;

        if (line < 1 || line > 10){
            do{
                std::cout << "input correct heights(1-10):" << std::endl;
                std::cin >> line;
            }while(line < 1 || line > 10);
        }

        for (int j = 0; j < 5; j++){
            for (int k =0; k < 5; k++){
                if (world[line][j][k])
                    slice[j][k] = 1;
                else
                    slice[j][k] = 0;
            }
        }
        print2xMatrix(slice);
    }
}

int main() {
    bool world[10][5][5];
    int heights[5][5];

    getHeights(heights);
    //print2xMatrix(heights);

    fillWorld(heights, world);
    //print3xMatrix(world);

    getSlice(world);

}
