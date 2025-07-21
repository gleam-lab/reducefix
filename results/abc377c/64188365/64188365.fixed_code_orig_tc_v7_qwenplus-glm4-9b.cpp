#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first;
        --pieces[i].second;
    }

    unordered_set<pair<long long, long long>> captured_cells;
    for (auto& p : pieces) {
        long long x = p.first, y = p.second;
        
        // Capture cells in the pattern described
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue; // Skip the piece itself
                long long nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    captured_cells.insert({nx, ny});
                }
            }
        }
    }

    // Total cells minus captured cells gives the number of empty cells
    cout << N * N - captured_cells.size() << endl;

    return 0;
}