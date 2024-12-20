#ifndef PEACEMAKER_H
#define PEACEMAKER_H
#include "../Strategy.h"

// The Peacemaker: Ever the optimist, this strategy trusts everyone completely—just don’t be
// surprised when it gets betrayed!
class Peacemaker : public Strategy {
    private:
        int move = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif //PEACEMAKER_H
