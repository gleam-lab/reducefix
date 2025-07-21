#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to check if a candidate can win with at least x additional votes
bool check(ll x, vector<ll>& votes, int m) {
    ll max_votes = *max_element(votes.begin(), votes.end());
    ll needed = max(max_votes + 1 - votes[m], 0LL);
    return needed <= x;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    k -= sum;

    // Create a sorted list of votes received by each candidate
    for(int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);

    // Calculate prefix sums for quick range queries
    for(int i = 1; i <= n; ++i) c[i] = c[i - 1] + b[i];

    for(int i = 1; i <= n; ++i) {
        // Binary search for the minimum number of additional votes needed
        ll l = 0, r = k + 1;
        while(l < r) {
            ll mid = l + (r - l) / 2;
            if(check(mid, b, n - i)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // Check if we found a valid solution within the limit
        if(l <= k && check(l, b, n - i)) {
            cout << l << " ";
        } else {
            cout << "-1 ";
        }
    }

    return 0;
}