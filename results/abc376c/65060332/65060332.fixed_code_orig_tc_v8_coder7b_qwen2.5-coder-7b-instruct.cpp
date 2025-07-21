#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] <= x && b[j] >= a[i]) {
            i++;
            j++;
        } else if(a[i] > x) {
            return false;
        } else {
            j++;
        }
    }
    return i == a.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];

    ll lo = 0, hi = 1e9 + 1, ans = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(a, b, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}