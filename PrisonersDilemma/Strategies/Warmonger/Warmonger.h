#ifndef WARMONGER_H
#define WARMONGER_H
#include "../Strategy.h"

// The Warmonger: Trust no one, show no mercy—this strategy’s motto is ‘defect first, ask questions never!’
class Warmonger : public Strategy {
    private:
        int nextMove = 1;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif // WARMONGER_H