#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, cnt, ans, q;
int a[N], f[N], sum[N];
bool vis[N];
bool check(int p, int dx, int k) {
    int ln = lower_bound(a + 1, a + n + 1, p - dx) - a;
    int rn = upper_bound(a + 1, a + n + 1, p + dx) - a;
    return rn - ln >= k;
}
int findans(int pos, int k) {
    int l = 0, r = 2e9; // Adjusted range to handle large distances
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(pos, mid, k)) r = mid;
        else l = mid + 1;
    }
    return l;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Added this line to improve performance

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << endl;
    }

    return 0;
}