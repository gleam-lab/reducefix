#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second 
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The optimal way is to remove some prefix and suffix such that total removed = k.
    // Try all possible splits: remove i from left, (k-i) from right, where i from 0 to k.
    int min_range = a[n-1] - a[0]; // worst case: no improvement
    
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        
        // Check if valid removal counts
        if (left_removed + right_removed > n || left_removed >= n || right_removed > n - left_removed)
            continue;
            
        // Remaining elements are from index [left_removed, n - right_removed - 1]
        int remaining_start = left_removed;
        int remaining_end = n - right_removed - 1;
        
        if (remaining_start <= remaining_end) {
            int current_range = a[remaining_end] - a[remaining_start];
            min_range = min(min_range, current_range);
        }
    }
    
    cout << min_range << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}