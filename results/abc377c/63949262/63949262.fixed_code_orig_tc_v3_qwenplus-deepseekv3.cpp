#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    int M;
    cin >> M;

    unordered_set<long long> unsafe_positions;
    vector<pair<int, int>> existing_pieces(M);

    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;
        existing_pieces[k] = {a, b};
        long long pos = (a - 1) * N + (b - 1);
        unsafe_positions.insert(pos);
    }

    for (const auto& piece : existing_pieces) {
        int i = piece.first;
        int j = piece.second;

        // Generate all 8 possible knight moves
        int moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                           {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        for (int m = 0; m < 8; ++m) {
            int ni = i + moves[m][0];
            int nj = j + moves[m][1];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                long long pos = (ni - 1) * N + (nj - 1);
                unsafe_positions.insert(pos);
            }
        }
    }

    long long total_safe = N * N - unsafe_positions.size();
    cout << total_safe << endl;

    return 0;
}