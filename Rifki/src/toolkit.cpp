#include "../include/toolkit.h"

using namespace std;

void card_reader(int id){
//takes a card id and outputs the name of it to the terminal

    int suit = id/100;
    int number = id%100;

    if(number <= 0 || number > 13){
        cout << "  Card number error!" << endl;
        return;
    }

    switch(number){
        case 1 :
            cout << "Ace of ";
            break;
        case 11 :
            cout << "Jack of ";
            break;
        case 12 :
            cout << "Queen of ";
            break;
        case 13 :
            cout << "King of ";
            break;
        default :
            cout << number << " of ";
            break;
    }

    switch(suit){
        case 1 :
            cout << "Spades" << endl;
            break;
        case 2 :
            cout << "Hearts" << endl;
            break;
        case 3 :
            cout << "Clubs" << endl;
            break;
        case 4 :
            cout << "Diamonds" << endl;
            break;
        default :
            cout << " Suit type error!" << endl;
            return;
    }

    return;
}

