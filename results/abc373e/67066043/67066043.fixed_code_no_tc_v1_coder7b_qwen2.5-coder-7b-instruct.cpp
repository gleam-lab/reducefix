#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    
    // Calculate the maximum votes needed for a candidate to win
    vector<ll> max_votes(n, 0);
    for(int i = 0; i < n; ++i) {
        max_votes[i] = (k / (n - m)) + (k % (n - m) > i);
    }
    
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i] + max_votes[i] >= k / (n - m)) {
            ans[i] = 0;
        } else {
            ans[i] = max_votes[i] - (a[i] - max_votes[i]);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}