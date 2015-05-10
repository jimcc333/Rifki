#ifndef PLAYER_H
#define PLAYER_H

#include "toolkit.h"

using namespace std;

/**
The players of the game

**/
class player {
    public:
        int id;
        int location;

        player (int player_id, int player_location){
            id = player_id;
            location = player_location;
        }

        void show_hand();
        void receive_hand(vector<int> hand){cards = hand;}


    protected:
    private:
        vector<int> cards;
};

#endif // CARD_H
