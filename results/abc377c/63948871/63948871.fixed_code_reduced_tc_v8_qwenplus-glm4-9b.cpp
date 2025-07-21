#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define INF 1000000000

int main() {
    int N;
    cin >> N;
    int M;
    cin >> M;

    set<pair<int, int>> occupied;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y});
    }

    int free_squares = N * N; // Total squares

    // Check each square if it is free from capture
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool can_be_attacked = false;
            // Check the capture area of each piece
            for (auto& p : occupied) {
                int dx = abs(p.first - i);
                int dy = abs(p.second - j);
                if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                    can_be_attacked = true;
                    break;
                }
            }
            // If not attacked by any piece, decrease the count of free squares
            if (!can_be_attacked) {
                --free_squares;
            }
        }
    }

    cout << free_squares << endl;

    return 0;
}