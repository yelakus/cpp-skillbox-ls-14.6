#include <iostream>
#include <vector>

std::vector<std::vector<char>> initVector(){
    char emptyPlaceChar = '_'; // для редактирования символа пустых мест
    return {{emptyPlaceChar, emptyPlaceChar, emptyPlaceChar},
            {emptyPlaceChar, emptyPlaceChar, emptyPlaceChar},
            {emptyPlaceChar, emptyPlaceChar, emptyPlaceChar}};
}

void printVector(const std::vector<std::vector<char>> &vectorForPrint){
    for (auto &row : vectorForPrint){
        for (auto &el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

void move(const std::string &player, std::vector<std::vector<char>> &gameGround){
    int x, y;
    char playerChar;
    if (player == "Player 1(X)") playerChar = 'X';
    else playerChar = 'O';
    bool isCorrectInput = false;

    do{
        std::cout << player <<", make a move. Input position ([0-2] [0-2]):" << std::endl;
        std::cin >> x >> y;
        if (x < 0 || x > 2 || y < 0 || y >2){
            std::cout << "Incorrect position. Try again." << std::endl;
        } else if (gameGround[x][y] == 'X' || gameGround[x][y] == 'O')
            std::cout << "Place taken. Try again." << std::endl;
        else {
            isCorrectInput = true;
            gameGround[x][y] = playerChar;
            std::cout << "Saved!" << std::endl;
        }
    } while(!isCorrectInput);
}

bool isThereAWinner(const std::vector<std::vector<char>> &gameGround, std::string &winnerOut){
    if (gameGround[0][0] == 'X' && gameGround[0][0] == gameGround[0][1] && gameGround[0][1] == gameGround[0][2]
        || gameGround[1][0] == 'X' && gameGround[1][0] == gameGround[1][1] && gameGround[1][1] == gameGround[1][2]
        || gameGround[2][0] == 'X' && gameGround[2][0] == gameGround[2][1] && gameGround[2][1] == gameGround[2][2]
        || gameGround[0][0] == 'X' && gameGround[0][0] == gameGround[1][0] && gameGround[1][0] == gameGround[2][0]
        || gameGround[0][1] == 'X' && gameGround[0][1] == gameGround[1][1] && gameGround[1][1] == gameGround[2][1]
        || gameGround[0][2] == 'X' && gameGround[0][2] == gameGround[1][2] && gameGround[1][2] == gameGround[2][2]
        || gameGround[0][0] == 'X' && gameGround[0][0] == gameGround[1][1] && gameGround[1][1] == gameGround[2][2]
        || gameGround[0][2] == 'X' && gameGround[0][2] == gameGround[1][1] && gameGround[1][1] == gameGround[2][0]){
        winnerOut = "Player 1(X) is winner!";
        return true;
    }

    if (gameGround[0][0] == 'O' && gameGround[0][0] == gameGround[0][1] && gameGround[0][1] == gameGround[0][2]
        || gameGround[1][0] == 'O' && gameGround[1][0] == gameGround[1][1] && gameGround[1][1] == gameGround[1][2]
        || gameGround[2][0] == 'O' && gameGround[2][0] == gameGround[2][1] && gameGround[2][1] == gameGround[2][2]
        || gameGround[0][0] == 'O' && gameGround[0][0] == gameGround[1][0] && gameGround[1][0] == gameGround[2][0]
        || gameGround[0][1] == 'O' && gameGround[0][1] == gameGround[1][1] && gameGround[1][1] == gameGround[2][1]
        || gameGround[0][2] == 'O' && gameGround[0][2] == gameGround[1][2] && gameGround[1][2] == gameGround[2][2]
        || gameGround[0][0] == 'O' && gameGround[0][0] == gameGround[1][1] && gameGround[1][1] == gameGround[2][2]
        || gameGround[0][2] == 'O' && gameGround[0][2] == gameGround[1][1] && gameGround[1][1] == gameGround[2][0]){
        winnerOut = "Player 2(O) is winner!";
        return true;
    }
    return false;
}

int main() {
    auto gameGround = initVector();
    std::string winner = "tie";

    std::string player1 = "Player 1(X)";
    std::string player2 = "Player 2(O)";

    for (int i = 0; i < 9; ++i){
        printVector(gameGround);
        if (i % 2 == 0)
            move(player1, gameGround);
        else
            move(player2, gameGround);

        if (i > 3) // выявить победителя после 5-ого хода
            if (isThereAWinner(gameGround, winner))
                break;
    }

    std::cout << "Final playground: " << std::endl;
    printVector(gameGround);
    std::cout << "Game result: " << winner << std::endl;
}
