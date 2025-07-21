#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in descending order
    sort(a.rbegin(), a.rend());

    // Calculate prefix sum array for the sorted votes
    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll target = a[i] + 1 + (m - 1) * (a[i] + 1);
        if(target <= k) {
            ans[i] = target - a[i] - 1;
        } else {
            ll rem = k - pref[i];
            if(rem >= a[i]) {
                ans[i] = rem - a[i];
            }
        }
    }

    for(auto x : ans) cout << x << " ";
    return 0;
}