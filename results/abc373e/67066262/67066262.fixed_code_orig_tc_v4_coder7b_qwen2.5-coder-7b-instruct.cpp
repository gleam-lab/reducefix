#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
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
    
    vector<ll> ans(n, -1);
    
    // Calculate the minimum additional votes needed for each candidate
    for(int i = 0; i < n; ++i) {
        if(i > 0) {
            // Need more votes than the second highest
            if(k >= a[i] - a[i + 1]) {
                ans[i] = a[i] - a[i + 1];
            } else {
                ans[i] = -1;
            }
        } else {
            // No other candidate to compare with
            if(k >= 1) {
                ans[i] = 1;
            } else {
                ans[i] = -1;
            }
        }
    }
    
    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}