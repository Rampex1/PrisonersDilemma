#ifndef TITFORTAT_H
#define TITFORTAT_H
#include "../Strategy.h"

// Tit for Tat: The fair and faithful partner—play nice, and it’ll match your kindness; betray it,
//  and prepare for payback!
class TitForTat : public Strategy {
    private:
        int move = 0;
    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif //TITFORTAT_H
