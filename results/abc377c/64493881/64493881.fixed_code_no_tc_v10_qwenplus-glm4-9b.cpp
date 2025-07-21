#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    long long count = N * N;
    for (const auto& p : occupied) {
        int x = p.first, y = p.second;
        // Check all possible moves from the piece
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    // Remove all possible moves that can attack this piece
                    count--; // Move (nx, ny)
                    if (dx == -2 && dy == -2) count--; // Move (x-2, y-2)
                    if (dx == -2 && dy == 2) count--; // Move (x-2, y+2)
                    if (dx == 2 && dy == -2) count--; // Move (x+2, y-2)
                    if (dx == 2 && dy == 2) count--; // Move (x+2, y+2)
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}