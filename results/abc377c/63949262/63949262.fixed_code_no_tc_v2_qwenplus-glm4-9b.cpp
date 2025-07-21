#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    set<pair<int, int>> occupied;

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        occupied.insert(pieces[i]);
    }

    long long safeSquares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool isSafe = true;
            for (const auto& p : pieces) {
                int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
                int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && occupied.count({nx, ny})) {
                        isSafe = false;
                        break;
                    }
                }
                if (!isSafe) break;
            }
            if (isSafe) safeSquares++;
        }
    }

    cout << safeSquares << endl;

    return 0;
}