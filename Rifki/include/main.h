#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <map>
#include <vector>
#include <algorithm>    // std::random_shuffle

#include "card.h"
#include "../src/player.cpp"
#include "../src/toolkit.cpp"
#include "../src/score.cpp"

/**
Contracts:

    0: +50x13 for every round: trump
    1: -320 for 213: king/rifki
    2: -100x4 for *12: no girls
    3: -60x8 for *11 or *13: no boys
    4: -30x13 for 2**
    5: -180x2 for last two rounds: no last two
    6: -50x13 for every round: no tricks

**/

bool new_game();

#endif // MAIN_H_INCLUDED
