#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> occupied;
    set<pair<int, int>> attack_ranges;

    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = a + dx;
                int ny = b + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    attack_ranges.insert({nx, ny});
                }
            }
        }
    }

    // Calculate the number of empty squares
    int empty_squares = N * N;
    for (const auto& p : occupied) {
        --empty_squares;
    }
    for (const auto& p : attack_ranges) {
        if (occupied.count(p)) {
            occupied.erase(p);
        }
    }
    empty_squares -= occupied.size();

    cout << empty_squares << endl;

    return 0;
}