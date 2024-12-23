#ifndef CROWDFOLLOWER_H
#define CROWDFOLLOWER_H
#include "../Strategy.h"

// The Crowd Follower: A true people-pleaser, this strategy goes with the flow, mirroring the
// majority's behavior to stay on the winning side!
class CrowdFollower : public Strategy {
    private:
        int move = 0;
        int splits = 0;
        int steals = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
    };
#endif //CROWDFOLLOWER_H
