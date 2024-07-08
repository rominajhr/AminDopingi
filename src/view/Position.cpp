#include "Position.h"

Position::Position(int X, int Y) {
    x=X;
    y=Y;
}

Position::Position(const Position &cpy) {
    x=cpy.x;
    y=cpy.y;
}

Position::Position() {
    x=0;
    y=0;
}

Position operator+(const Position & firstPos,const Position & secondPos) {
    return Position(firstPos.x+secondPos.x, firstPos.y+secondPos.y);

}

Position operator-(const Position & firstPos,const Position & secondPos) {
    return Position(firstPos.x-secondPos.x, firstPos.y-secondPos.y);
}
