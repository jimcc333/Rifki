#include <iostream>
#include "./include/main.h"

using namespace std;

int main()
{

    //create game deck
    map<int,bool> cards;
    for(int i = 0; i < 52; i++){
        //declares the id of every available card in the game
        //  and assigns false to ownership
        cards[(i/13+1)*100 + (i+1)-(13*(i/13))] = false;
    }

    cout << "before" << endl;
    player player1(1,3, cards);
    cout << "after " << player1.id << endl;

    return 0;
}
