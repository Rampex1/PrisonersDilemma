#ifndef ENFORCER_H
#define ENFORCER_H
#include "../Strategy.h"

// The Enforcer: Trustworthy until crossed—betray it once, and it’ll strike back twice as hard to teach you a lesson!
class Enforcer : public Strategy {
    private:
        int move = 0;
        int retaliationCount = 0;
    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif //ENFORCER_H
