#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<pair<int, int>> sa(n + 1);
        for (int i = 1; i <= n; i++) {
            sa[i] = {a[i], b[i]};
        }

        // Sort pairs by A[i], then by B[i] if A[i] is the same
        sort(sa.begin() + 1, sa.begin() + n + 1, [](const pair<int, int>& left, const pair<int, int>& right) {
            return left.first < right.first || (left.first == right.first && left.second > right.second);
        });

        long long res = INF;
        long long sum = 0;
        priority_queue<long long> q;
        for (int i = 1; i <= n; i++) {
            sum += sa[i].se;
            if (q.size() > k - 1) {
                sum -= q.top();
                q.pop();
            }
            q.push(sa[i].se);
            if (i >= k) {
                res = min(res, sa[i].fi * sum);
            }
        }

        cout << res << '\n';
    }

    return 0;
}