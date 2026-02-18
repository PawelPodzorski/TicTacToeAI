#pragma once
#include "../minimax.h"

namespace ai{
    struct MinimaxReturn {
        int eval;
        int move[2]; // row, col
    };
}