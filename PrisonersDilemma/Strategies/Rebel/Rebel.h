#ifndef REBEL_H
#define REBEL_H
#include "../Strategy.h"

// The Rebel: Chaos is the name of the game—starting with betrayal, it thrives on doing the
// opposite of whatever you do!
class Rebel : public Strategy {
    private:
        int move = 0;
    public:
        int getMove() override;
        void setNextMove(int result) override;
    };

#endif //REBEL_H
