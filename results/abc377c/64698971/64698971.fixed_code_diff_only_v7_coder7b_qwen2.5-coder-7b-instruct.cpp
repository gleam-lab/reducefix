#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<long long> st;
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        for (auto& move : moves) {
            int x = a + move.first, y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                st.insert(x * N + y);
            }
        }
    }

    long long total_squares = N * N;
    cout << total_squares - st.size() << endl;

    return 0;
}