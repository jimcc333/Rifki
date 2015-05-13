#ifndef TOOLKIT_H
#define TOOLKIT_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void card_reader(int id);
void card_output(int id);
void hand_output(vector<int> cards);
int takepoint_eval(vector<int> cards);
int take_rounds(vector<int> cards);
int count_suit(vector<int> cards, int suit_id);
void return_suit(vector<int> cards, int suit_id, vector<int> &scards);
int lowest_of_suit(vector<int> cards, int suit_id);
int highest_of_suit(vector<int> cards, int suit_id);
bool has_card(vector<int> cards, int card_id);
int est_king(vector<int> cards);
int est_hearts(vector<int> cards);
int est_girls(vector<int> cards);

#endif // TOOLKIT_H
