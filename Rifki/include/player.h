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

        void tell_hand();
        void show_hand();
        void receive_cards(vector<int> hand){cards.insert(cards.end(), hand.begin(), hand.end());}
        void empty_hand(){cards.clear();}
        int call_contract(int contracts[7]);

        vector<int> cards;

    protected:
    private:

};

#endif // CARD_H
