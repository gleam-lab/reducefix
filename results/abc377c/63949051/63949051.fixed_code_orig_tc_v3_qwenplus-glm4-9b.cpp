#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define LINF 1000000000000000000

using i64 = long long;
using pi64 = pair<i64, i64>;

// CCW (Counter-Clockwise) è®¡ç®
pi64 ccw(pi64 a, pi64 b, pi64 c) {
    return { (b.se - a.se) * (c.fi - a.fi) - (b.fi - a.fi) * (c.se - a.se),
             (b.fi - a.fi) * (c.fi - a.fi) + (b.se - a.se) * (c.se - a.se) };
}

// æ£æ¥ç¹æ¯å¦å¨ä¸è§å½¢
bool inside.pi64(pi64 a, pi64 b, pi64 c, pi64 p) {
    pi64 AB = ccw(a, b, c);
    pi64 AC = ccw(a, c, b);
    pi64 AP = ccw(a, p, b);
    pi64 PB = ccw(p, b, c);
    pi64 PC = ccw(p, c, b);
    pi64 PP = ccw(p, a, b);
    return (AB.se >= 0 && AP.se >= 0 && PP.se >= 0) && (PC.se >= 0 && PB.se >= 0 && BC.se >= 0);
}

// ä¸»è¦å¤çå½æ°
int main() {
    i64 N, M;
    cin >> N >> M;

    vector<pi64> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i].fi >> pieces[i].se;
    }

    set<pi64> attackable;
    for (i64 i = 0; i < M; ++i) {
        i64 x = pieces[i].fi, y = pieces[i].se;
        if (x + 2 <= N && y + 1 <= N) {
            attackable.insert({ x + 2, y + 1 });
        }
        if (x + 1 <= N && y + 2 <= N) {
            attackable.insert({ x + 1, y + 2 });
        }
        if (x - 1 >= 1 && y + 2 <= N) {
            attackable.insert({ x - 1, y + 2 });
        }
        if (x - 2 >= 1 && y + 1 <= N) {
            attackable.insert({ x - 2, y + 1 });
        }
        if (x - 2 >= 1 && y - 1 >= 1) {
            attackable.insert({ x - 2, y - 1 });
        }
        if (x - 1 >= 1 && y - 2 >= 1) {
            attackable.insert({ x - 1, y - 2 });
        }
        if (x + 1 <= N && y - 2 >= 1) {
            attackable.insert({ x + 1, y - 2 });
        }
        if (x + 2 <= N && y - 1 >= 1) {
            attackable.insert({ x + 2, y - 1 });
        }
    }

    i64 count = N * N;
    for (i64 i = 1; i <= N; ++i) {
        for (i64 j = 1; j <= N; ++j) {
            if (attackable.count({ i, j }) == 0) {
                count--;
            }
        }
    }

    cout << count << endl;

    return 0;
}