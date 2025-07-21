#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = LLONG_MAX;
    
    for(int i = 0; i < n-1; ++i) {
        ans = min(ans, max(a.back(), b[i]));
        a.pop_back();
    }
    
    ans = min(ans, a.back());
    
    cout << ans << '\n';
    
    return 0;
}