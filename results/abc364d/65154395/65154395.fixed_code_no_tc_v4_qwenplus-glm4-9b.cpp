#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 200005;
int a[N], cnt[N], ans;
#define lowbit(x) (x & (-x))

void update(int x, int val) {
    for (; x <= N; x += lowbit(x)) cnt[x] += val;
}

int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += cnt[x];
    return res;
}

int solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int b, k; cin >> b >> k;
        int l = -1e8, r = 1e8;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            int count = query(mid - b);
            if (count >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans = abs(b - l);
    }
    cout << ans << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T = 1; //cin >> T;
    for (int t = 0; t < T; t++) solve();
    return 0;
}