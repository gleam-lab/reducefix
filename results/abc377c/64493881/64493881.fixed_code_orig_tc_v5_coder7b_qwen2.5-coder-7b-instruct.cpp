#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>

class Sub {
public:
    int solve() {
        long long N, M;
        scanf("%lld %lld", &N, &M);

        s(p(long long, long long)) pieces;
        for (long long i = 0; i < M; i++) {
            long long a, b;
            scanf("%lld %lld", &a, &b);
            pieces.insert({a, b});
        }

        long long total_squares = N * N;
        long long occupied_squares = pieces.size();

        // Directions for capturing
        vector<p(long long, long long)> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto& piece : pieces) {
            long long x = piece.first, y = piece.second;
            for (const auto& dir : directions) {
                long long nx = x + dir.first, ny = y + dir.second;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    pieces.erase({nx, ny});
                }
            }
        }

        long long valid_squares = total_squares - pieces.size();
        printf("%lld\n", valid_squares);

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}