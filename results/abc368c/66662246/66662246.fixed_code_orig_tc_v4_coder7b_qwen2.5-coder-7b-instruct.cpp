#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq(a.begin(), a.end());

    while (!pq.empty()) {
        long long x = pq.top();
        pq.pop();

        if (x == 0) continue;

        ans++;
        if (ans % 3 == 0) {
            pq.push(x - 3);
        } else {
            pq.push(x - 1);
        }
    }

    cout << ans << endl;
}