#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> affected;
    vector<pair<long long, long long>> pieces(M);

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};

        // Check the 3x3 area around the piece to determine the affected region
        for (long long dx = -2; dx <= 2; ++dx) {
            for (long long dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue; // Skip the piece itself
                long long nx = a + dx, ny = b + dy;
                // Check if the square is within the grid boundaries
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    affected.insert({nx, ny});
                }
            }
        }
    }

    // Calculate the total number of empty squares
    long long total_squares = N * N;
    // Subtract the number of affected squares
    long long empty_squares = total_squares - affected.size();

    cout << empty_squares << endl;

    return 0;
}