#include <bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 100005;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }

vector<int> a;

bool check(int mid, int x, int k) {
    auto it = lower_bound(a.begin(), a.end(), x - mid);
    int count = 0;
    while (it != a.end() && *it <= x + mid) {
        if (*it == x) continue;
        if (++count == k) return true;
        ++it;
    }
    return false;
}

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        int l = 0, r = 1e8;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, x, k)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}