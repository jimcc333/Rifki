#include <iostream>
#include "../include/main.h"

using namespace std;

int main()
{
    cout << "     --Welcome to King!-- " << endl;

    //create game deck
    map<int,bool> cards;
    for(int i = 0; i < 52; i++){
        //declares the id of every available card in the game
        //  and assigns false to ownership
        cards[(i/13+1)*100 + (i+1)-(13*(i/13))] = false;
    }

    player player1(0,0,cards);
    player player2(1,1,cards);
    player player3(2,2,cards);
    player player4(3,3,cards);

    score points;


    cout << endl << "     --Game over--" << endl;
    return 0;
}



