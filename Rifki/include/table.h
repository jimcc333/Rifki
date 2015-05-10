#ifndef TABLE_H
#define TABLE_H


class table
{
    public:
        table();
        virtual ~table();

        vector::map<int,int> on_table; //<from player_id, card_id> ordered
        vector::map<int,int> last_hand; //<from player_id, card_id> ordered
        vector::int player0; //cards taken by in this round player0
        vector::int player1;
        vector::int player2;
        vector::int player3;

        bool add_infront(int player_no, vector::int cards);
        reset();

    protected:
    private:
};

#endif // TABLE_H
