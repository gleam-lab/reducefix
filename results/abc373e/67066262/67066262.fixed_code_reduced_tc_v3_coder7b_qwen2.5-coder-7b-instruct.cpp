#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to binary search for the minimum number of votes needed
ll min_votes_needed(vector<ll>& a, int n, int m, ll k, int i) {
    ll l = -1, r = k + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll rid = upper_bound(a.begin(), a.end(), a[i] + mid) - a.begin();
        ll lid = n - m - (i >= n - m ? 1 : 0);
        ll cnt = 0;
        
        if (rid > lid) {
            cnt += (rid - lid) * (a[i] + mid) - (accumulate(a.begin() + lid, a.begin() + rid, 0LL));
        }
        
        if (lid <= i && i < rid) {
            cnt--;
        } else {
            cnt += mid;
        }
        
        if (cnt > k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Sort the array in descending order to facilitate the calculation
    sort(a.rbegin(), a.rend());
    
    vector<ll> ans(n, -1);
    
    for (int i = 0; i < n; ++i) {
        if (n - i - 1 < m) {
            continue; // If remaining candidates are fewer than m, no one can win
        }
        
        ans[i] = min_votes_needed(a, n, m, k, i);
    }
    
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}