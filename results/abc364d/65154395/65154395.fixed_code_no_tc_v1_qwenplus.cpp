#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> a;
int n, q;

void solve() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}