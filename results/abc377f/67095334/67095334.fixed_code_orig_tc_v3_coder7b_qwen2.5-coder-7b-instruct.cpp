#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)(r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    set<PII> h, v, d1, d2; // d1 存 i+j=d 的对角线 d2 存i-j=d的对角线
    
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        h.insert({x, y});
        v.insert({x, y});
        d1.insert({x + y, y});
        d2.insert({x - y, y});
    }

    int ans = (n - (int)h.size()) * (n - (int)v.size());

    for (auto [sum, y] : d1) {
        // i+j=sum 的对角线
        set<int> s; // 记录已经被算过的行坐标
        for (auto [x, _] : h) { // 找到所有和该对角线相交的水平线
            if (1 <= sum - x && sum - x <= n) {
                s.insert(sum - x);
            }
        }

        for (auto [_, vy] : v) { // 找到所有和该对角线相交的垂直线
            if (1 <= sum - vy && sum - vy <= n) {
                s.insert(sum - vy);
            }
        }

        int len = 0;
        if (sum <= n + 1) { // 在左上部分，列坐标1~sum-1
            len = sum - 1;
        } else { // 在右下部分，列坐标sum-n~n
            len = n - (sum - n) + 1;
        }
        ans -= (len - s.size()); // 所有这条对角线上y的取值（每个y对应一个x）减去 已经减去的x值（也就是已经减去了的点）
    }

    for (auto [diff, y] : d2) {
        // i-j=diff 的对角线
        set<int> s; // 记录已经被算过的行坐标
        for (auto [x, _] : h) { // 找到所有和该对角线相交的水平线
            if (1 <= x - diff && x - diff <= n) {
                s.insert(x - diff);
            }
        }

        for (auto [_, vy] : v) { // 找到所有和该对角线相交的垂直线
            if (1 <= diff + vy && diff + vy <= n) {
                s.insert(diff + vy);
            }
        }

        for (auto [sdiff, _] : d1) {
            // i+j==sdiff,i-j==diff
            if ((sdiff + diff) % 2 == 0 && (sdiff - diff) % 2 == 0) {
                int si = (sdiff + diff) / 2, sj = (sdiff - diff) / 2;
                if (si >= 2 && si <= n && sj >= 1 && sj <= n) {
                    s.insert(si);
                }
            }
        }

        int len = 0;
        if (diff <= 0) { // 在右上部分，列坐标1-diff~n
            len = n - (1 - diff) + 1;
        } else { // 在左下部分，列坐标1-n-diff
            len = n - diff;
        }
        ans -= (len - s.size()); // 所有这条对角线上y的取值（每个y对应一个x）减去 已经减去的x值（也就是已经减去了的点）
    }

    cout << ans << endl;
}

signed main() {
    int _ = 1;
    while (_) {
        solve();
    }
    return 0;
}