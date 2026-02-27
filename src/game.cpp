#include "game.h"
#include <iostream>
#include "minimax.h"
#include <random>

using std::cout, std::cin;


void playTTTGame(){
    auto tgame = tictactoe::Game();
    cout << "Do you want to play against AI or Human?\n";
    Opponent opponent = ChooseOpponent();
    if(opponent == Opponent::Human){
        humanVsHuman(tgame);
    } 
    else if(opponent == Opponent::AI){
        cout << "Choose AI difficulty: [Easy | Medium | Impossible]\n";
        AiDifficulty difficulty = ChooseDifficulty();

        PlayAi(tgame, difficulty, true);
    }
}

Opponent ChooseOpponent(){
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

AiDifficulty ChooseDifficulty(){
    AiDifficulty difficulty;
    std::string input;
    while(true){
        cin >> input;
        if(input[0] == 'E' || input[0] == 'e'){
            difficulty = AiDifficulty::Easy;
            break;
        } else if(input[0] == 'M' || input[0] == 'm'){
            difficulty = AiDifficulty::Medium;
            break;
        } else if(input[0] == 'I' || input[0] == 'i'){
            difficulty = AiDifficulty::Impossible;
            break;
        } else {
            cout << "Invalid input. Please enter E..., M... or I...\n";
        }
    }
    return difficulty;
}   

void humanMoveInput(tictactoe::Game& tgame, short player){
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

        humanMoveInput(tgame, player);
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

void humanVsHumanPlusAiReport(tictactoe::Game& tgame){
    short player = 1;
    while(true){
        tgame.printBoard();

        ai::MinimaxReturn result = ai::evaluate(tgame, player, (short)tgame.getEmptyCellsCount(), player == 1);
        cout << "AI evaluation: " << result.eval << "\n";
        cout << "mate in: " << ai::matein(tgame, result.eval) << "\n\n";
        cout << "Best move: (" << result.move[0] << ", " << result.move[1] << ")\n";
        humanMoveInput(tgame, player);

        if(tgame.checkIfWin() == player){
            cout << "Player " << player << " wins!\n";
            return;
        }
        if(tgame.checkIfDraw()){
            cout << "Draw!\n";
            return;
        }
        player = ai::switchPlayer(player);
    }
}

void RandomMove(tictactoe::Game& tgame, short player){
    // random move
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    short row, col;
    do {
        row = dis(gen);
        col = dis(gen);
    } while (!tgame.makeMove(row, col, player));
}
void EasyAiMove(tictactoe::Game& tgame, short player){
    RandomMove(tgame, player);
}
void MediumAiMove(tictactoe::Game& tgame, short player){
    ai::MinimaxReturn result = ai::evaluate(tgame, player, (short)tgame.getEmptyCellsCount(), player == 1);
    if(result.eval >= ai::WIN_SCORE || result.eval <= ai::LOSE_SCORE){
        tgame.makeMove(result.move[0], result.move[1], player);
    } else {
        RandomMove(tgame, player);
    }
}
void ImpossibleAiMove(tictactoe::Game& tgame, short player){
    ai::MinimaxReturn result = ai::evaluate(tgame, player, (short)tgame.getEmptyCellsCount(), player == 1);
    tgame.makeMove(result.move[0], result.move[1], player);
}

void PlayAi(tictactoe::Game& tgame, AiDifficulty difficulty, bool HumanIswhitePlayer){
    short human = (HumanIswhitePlayer ? 1 : 2);
    short player = 1;
    while(true){
        cout << "-----------------------\n";
        tgame.printBoard();

        if(player == human){
            humanMoveInput(tgame, player);
        } else {
            switch(difficulty){
                case AiDifficulty::Easy:
                    EasyAiMove(tgame, player);
                    break;
                case AiDifficulty::Medium:
                    MediumAiMove(tgame, player);
                    break;
                case AiDifficulty::Impossible:
                    ImpossibleAiMove(tgame, player);
                    break;
            }
        }

        if(tgame.checkIfWin() == player){
            cout << "Player " << player << " wins!\n";
            return;
        }
        if(tgame.checkIfDraw()){
            cout << "Draw!\n";
            return;
        }
        player = ai::switchPlayer(player);
    }
}