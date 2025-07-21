#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

// Directions in terms of (dx, dy) for all 8 possible knight moves
const vector<pair<long long, long long>> knight_moves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Custom hash to allow pair in unordered_set
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<long long, long long>, pair_hash> attacked;
    vector<pair<long long, long long>> pieces(M);

    // Read piece positions and mark attacked squares
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};

        // Mark squares that this piece can attack
        for (const auto& [dx, dy] : knight_moves) {
            long long ni = a + dx;
            long long nj = b + dy;
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked.insert({ni, nj});
            }
        }
    }

    // Remove original piece positions from attacked set since they are not empty
    for (const auto& [a, b] : pieces) {
        attacked.erase({a, b});
    }

    // Total empty squares = total squares - number of pieces - number of attacked squares
    unsigned __int128 total = (__int128)N * N;
    total -= M;
    total -= attacked.size();

    // Output the result as string
    cout << (unsigned long long)total << endl;

    return 0;
}