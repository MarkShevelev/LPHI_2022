#include <iostream>

// definition of a structure
struct Position {
    int x, y;
};

// examples of the structure usage in a function
void print(Position p, char delimiter = ' ') {
    std::cout << "(" << p.x << "," << p.y << ")" << delimiter;
}
int sqr_distance(Position a, Position b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); // making use of the access operator '.'
}

Position middle(Position a, Position b) {
    return Position{(a.x + b.x) / 2, (a.y + b.y) / 2};
}

void move(Position &p, int x_distance, int y_distance) {
    p.x += x_distance;
    p.y += y_distance;
}

using namespace std;

int main() {
    Position p1, p2; // variables declaration with a structure type
    p1.x = 1; p1.y = 2;
    p2.x = 3; p2.y = 6;

    auto p3 = middle(p1,p2);
    auto distance1 = sqr_distance(p3,p2);
    auto distance2 = sqr_distance(p3,p1);
    

    print(p1); print(p2); print(p3);
    cout << '\n';
    cout << distance1 << " " << distance2 << endl;

    return 0;
}