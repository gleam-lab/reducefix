#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s;
pair<int, int> a[N], b[N];

signed main() {
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
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        priority_queue<int, vector<int>, greater<int>> pq;
        s = 0;
        for (int i = 1; i <= k; i++) {
            pq.push(b[i].first);
            s += b[i].first;
        }

        ans = s * a[k].first;
        for (int i = k + 1; i <= n; i++) {
            s += b[i].first - pq.top();
            pq.pop();
            pq.push(b[i].first);
            ans = min(ans, s * a[i].first);
        }

        cout << ans << endl;
    }
    return 0;
}