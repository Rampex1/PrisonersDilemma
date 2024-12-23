#ifndef RANDOM_H
#define RANDOM_H
#include "../Strategy.h"

// The Random: Unpredictable and chaotic, this strategy keeps everyone guessing—friend or foe, who
// knows what’s next?
class Random : public Strategy{
    private:
        int move = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};



#endif //RANDOM_H
