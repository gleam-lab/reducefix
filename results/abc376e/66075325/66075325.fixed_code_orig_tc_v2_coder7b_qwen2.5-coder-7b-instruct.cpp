#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define int long long
#define lowbit(x) x & (-x)
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int n, k, t;
int ans;
pair<int, int> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += b[i].first;
            pq.push(b[i].first);
        }

        ans = inf;
        for (int i = k; i <= n; i++) {
            ans = min(ans, (long long)a[i].first * (sum));
            sum += b[i].first - pq.top();
            pq.pop();
            pq.push(b[i].first);
        }

        ans = min(ans, (long long)a[n].first * (sum));

        cout << ans << endl;
    }
    return 0;
}