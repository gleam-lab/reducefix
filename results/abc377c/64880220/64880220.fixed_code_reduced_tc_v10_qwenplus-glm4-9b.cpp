#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
    Point(long long x, long long y) : x(x), y(y) {}
};

// Directions are in clockwise order starting from the upper right
const vector<Point> directions = {
    Point(1, 2), Point(2, 1), Point(2, -1), Point(1, -2),
    Point(-1, -2), Point(-2, -1), Point(-2, 1), Point(-1, 2)
};

bool canPlacePiece(int n, const vector<Point>& occupied, Point newPiece) {
    if (newPiece.x < 1 || newPiece.x > n || newPiece.y < 1 || newPiece.y > n) {
        return false;
    }
    for (const auto& dir : directions) {
        Point target(newPiece.x + dir.x, newPiece.y + dir.y);
        if (find(occupied.begin(), occupied.end(), target) != occupied.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<Point> occupied;
    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        occupied.push_back(Point(x, y));
    }

    // Count the total number of free squares
    long long totalSquares = n * n;
    
    // Count the number of free squares that can't be occupied
    long long occupiedSquares = 0;
    for (const auto& occupiedPoint : occupied) {
        if (canPlacePiece(n, occupied, occupiedPoint)) {
            occupiedSquares++;
        }
    }

    // Calculate the number of free squares that can be occupied
    long long freeSquares = totalSquares - occupiedSquares;
    cout << freeSquares << endl;

    return 0;
}