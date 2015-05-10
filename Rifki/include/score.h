#ifndef SCORE_H
#define SCORE_H


class score
{
    public:
        score();
        virtual ~score();


        bool add(int player_id, int round, int contract_id, int added_score);

        map<int,int> scores; //<player_id,current score>
        int scoreboard[20][5]; //[round][id] | id:player_id, id:4 contract_no
        int contracts[4][7]; //[player_id][contract_id]

    protected:
    private:

};

#endif // SCORE_H
