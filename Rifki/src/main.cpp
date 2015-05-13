#include <iostream>
#include "../include/main.h"

using namespace std;

int main()
{
    cout << "     --Welcome to Rifki!-- " << endl;
    cout << " -Starting new game- " << endl;

    if(new_game()){
        cout << " -Game over- " << endl;
    } else {
        cout << " Game failed!" << endl;
        return 0;
    }


    cout << "     --Rifki Exiting--" << endl;
    return 0;
}

bool new_game(){
    //create game deck
    vector<int> deck;
    for(int i = 0; i < 52; i++){
        deck.push_back((i/13+1)*100 + (i+2)-(13*(i/13)));
    }

    player player0(0,0); //player zero always first dealer
    player player1(1,1);
    player player2(2,2);
    player player3(3,3);

    score points;

    //start playing round by round
    for(int round = 0; round < 20; round++){
        cout << "Round " << round+1 << " begins." << endl;

        //shuffle the deck
        random_shuffle(deck.begin(), deck.end());

        //deal cards
        vector<int> pass (deck.begin(), deck.begin()+13);
        player0.receive_cards(pass);

        pass.assign(deck.begin()+13, deck.begin()+26);
        player1.receive_cards(pass);

        pass.assign(deck.begin()+26, deck.begin()+39);
        player2.receive_cards(pass);

        pass.assign(deck.begin()+39, deck.end());
        player3.receive_cards(pass);

        pass.clear();

        //start calling shit
        //player0.show_hand();
        player0.call_contract(points.contracts[player0.id]);



        //clear the cards
        player0.empty_hand();
        player1.empty_hand();
        player2.empty_hand();
        player3.empty_hand();

        cout << "End of round." << endl << endl;
    }

    return true;
}

