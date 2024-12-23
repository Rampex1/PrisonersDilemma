#ifndef PENDULUM_H
#define PENDULUM_H
#include "../Strategy.h"

// The Pendulum: Back and forth it goes, swaying predictably between friendship and betrayal—can
// you keep up with its rhythm?
class Pendulum : public Strategy {
    private:
        int move = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};



#endif //PENDULUM_H
