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

/// updates the scards vector with the cards of the given suit
void return_suit(vector<int> cards, int suit_id, vector<int> &scards){
    scards.clear();
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it/100 == suit_id){
            scards.push_back(*it);
        }
    }
}

/// returns the number of the lowest numbered card in a suit, -1 if empty suit
int lowest_of_suit(vector<int> cards, int suit_id){
    int lowest = 99;
    bool assigned = false;
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it/100 == suit_id && lowest > *it%100){
            lowest = *it%100;
            assigned = true;
        }
    }
    if(assigned){
        return lowest;
    } else {
        return -1;
    }
}

/// return the number of the highest numbered card in a suit, -1 if empty suit
int highest_of_suit(vector<int> cards, int suit_id){
    int highest = 99;
    bool assigned = false;
    for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it/100 == suit_id && highest < *it%100){
            highest = *it%100;
            assigned = true;
        }
    }
    if(assigned){
        return highest;
    } else {
        return -1;
    }
}

/// return true if card is present, false otherwise
bool has_card(vector<int> cards, int card_id){
   for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it){
        if(*it == card_id){
            return true;
        }
    }
    return false;
}

/// estimates the points the hand would receive from king contract
int est_king(vector<int> cards){
    int ct = 70; //default is base rate

    sort(cards.begin(), cards.end());


    if(has_card(cards, 213)){
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

        // check for lowest cards in suits
        int i = lowest_of_suit(cards, 1);
        if(i < 5){ct -= 20;}
        else if(i < 6){ct -= 15;}
        else if(i < 7){ct -= 5;}

        i = lowest_of_suit(cards, 3);
        if(i < 5){ct -= 20;}
        else if(i < 6){ct -= 15;}
        else if(i < 7){ct -= 5;}

        i = lowest_of_suit(cards, 4);
        if(i < 5){ct -= 20;}
        else if(i < 6){ct -= 15;}
        else if(i < 7){ct -= 5;}

        // check for ace of hearts and other hearts
        if(count_suit(cards, 2) < 2 && has_card(cards, 214)){ct += 200;}
        if(count_suit(cards, 2) < 3 && has_card(cards, 214)){ct += 150;}

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
    if(scards.size() == 3 && ct >= 4){ct -= 1;}
    if(scards.size() == 2 && ct >= 4){ct -= 2;}
    if(scards.size() == 1 && ct >= 4){ct -= 3;}
    if(scards.size() == 0 && ct >= 4){ct -= 4;}

    return_suit(cards, 3, scards);
    if(scards.size() == 3 && ct >= 4){ct -= 1;}
    if(scards.size() == 2 && ct >= 4){ct -= 2;}
    if(scards.size() == 1 && ct >= 4){ct -= 3;}
    if(scards.size() == 0 && ct >= 4){ct -= 4;}

    return_suit(cards, 4, scards);
    if(scards.size() == 3 && ct >= 4){ct -= 1;}
    if(scards.size() == 2 && ct >= 4){ct -= 2;}
    if(scards.size() == 1 && ct >= 4){ct -= 3;}
    if(scards.size() == 0 && ct >= 4){ct -= 4;  }

    return ct*30;
}

/// estimates the points the hand would receive from no girls contract
int est_girls(vector<int> cards){
    int ct = 0;
    int suit_count;
    int inc = 120;

    for(int suit = 1; suit < 5; suit++){
        suit_count = count_suit(cards, suit);
        if(has_card(cards, suit*100+14)){
            if(has_card(cards, suit*100+12)){
                if(suit_count == 1){ct += inc*0.60;}
                if(suit_count == 2){ct += inc*0.20;}
                if(suit_count == 3){ct += inc*0.15;}
                if(suit_count == 4){ct += inc*0.04;}

            } else {
                if(suit_count == 1){ct += inc*0.80;}
                if(suit_count == 2){ct += inc*0.60;}
                if(suit_count == 3){ct += inc*0.30;}
                if(suit_count == 4){ct += inc*0.10;}
            }
        } else if(has_card(cards, suit*100+13)){
            if(has_card(cards, suit*100+12)){
                if(suit_count == 1){ct += inc*0.60;}
                if(suit_count == 2){ct += inc*0.20;}
                if(suit_count == 3){ct += inc*0.15;}
                if(suit_count == 4){ct += inc*0.4;}

            } else {
                if(suit_count == 1){ct += inc*0.80;}
                if(suit_count == 2){ct += inc*0.60;}
                if(suit_count == 3){ct += inc*0.30;}
                if(suit_count == 4){ct += inc*0.10;}
            }
        }
        if(has_card(cards, suit*100+14) && has_card(cards, suit*100+13)){
            if(suit_count == 2){ct += inc*0.100;}
            if(suit_count == 3){ct += inc*0.70;}
            if(suit_count == 4){ct += inc*0.50;}
            if(suit_count == 5){ct += inc*0.20;}
        }

        if(lowest_of_suit(cards, suit) == 5 && suit_count == 2){ct += inc*0.10;}
        if(lowest_of_suit(cards, suit) == 5 && suit_count == 3){ct += inc*0.30;}
        if(lowest_of_suit(cards, suit) == 5 && suit_count == 4){ct += inc*0.10;}

        if(lowest_of_suit(cards, suit) == 6 && suit_count == 2){ct += inc*0.15;}
        if(lowest_of_suit(cards, suit) == 6 && suit_count == 3){ct += inc*0.35;}
        if(lowest_of_suit(cards, suit) == 6 && suit_count == 4){ct += inc*0.15;}

        if(lowest_of_suit(cards, suit) == 7 && suit_count == 2){ct += inc*0.20;}
        if(lowest_of_suit(cards, suit) == 7 && suit_count == 3){ct += inc*0.50;}
        if(lowest_of_suit(cards, suit) == 7 && suit_count == 4){ct += inc*0.20;}

        if(lowest_of_suit(cards, suit) > 8 && suit_count == 2){ct += inc*0.40;}
        if(lowest_of_suit(cards, suit) > 8 && suit_count == 3){ct += inc*0.70;}
        if(lowest_of_suit(cards, suit) > 8 && suit_count == 4){ct += inc*0.40;}
    }

    return ct;
}

/// estimates the points the hand would receive from no b contract

int est_boys(vector<int> cards){
    float ct = 0;
    int suit_count;
    float inc = 60; // min: 40.  inc is like one negative point card

    for(int suit = 1; suit < 5; suit++){
        //suit_count = count_suit(cards, suit);

        if(lowest_of_suit(cards, suit) == 5 && suit_count <= 2){ct += inc*0.10;}
        if(lowest_of_suit(cards, suit) == 5 && suit_count == 3){ct += inc*0.30;}
        if(lowest_of_suit(cards, suit) == 5 && suit_count >= 4){ct += inc*0.10;}

        if(lowest_of_suit(cards, suit) == 6 && suit_count <= 2){ct += inc*0.15;}
        if(lowest_of_suit(cards, suit) == 6 && suit_count == 3){ct += inc*0.35;}
        if(lowest_of_suit(cards, suit) == 6 && suit_count >= 4){ct += inc*0.15;}

        if(lowest_of_suit(cards, suit) == 7 && suit_count <= 2){ct += inc*0.20;}
        if(lowest_of_suit(cards, suit) == 7 && suit_count == 3){ct += inc*0.50;}
        if(lowest_of_suit(cards, suit) == 7 && suit_count >= 4){ct += inc*0.20;}

        if(lowest_of_suit(cards, suit) > 8 && suit_count <= 2){ct += inc*0.40;}
        if(lowest_of_suit(cards, suit) > 8 && suit_count == 3){ct += inc*0.70;}
        if(lowest_of_suit(cards, suit) > 8 && suit_count >= 4){ct += inc*0.40;}


        if(highest_of_suit(cards, suit) == 14 && suit_count == 1){ct += inc*1.5;}
        if(highest_of_suit(cards, suit) == 14 && suit_count == 2){ct += inc*1.0;}
        if(highest_of_suit(cards, suit) == 14 && suit_count == 3){ct += inc*0.80;}
        if(highest_of_suit(cards, suit) == 14 && suit_count == 4){ct += inc*0.50;}
        if(highest_of_suit(cards, suit) == 14 && suit_count == 5){ct += inc*0.20;}
        if(highest_of_suit(cards, suit) == 14 && suit_count > 5){ct += inc*0.05;}

        inc -= 10;
        if(highest_of_suit(cards, suit) == 13 && suit_count == 1){ct += inc*1.5;}
        if(highest_of_suit(cards, suit) == 13 && suit_count == 2){ct += inc*1.0;}
        if(highest_of_suit(cards, suit) == 13 && suit_count == 3){ct += inc*0.80;}
        if(highest_of_suit(cards, suit) == 13 && suit_count == 4){ct += inc*0.50;}
        if(highest_of_suit(cards, suit) == 13 && suit_count == 5){ct += inc*0.20;}
        if(highest_of_suit(cards, suit) == 13 && suit_count > 5){ct += inc*0.05;}

        inc -= 10;
        if(highest_of_suit(cards, suit) == 12 && suit_count == 1){ct += inc*1.5;}
        if(highest_of_suit(cards, suit) == 12 && suit_count == 2){ct += inc*1.0;}
        if(highest_of_suit(cards, suit) == 12 && suit_count == 3){ct += inc*0.80;}
        if(highest_of_suit(cards, suit) == 12 && suit_count == 4){ct += inc*0.50;}
        if(highest_of_suit(cards, suit) == 12 && suit_count == 5){ct += inc*0.20;}
        if(highest_of_suit(cards, suit) == 12 && suit_count > 5){ct += inc*0.05;}

        inc -= 10;
        if(highest_of_suit(cards, suit) == 11 && suit_count == 1){ct += inc*1.5;}
        if(highest_of_suit(cards, suit) == 11 && suit_count == 2){ct += inc*1.0;}
        if(highest_of_suit(cards, suit) == 11 && suit_count == 3){ct += inc*0.80;}
        if(highest_of_suit(cards, suit) == 11 && suit_count == 4){ct += inc*0.50;}
        if(highest_of_suit(cards, suit) == 11 && suit_count == 5){ct += inc*0.20;}
        if(highest_of_suit(cards, suit) == 11 && suit_count > 5){ct += inc*0.05;}

        if(highest_of_suit(cards, suit) < 11 && suit_count == 1){ct -= inc*0.50;}
        if(highest_of_suit(cards, suit) < 11 && suit_count == 2){ct -= inc*0.40;}
        if(highest_of_suit(cards, suit) < 11 && suit_count == 3){ct -= inc*0.30;}
        if(highest_of_suit(cards, suit) < 11 && suit_count == 4){ct -= inc*0.20;}
        if(highest_of_suit(cards, suit) < 11 && suit_count == 5){ct -= inc*0.10;}
        if(highest_of_suit(cards, suit) < 11 && suit_count > 5){ct -= inc*0.05;}
    }

    return ct;
}














