#include "../include/toolkit.h"

using namespace std;

void card_reader(int id){
//takes a card id and outputs the name of it to the terminal

    int suit = id/100;
    int number = id%100;

    if(number <= 1 || number > 14){
        cout << "  Card number error!" << endl;
        return;
    }

    switch(number){
        case 14 :
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

    if(number <= 1 || number > 14){
        cout << "  Card number error!" << endl;
        return;
    }

    for(int i = 0; i < number; i++){
        cout << " ";
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
        case 14 :
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

void hand_output(vector<int> cards){
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        card_output(*it);
    }
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

/// returns a vector of the cards of the given suit
void return_suit(vector<int> cards, int suit_id, vector<int> &scards){
    scards.clear();
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it/100 == suit_id){
            scards.push_back(*it);
        }
    }
}


/// estimates the points the hand would receive from king contract
int est_king(vector<int> cards){
    int ct = 320/4; //default is base rate
    bool have_king = false;

    sort(cards.begin(), cards.end());

    //check to see if king is held
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it == 214){have_king = true;}
    }

    if(have_king){
        if(count_suit(cards, 1) == 0 || count_suit(cards, 3) == 0 || count_suit(cards, 4) == 0){
            // holding the king and have an empty suit in hand
            ct = 0;
        }
        if(count_suit(cards, 1) == 1 || count_suit(cards, 3) == 1 || count_suit(cards, 4) == 1){
            // holding the king and have a single card suit in hand
            ct = 16;
        }
        if(count_suit(cards, 1) == 2 || count_suit(cards, 3) == 2 || count_suit(cards, 4) == 2){
            // holding the king and have a two card suit in hand
            ct = 40;
        }
    } else {
        // dont have the king


    }

    return ct;
}


/// estimates the points the hand would receive from no hearts contract
int est_hearts(vector<int> cards){
    int ct = 0;
    int suit;

    sort(cards.begin(), cards.end());

    vector<int> scards;

    return_suit(cards, 2, scards);

    switch(scards.size()){
        case 0:
            break;
        case 1:
            if(scards[0]%100 > 4){ct += 4;}
            break;
        case 2:
            if(scards[0]%100 > 4){ct += 4;}
            if(scards[1]%100 > 8){ct += 4;}
            break;
        case 3:
            if(scards[0]%100 > 4){ct += 4;}
            if(scards[1]%100 > 8){ct += 4;}
            if(scards[2]%100 > 11){ct += 3;}
            break;
        case 4:
            if(scards[0]%100 > 4){ct += 4;}
            if(scards[1]%100 > 8){ct += 4;}
            if(scards[2]%100 > 12){ct += 3;}
            break;
        default:
            if(scards[0]%100 > 4){ct += 4;}
            if(scards[1]%100 > 8){ct += 4;}
            break;
    }

    // check if there is chance to get rid of an unwanted high heart
    return_suit(cards, 1, scards);
    if(scards.size() == 3 && ct >= 4){ct -= 1}
    if(scards.size() == 2 && ct >= 4){ct -= 2}
    if(scards.size() == 1 && ct >= 4){ct -= 3}
    if(scards.size() == 0 && ct >= 4){ct -= 4}

    return_suit(cards, 3, scards);
    if(scards.size() == 3 && ct >= 4){ct -= 1}
    if(scards.size() == 2 && ct >= 4){ct -= 2}
    if(scards.size() == 1 && ct >= 4){ct -= 3}
    if(scards.size() == 0 && ct >= 4){ct -= 4}

    return_suit(cards, 4, scards);
    if(scards.size() == 3 && ct >= 4){ct -= 1}
    if(scards.size() == 2 && ct >= 4){ct -= 2}
    if(scards.size() == 1 && ct >= 4){ct -= 3}
    if(scards.size() == 0 && ct >= 4){ct -= 4}

    return ct*30;
}

