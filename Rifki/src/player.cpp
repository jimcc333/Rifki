#include "../include/player.h"

void player::tell_hand(){
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


void player::show_hand (){
    bool zero = true;
    cout << "Player " << id << "'s cards:" << endl;

    for(int i = 0; i < cards.size(); i++){
        cout << i+1;
        if(i < 9){
            cout << " ";
        }
        card_output(cards[i]);
        zero = false;
    }

    if(zero){
        cout << "   -none-  " << endl;
    }
}

int player::call_contract(int contracts[7]){
    int takepoints = takepoint_eval(cards);




    est_hearts(cards);

    est_king(cards);


    sort(cards.begin(), cards.end());
    hand_output(cards);

    cout << "lowest of S: " << lowest_of_suit(cards, 1) << "  lowest of H: " << lowest_of_suit(cards, 2) << endl;

    cout << " king est: " << est_king(cards) << endl;



}





