#include <iostream>
#include <vector>

void fillFieldWithFalse(bool field[][10]){
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; ++j) {
            field[i][j] = false;
        }
    }
}

void printField(const bool field[][10]){
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; ++j) {
            if (field[i][j])
                std::cout << "O\t";
            else std::cout << "[]\t";
        }
        std::cout << std::endl;
    }
}

void printHidField(const bool field[][10]){
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; ++j) {
            if (field[i][j])
                std::cout << "*\t";
            else std::cout << "X\t";
        }
        std::cout << std::endl;
    }
}

void putShip(std::vector<std::vector<int>> &playerShipsPositions, bool field[][10]){
    int pos1, pos2;
    std::cout << "Input X position:" << std::endl;
    std::cin >> pos1;
    std::cout << "Input Y position:" << std::endl;
    std::cin >> pos2;

    for (auto & pos1_2 : playerShipsPositions){
        if (pos1 < 0 || pos1 > 9
            || pos2 < 0 || pos2 > 9){
            std::cout << "Out of field! Try again." << std::endl;
            putShip(playerShipsPositions, field);
        }
        else if (pos1_2[0] == pos1
            && pos1_2[1] == pos2) {
            std::cout << "This position is taken! Try again." << std::endl;
            putShip(playerShipsPositions, field);
        }
    }
    field[pos1][pos2] = true;
    playerShipsPositions.push_back({pos1, pos2});
}

int main() {
    bool field_1[10][10];
    bool field_2[10][10];
    std::vector<std::vector<int>> player1ShipsPositions; // [20][2] - 4 * 1 + 3 * 2 + 2 * 3 + 1 * 4
    std::vector<std::vector<int>> player2ShipsPositions; // [20][2] - 4 * 1 + 3 * 2 + 2 * 3 + 1 * 4

    fillFieldWithFalse(field_1);
    fillFieldWithFalse(field_2);

    for(int i = 0; i < 4; i++){
        putShip(player1ShipsPositions, field_1);
    }


    for (auto & row : player1ShipsPositions){
        for (auto &column : row){
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }

    printField(field_1);
}
