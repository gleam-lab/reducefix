#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Directions for knight moves (8 possible positions)
const vector<pair<long long, long long>> directions = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    pair<long long, long long> pos;
    const long long MOD = 1000000000;

    // To store the positions of existing pieces
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pos.first >> pos.second;
        pieces[i] = pos;
    }

    // Calculate all attacked positions
    for (const auto& p : pieces) {
        long long x = p.first;
        long long y = p.second;

        for (const auto& d : directions) {
            long long nx = x + d.first;
            long long ny = y + d.second;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                // Combine coordinates into single 64-bit integer (assuming N <= 1e9)
                attacked.insert(nx * MOD + ny);
            }
        }
    }

    // Remove original piece positions from attacked set to ensure they don't block themselves
    for (const auto& p : pieces) {
        long long code = p.first * MOD + p.second;
        attacked.erase(code);
    }

    // Total positions under attack is the size of the set
    cout << (1LL * N * N - M - attacked.size()) << endl;

    return 0;
}