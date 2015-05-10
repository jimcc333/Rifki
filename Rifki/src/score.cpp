#include "../include/score.h"

score::score()
{
    //ctor

    for(int i = 0; i < 4; i++){
        scores[i] = 0;

        contracts[i][0] = 2; //each player has 2 trump contracts
        for(int j = 1; j < 7; j++){
            contracts[i][j] = 3; //each player has 3 negative contracts
        }

        for(int j = 0; j < 20; j++){
            scoreboard[j][i] = 0;
        }
    }
    for(int j = 0; j < 20; j++){
        scoreboard[j+1][4] = 0;
    }
}

score::~score()
{
    //dtor
}


bool score::add(int player_id, int round, int contract_id, int added_score){
    // use negative values for negative score contracts

    if( scores.find(player_id) == scores.end() ||
        round > 13 || round < 1 || contract_id > 6 ||
        contract_id < 0 || scoreboard[round][player_id] != 0) {
        // some input was wrong, not comprehensive
        return false;
    } else {
        // player exists
        scores[player_id] += added_score;

        //scoreboard
        scoreboard[round][player_id] = added_score;
        scoreboard[round][0] = contract_id;

        return true;
    }
}


