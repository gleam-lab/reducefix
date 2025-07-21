#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canWin(vector<ll>& a, ll k, ll x, int m) {
    int n = a.size();
    vector<ll> b(a);
    for (int i = 0; i < n; ++i) b[i] += x;
    sort(b.begin(), b.end());
    
    for (int i = 0; i < n; ++i) {
        if (b[i] <= b[n - 1 - m]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] > k / (n - m)) {
            ans[i] = 0;
            continue;
        }
        
        ll l = 0, r = k;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (canWin(a, k - mid, mid, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans[i] = l;
    }
    
    for (auto i : ans) cout << i << ' ';
    return 0;
}