#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    for (auto &p : pieces) {
        // Capture positions relative to the current piece
        vector<pair<int, int>> captures = {
            {p.first + 2, p.second + 1},
            {p.first + 1, p.second + 2},
            {p.first - 1, p.second + 2},
            {p.first - 2, p.second + 1},
            {p.first - 2, p.second - 1},
            {p.first - 1, p.second - 2},
            {p.first + 1, p.second - 2},
            {p.first + 2, p.second - 1}
        };

        for (auto &cap : captures) {
            if (1 <= cap.first && cap.first <= N && 1 <= cap.second && cap.second <= N) {
                captured.insert(cap);
            }
        }
    }

    // Total squares minus the number of captured squares gives the number of free squares
    cout << (N * N) - captured.size() << '\n';

    return 0;
}