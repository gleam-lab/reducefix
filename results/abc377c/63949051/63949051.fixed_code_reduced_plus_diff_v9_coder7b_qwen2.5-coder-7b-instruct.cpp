#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL N, M;
    cin >> N >> M;

    set<pair<LL, LL>> pieces;
    for (LL i = 0; i < M; ++i) {
        LL x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    LL count = 0;

    for (LL i = 1; i <= N; ++i) {
        for (LL j = 1; j <= N; ++j) {
            bool safe = true;
            for (const auto& piece : pieces) {
                LL dx = abs(piece.first - i);
                LL dy = abs(piece.second - j);
                if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
                    safe = false;
                    break;
                }
            }
            if (safe) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}