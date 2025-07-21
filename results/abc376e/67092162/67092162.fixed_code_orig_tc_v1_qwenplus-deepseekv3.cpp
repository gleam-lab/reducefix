#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i].second;
        }

        sort(p, p + n);

        priority_queue<int> q;
        long long sum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
            q.push(p[i].second);
        }
        ans = p[k-1].first * sum;

        for (int i = k; i < n; ++i) {
            if (p[i].second < q.top()) {
                sum -= q.top();
                q.pop();
                sum += p[i].second;
                q.push(p[i].second);
            }
            ans = min(ans, p[i].first * sum);
        }

        cout << ans << "\n";
    }
    return 0;
}