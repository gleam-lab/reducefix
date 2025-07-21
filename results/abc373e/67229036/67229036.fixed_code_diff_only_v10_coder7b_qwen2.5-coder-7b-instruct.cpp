#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 5;

ll n, m, k, sum, cnt, a[N], b[N], c[N];

// Function to check if candidate i can win with at least 'x' additional votes
bool check(ll x, ll y) {
    // Calculate the maximum number of votes candidate i can get
    ll max_votes_i_can_get = x + a[y];
    
    // Find the smallest index 'z' such that the total votes from top 'z' candidates > max_votes_i_can_get
    auto z = lower_bound(b + 1, b + 1 + n, max_votes_i_can_get + 1) - b - 1;
    
    // Check if there are enough candidates left to ensure i wins
    if (z < n - m) return false;
    
    // Calculate the required votes for candidate i to win considering the votes from other candidates
    ll required_votes = (max_votes_i_can_get + 1) * (z - n + m) - (c[z] - c[n - m - 1] - max(max_votes_i_can_get, b[n - m]));
    
    // Ensure the required votes do not exceed the remaining votes
    return required_votes <= k - y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k -= a[i];
        b[i] = a[i];
    }
    
    sort(b + 1, b + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        ll l = 0, r = k + 1;
        
        while (l < r) {
            ll mid = (l + r) / 2;
            
            if (check(mid, i)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if (l <= k) {
            cout << l << " ";
        } else {
            cout << "-1 ";
        }
    }
    
    return 0;
}