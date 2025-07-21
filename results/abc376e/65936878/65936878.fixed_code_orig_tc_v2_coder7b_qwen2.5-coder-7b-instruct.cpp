#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].f;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i].f;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<int> pq;
        long long sum = 0, res = LLONG_MAX;

        for(int i = 0; i < k; i++) {
            pq.push(-b[i].f);
            sum += b[i].f;
        }

        for(int i = k; i < n; i++) {
            res = min(res, (long long)a[i].f * sum);
            sum -= b[pq.top()];
            pq.pop();
            pq.push(-b[i].f);
            sum += b[i].f;
        }

        res = min(res, (long long)a[n-1].f * sum);
        cout << res << '\n';
    }

    return 0;
}