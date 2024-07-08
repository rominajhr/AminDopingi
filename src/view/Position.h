#ifndef AMINDOPINGI_POSITION_H
#define AMINDOPINGI_POSITION_H

#include <iostream>


class Position {

public:
    Position();
    Position(int X,int Y);
    Position (const Position &cpy);
    friend Position operator +(const Position & firstPos,const Position & secondPos);
    friend Position operator -(const Position & firstPos,const Position & secondPos);
    float x{};
    float y{};

};


#endif
