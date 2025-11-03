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
    // The optimal way is to remove some prefix and/or suffix.
    // Try all possible combinations: remove i from left and (k-i) from right.
    int min_diff = a[n-1] - a[0]; // worst case: no removal benefit
    
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        
        if (left_removed + right_removed > n || (n - k) == 0) continue;
        
        int left_idx = left_removed;
        int right_idx = n - 1 - right_removed;
        
        if (left_idx <= right_idx) {
            min_diff = min(min_diff, a[right_idx] - a[left_idx]);
        }
    }
    
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}