#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(x, val) memset(x, val, sizeof(x))

const int MAXN = 1000005;
long long n, m, ans;
unordered_set<long long> s, t, u, v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    rep(k, 1, m) {
        long long a, b; cin >> a >> b;
        s.insert(a), t.insert(b), u.insert(a + b), v.insert(a - b);
    }

    // Calculate the number of valid positions
    ans = n * n - s.size() * t.size();
    for (auto x : u) {
        long long tmp = n - abs(x);
        for (auto y : s) if (y - x >= 1 && y - x <= n) --tmp;
        for (auto y : t) if (x + y >= 1 && x + y <= n) --tmp;
        ans -= tmp;
    }
    for (auto x : v) {
        long long tmp = n - abs(x);
        for (auto y : s) if (x - y >= 1 && x - y <= n) --tmp;
        for (auto y : t) if (x + y >= 1 && x + y <= n) --tmp;
        ans -= tmp;
    }

    cout << ans << '\n';
    return 0;
}