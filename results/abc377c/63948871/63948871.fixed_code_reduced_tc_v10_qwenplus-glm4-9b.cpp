#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define MAX_N 1000000000

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden_positions;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden_positions.insert({a, b});

        // Check the 8 possible positions that can capture other pieces
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue; // Skip the current position
                long long x = a + dx;
                long long y = b + dy;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    forbidden_positions.insert({x, y});
                }
            }
        }
    }

    // Calculate the total number of positions that can be placed without being captured
    long long possible_positions = N * N;
    for (const auto& pos : forbidden_positions) {
        possible_positions--;
    }

    cout << possible_positions << endl;

    return 0;
}