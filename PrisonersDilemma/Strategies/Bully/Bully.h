#ifndef BULLY_H
#define BULLY_H
#include "../Strategy.h"


class Bully : public Strategy {
    private:
        int move = 1;
        int history_count = 0;
        int defect_count = 0;

    public:
        int getMove() override;
        void setNextMove(int result) override;
};

#endif //BULLY_H