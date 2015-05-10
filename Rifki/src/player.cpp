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
    cout << "suit 1: " << count_suit(cards, 1) << endl;
    cout << "suit 2: " << count_suit(cards, 2) << endl;
    cout << "suit 3: " << count_suit(cards, 3) << endl;
    cout << "suit 4: " << count_suit(cards, 4) << endl;

    cout << " round est: " << take_rounds(cards) << endl;

}





