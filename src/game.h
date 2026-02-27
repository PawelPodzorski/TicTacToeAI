#pragma once
#include "tictactoe.h"

enum class Opponent { AI, Human };
enum class AiDifficulty { Easy, Medium, Impossible };

void playTTTGame();

// Human play functions
void humanMoveInput(tictactoe::Game& tgame, short player);
void humanVsHuman(tictactoe::Game& tgame);
void humanVsHumanPlusEval(tictactoe::Game& tgame);

// AI play functions
void PlayAi(tictactoe::Game& tgame, AiDifficulty difficulty, bool HumanIswhitePlayer);

// AI move functions
void EasyAiMove(tictactoe::Game& tgame, short player);
void MediumAiMove(tictactoe::Game& tgame, short player);
void ImpossibleAiMove(tictactoe::Game& tgame, short player);
void RandomMove(tictactoe::Game& tgame, short player);

Opponent ChooseOpponent();
AiDifficulty ChooseDifficulty();