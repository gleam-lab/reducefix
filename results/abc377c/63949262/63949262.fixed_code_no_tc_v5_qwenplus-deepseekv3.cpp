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

    unordered_set<long long> unsafe_squares;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        long long pos = (long long)(pieces[i].first - 1) * N + (pieces[i].second - 1);
        unsafe_squares.insert(pos);
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (const auto &piece : pieces) {
        int x = piece.first;
        int y = piece.second;

        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                long long pos = (long long)(nx - 1) * N + (ny - 1);
                unsafe_squares.insert(pos);
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_count = unsafe_squares.size();
    long long safe_count = total_squares - unsafe_count;

    cout << safe_count << endl;

    return 0;
}