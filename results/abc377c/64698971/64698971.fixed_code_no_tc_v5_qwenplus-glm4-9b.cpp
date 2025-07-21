#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000000000; // Maximum value for N
const int MAX_M = 200000; // Maximum value for M
const vector<pair<int, int>> directions = {
    {0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

long long calculateAvailableSpaces(int N, const vector<pair<int, int>>& pieces) {
    bitset<MAXN> taken;
    for (const auto& piece : pieces) {
        taken[piece.first * N + piece.second] = true;
    }

    long long availableSpaces = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!taken[i * N + j]) {
                bool isSafe = true;
                for (const auto& dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (x >= 0 && x < N && y >= 0 && y < N) {
                        if (taken[x * N + y]) {
                            isSafe = false;
                            break;
                        }
                    }
                }
                if (isSafe) {
                    availableSpaces++;
                }
            }
        }
    }
    return availableSpaces;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1};
    }

    cout << calculateAvailableSpaces(N, pieces) << endl;
    return 0;
}