#pragma once
#include "tictactoe.h"

enum class Opponent { AI, Human };

void playTTTGame();
void humanMove(tictactoe::Game& tgame, short player);
void humanVsHuman(tictactoe::Game& tgame);
void humanVsHumanPlusEval(tictactoe::Game& tgame);

Opponent ChooseOpponent();