#include "game.h"
#include <iostream>
#include "minimax.h"

using std::cout, std::cin;


void playTTTGame(){
    auto tgame = tictactoe::Game();
    cout << "Do you want to play against AI or Human?\n";
    Opponent opponent = GetOpponent();
    if(opponent == Opponent::AI){
        // placeholder
        humanVsHumanPlusEval(tgame);
    } else {
        humanVsHuman(tgame);
    }
    

}

Opponent GetOpponent(){
    Opponent opponent;
    std::string input;
    while(true){
        cin >> input;
        if(input[0] == 'A' || input[0] == 'a'){
            opponent = Opponent::AI;
            break;
        } else if(input[0] == 'H' || input[0] == 'h'){
            opponent = Opponent::Human;
            break;
        } else {
            cout << "Invalid input. Please enter A... or H...\n";
        }
    }
    return opponent;
}

void humanMove(tictactoe::Game& tgame, short player){
    short row, col;

    cout << "Player " << player << ", enter row and column (0-2) for your move\n";
    while(true){

        cin >> row >> col;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter numbers only\n";
            continue;
        }

        if(tgame.makeMove(row, col, player)){
            break;
        } else {
            cout << "Invalid move. Row and column must be between 0 and 2, or the space is already occupied\n";
            continue;
        }
    }
}

void humanVsHuman(tictactoe::Game& tgame){
    short player = 1;
    while(true){
        tgame.printBoard();

        humanMove(tgame, player);
        if(tgame.checkIfWin() == player){
            cout << "Player " << player << " wins!\n";
            return;
        }
        if(tgame.checkIfDraw()){
            cout << "Draw!\n";
            return;
        }
        player = (player == 1) ? 2 : 1;
    }
}

void humanVsHumanPlusEval(tictactoe::Game& tgame){
    short player = 1;
    while(true){
        tgame.printBoard();

        int eval = ai::minimax(tgame, (short)9, player, player == 1);
        cout << "AI evaluation: " << eval << "\n\n";
        humanMove(tgame, player);

        if(tgame.checkIfWin() == player){
            cout << "Player " << player << " wins!\n";
            return;
        }
        if(tgame.checkIfDraw()){
            cout << "Draw!\n";
            return;
        }
        player = (player == 1) ? 2 : 1;
    }
}
