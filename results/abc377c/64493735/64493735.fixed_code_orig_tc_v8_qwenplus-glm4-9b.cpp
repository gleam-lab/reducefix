#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>
#define forn(i,n) for(int i = 0; i < (n); ++i)

class Sub {
public:
    int solve() {
        int N, M;
        cin >> N >> M;

        s<p(int, int)> pieces;
        forn(i, M) {
            int x, y;
            cin >> x >> y;
            pieces.emplace(x, y);
        }

        long long ans = N * N; // Start with all squares
        forn(i, N) {
            forn(j, N) {
                bool isAttacked = false;
                // Check if the current square (i, j) is under attack
                forn(dx, -2, 3) {
                    forn(dy, -2, 3) {
                        if (dx == 0 && dy == 0) continue; // Skip the current square itself
                        int nx = i + dx, ny = j + dy;
                        if (nx < 1 || nx > N || ny < 1 || ny > N) continue; // Skip out-of-bound coordinates
                        if (pieces.count({nx, ny})) {
                            isAttacked = true;
                            break;
                        }
                    }
                    if (isAttacked) break;
                }
                if (!isAttacked) ans--; // If not attacked, decrement the count of remaining squares
            }
        }

        cout << ans << endl;
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub sub;
    sub.solve();
    return 0;
}