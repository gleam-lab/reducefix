#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> captured_squares;

    vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dy = {2, 1, -1, 2, -2, -1, 2, -2};

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        for (int d = 0; d < 8; ++d) {
            long long nx = x + dx[d];
            long long ny = y + dy[d];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                captured_squares.insert({nx, ny});
            }
        }
    }

    long long available_squares = N * N - captured_squares.size();
    cout << available_squares << endl;

    return 0;
}