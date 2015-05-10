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


void card_output(int id){
//takes a card id and outputs the card to terminal

    int suit = id/100;
    int number = id%100;

    if(number <= 0 || number > 13){
        cout << "  Card number error!" << endl;
        return;
    }

    for(int i = 0; i < number; i++){
        cout << " ";
    }
    if(number == 1){
        cout << "             ";
    }

    switch(suit){
        case 1 :
            cout << "S";
            break;
        case 2 :
            cout << "H";
            break;
        case 3 :
            cout << "C";
            break;
        case 4 :
            cout << "D";
            break;
        default :
            cout << " Suit type error!" << endl;
            return;
    }

    switch(number){
        case 1 :
            cout << "A";
            break;
        case 11 :
            cout << "J";
            break;
        case 12 :
            cout << "Q";
            break;
        case 13 :
            cout << "K";
            break;
        default :
            cout << number;
            break;
    }
    cout << endl;

    return;

}


/// estimates the value of the hand for trump game
int takepoint_eval(vector<int> cards){
    /**
    1 : 10
    13: 7
    12: 4
    11: 2
    10: 1
    **/
    int points = 0;
    int number;

    for(int i = 0; i < cards.size(); i++){
        number = cards[i]%100;

        switch(number){
            case 1:
                points += 10;
                break;
            case 13:
                points += 7;
                break;
            case 12:
                points += 4;
                break;
            case 11:
                points += 2;
                break;
            case 10:
                points += 1;
                break;
        }
    }

    return points;
}

/// estimates how many rounds the cards could take ignoring trump suit
int take_rounds(vector<int> cards){
    int number;
    int ct = 0;

    for(int i = 0; i < cards.size(); i++){
        number = cards[i]%100;
        if(number == 1){ct++;}

        if(number == 13 && count_suit(cards, cards[i]/100) > 1){ct++;}

        if(number == 12 && count_suit(cards, cards[i]/100) > 2){ct++;}
    }

    int trump_cand = 0;
    int current_max = 0;
    for(int i = 1; i < 5; i++){
        if(count_suit(cards, i) > current_max){
            trump_cand = i;
            current_max = count_suit(cards, i);
        }
    }

    if(current_max > 4){ct += current_max-4;}

    return ct;
}

/// counts the number of cards of a given suit in hand
int count_suit(vector<int> cards, int suit_id){
    int ct = 0;

    for(int i = 0; i < cards.size(); i++){
        if(cards[i]/100 == suit_id){ct++;}
    }
    return ct;
}

