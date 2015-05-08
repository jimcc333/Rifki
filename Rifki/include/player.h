#ifndef PLAYER_H
#define PLAYER_H

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

        show_hand (){
            cout << "fine" << endl;
        }


    protected:
    private:
        map<int,bool> cards;
};

#endif // CARD_H
