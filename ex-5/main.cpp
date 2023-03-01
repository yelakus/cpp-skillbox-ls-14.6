#include <iostream>

void fillMatrix(bool matrix[][12]){
    for (int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            matrix[i][j] = true;
        }
    }
}

void printShell(const bool matrix[][12]){
    for (int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            if (matrix[i][j]) std::cout << "O ";
            else std::cout << "X ";
        }
        std::cout << std::endl;
    }
}

void getCoordinate(int arr[]){
    for (int i = 0; i < 2; ++i){
        std::cin >> arr[i];
    }
}

void popBubbles(bool shell[][12], int &wholeBubbles){
    int firstBubbleCoordinate[2], secondBubbleCoordinate[2];

    bool isCoordinatesCorrect = false;
    do{
        std::cout << "Input first coordinate([0-11 0-11]):" << std::endl;
        getCoordinate(firstBubbleCoordinate);
        if (firstBubbleCoordinate[0] < 0
            || firstBubbleCoordinate[0] > 12
            || firstBubbleCoordinate[1] < 0
            || firstBubbleCoordinate[1] > 12){
            std::cout << "Coordinates must be in the area from 0 to 11" << std::endl;
            isCoordinatesCorrect = false;
        } else isCoordinatesCorrect = true;
        std::cout << "Input second coordinate([0-11 0-11]). The coordinate values must be greater than or equal to the values of the first coordinate:" << std::endl;
        getCoordinate(secondBubbleCoordinate);
        if (secondBubbleCoordinate[0] < 0
            || secondBubbleCoordinate[0] > 12
            || secondBubbleCoordinate[1] < 0
            || secondBubbleCoordinate[1] > 12
            || secondBubbleCoordinate[0] < firstBubbleCoordinate[0]
            || secondBubbleCoordinate[1] < firstBubbleCoordinate[1]){
            std::cout << "Coordinates must be in the area from 0 to 11. The second coordinate values must be greater than or equal to the values of the first coordinate" << std::endl;
            isCoordinatesCorrect = false;
        } else isCoordinatesCorrect = true;
    } while(!isCoordinatesCorrect);

    int burstBubbles = 0;

    for (int i = firstBubbleCoordinate[0]; i <= secondBubbleCoordinate[0]; i++){
        for (int j = firstBubbleCoordinate[1]; j <= secondBubbleCoordinate[1]; j++){
            if (shell[i][j]){
                std::cout << "shell[" << i << "][" << j << "]: Pop!" << std::endl;
                shell[i][j] = false;
                burstBubbles++;
            }
        }
    }

    wholeBubbles -= burstBubbles;
}

int main() {
    bool shell[12][12];
    int wholeBubbles = 12*12;

    fillMatrix(shell);
    printShell(shell);

    while(wholeBubbles > 0){
        popBubbles(shell, wholeBubbles);
        printShell(shell);
        std::cout << "wholeBubbles: " << wholeBubbles << std::endl;
    }

}
