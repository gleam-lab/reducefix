#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

bool check(ll mid) {
    vector<ll> boxes(mid + 1, 0);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i < mid; ++i) pq.push(b[i]);
    
    for (ll i = 0; i < N - 1; ++i) {
        while (!pq.empty() && pq.top() < a[i]) pq.pop();
        if (pq.empty()) return false;
        pq.pop();
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];
    sort(b, b + n - 1);

    ll lo = 0, hi = n, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}