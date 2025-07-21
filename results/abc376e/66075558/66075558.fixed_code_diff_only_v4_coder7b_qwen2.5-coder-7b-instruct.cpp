#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s, q;
pair<int, int>a[N], b[N];

bool cmp(const pair<int, int>& pa, const pair<int, int>& pb) {
    return pa.first == pb.first ? a[pa.second] > a[pb.second] : pa.first < pb.first;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, greater<pair<int, int>>());

        ans = inf;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, (a[i].first * b[i].first));
        }
        cout << ans << endl;
    }
    return 0;
}