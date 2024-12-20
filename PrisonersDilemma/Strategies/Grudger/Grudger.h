#ifndef GRUDGER_H
#define GRUDGER_H
#include "../Strategy.h"

// The Grudger: Forgive? Never. This strategy holds a grudge forever after even a single betrayal!
class Grudger : public Strategy {
    private:
        int move = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};
#endif //GRUDGER_H
