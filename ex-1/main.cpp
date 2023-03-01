#include <iostream>

int main() {
    int cutlery[2][6] = {{4, 3, 3, 3, 3, 3},
                         {4, 3, 3, 3, 3, 3}};
    int plates[2][6] = {{3, 2, 2, 2, 2, 2},
                         {3, 2, 2, 2, 2, 2}};
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    chairs[0][4] += 1;  // пятое место первого ряда ... приставлен ещё один стул
    cutlery[1][2] -= 1; // С третьего места во втором ряду ... была украдена ложка
    cutlery[0][0] -= 1; // Одна из VIP-персон (любая) поделилась своей ложкой ...
    cutlery[1][2] += 1; // ... с тем, кто остался без ложки
    plates[0][0] -= 1;  // официант забрал у VIP-гостя одну десертную тарелку

    std::cout << "Cutlery:" << std::endl;

    for (auto &row : cutlery){
        for (auto &oneOfTheCutlery : row){
            std::cout << oneOfTheCutlery << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Plates:" << std::endl;
    for (auto &row : plates){
        for (auto &plate : row){
            std::cout << plate << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Chairs:" << std::endl;
    for (auto &row : chairs){
        for (auto &chair : row){
            std::cout << chair << " ";
        }
        std::cout << std::endl;
    }
}
