#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = -1;
    for(ll i = 0, j = 0; i < n && j < n-1;) {
        if(a[i] <= b[j]) {
            i++;
        } else {
            ans = max(ans, b[j]);
            j++;
        }
    }
    
    // Check if there's any remaining toy which couldn't fit in any box
    while(i < n) {
        if(ans == -1 || a[i] > ans) {
            break;
        }
        i++;
    }

    if(i == n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}