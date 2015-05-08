#ifndef CARD_H
#define CARD_H


/**
Describes the cards in the game

    Suit #s:
        1 - Spades
        2 - Hearts
        3 - Clubs
        4 - Diamonds

        0 - Joker
    Card #s:
        01 - 1/Ace
        02 - 2
        ...
        10 - 10
        11 - Jack
        12 - Queen
        13 - King

**/
struct card
{
    public:
        int type_id; // (suit# x100) + card#
        int location_id; // 0 is unknown (could be at a players hand or discarded)
    protected:
    private:
        int owner_id; //who this card belongs at this time
};

#endif // CARD_H
