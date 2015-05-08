#include "../include/player.h"

void player::show_hand (){
    bool zero = true;
    cout << "Player " << id << "'s cards:" << endl;

    for(map<int,bool>::iterator it = cards.begin(); it != cards.end(); it++){
        if(it->second){
            card_reader(it->first);
            zero = false;
        }
    }

    if(zero){
        cout << "   -none-  " << endl;
    }
}
