#include "../include/table.h"

table::table()
{
    //ctor
}

table::~table()
{
    //dtor
}

bool table::add_infront(int player_no, vector::int cards){
    if(cards.size() < 1){
        return false;
    }
    switch(player_no){
        case 0:
            player0.push_back(cards);
            return true;
        case 1:
            player1.push_back(cards);
            return true;
        case 2:
            player2.push_back(cards);
            return true;
        case 3:
            player3.push_back(cards);
            return true;
        default:
            return false;
    }
}

table::reset(){
//clears all the cards on the table
    player0.clear();
    player1.clear();
    player2.clear();
    player3.clear();
    on_table.clear();
    last_hand.clear();

}
