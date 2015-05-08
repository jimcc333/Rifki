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

        player (int player_id, int player_location, map<int,bool> player_cards){
            id = player_id;
            location = player_location;
            cards  = player_cards;
        }

        void show_hand();


    protected:
    private:
        map<int,bool> cards;
};

#endif // CARD_H
