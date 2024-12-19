#ifndef PEACEMAKER_H
#define PEACEMAKER_H
#include "../Strategy.h"

// The Peacemaker: Ever the optimist, this strategy trusts everyone completely—just don’t be
// surprised when it gets betrayed!
class Peacemaker : public Strategy {
private:
    int nextMove = 0;

public:
    int getNextMove() override;
};

#endif //PEACEMAKER_H
