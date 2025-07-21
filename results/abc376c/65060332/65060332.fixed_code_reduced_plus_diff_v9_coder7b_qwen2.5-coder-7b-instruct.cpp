#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, ll mid) {
    int n = a.size();
    vector<int> pos(n, -1);
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        auto it = upper_bound(b.begin(), b.end(), mid - a[i] + 1);
        if(it == b.end()) return false;
        pos[i] = it - b.begin();
        b.erase(it);
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    ll l = 0, r = 1e18;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(check(a, b, mid)) r = mid;
        else l = mid + 1;
    }

    if(l > 1e9) cout << -1 << endl;
    else cout << l << endl;
    return 0;
}