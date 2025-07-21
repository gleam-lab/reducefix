#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> st;
    vector<vector<bool>> board(N, vector<bool>(N, false));

    vector<pair<long long, long long>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        st.insert({a, b});
        board[a][b] = true;
    }

    long long count = 0;

    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if (!board[i][j]) {
                bool valid = true;
                for (auto& move : moves) {
                    long long ni = i + move.first;
                    long long nj = j + move.second;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && st.count({ni, nj})) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ++count;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}