#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Calculate the total votes needed to ensure a candidate wins
    ll total_votes_needed = 0;
    for(int i = 0; i < n; i++) {
        total_votes_needed += max(0LL, a[i] - (k / (n - i - 1)));
    }
    
    // Check if it's even possible for any candidate to win
    if(total_votes_needed > k) {
        for(int i = 0; i < n; i++) cout << -1 << " ";
        return 0;
    }
    
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        if(a[i] + k / (n - i - 1) >= a[m]) {
            ans[i] = 0;
        } else {
            ans[i] = a[m] - (a[i] + k / (n - i - 1)) - 1;
        }
    }
    
    for(auto i : ans) cout << i << ' ';
    return 0;
}