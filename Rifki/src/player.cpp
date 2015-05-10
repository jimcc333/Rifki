#include "../include/player.h"

void player::show_hand (){
    bool zero = true;
    cout << "Player " << id << "'s cards:" << endl;

    for(int i = 0; i < cards.size(); i++){
        card_reader(cards[i]);
        zero = false;
    }

    if(zero){
        cout << "   -none-  " << endl;
    }
}
