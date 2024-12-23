//
// Created by David Zhou on 2024-12-20.
//

#ifndef TITFORTAT_H
#define TITFORTAT_H
#include "../Strategy.h"

class TitForTat : public Strategy {
    private:
        int move = 0;
    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif //TITFORTAT_H
