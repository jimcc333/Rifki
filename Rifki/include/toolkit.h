#ifndef TOOLKIT_H
#define TOOLKIT_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void card_reader(int id);
void card_output(int id);
int takepoint_eval(vector<int> cards);
int take_rounds(vector<int> cards);
int count_suit(vector<int> cards, int suit_id);

#endif // TOOLKIT_H
