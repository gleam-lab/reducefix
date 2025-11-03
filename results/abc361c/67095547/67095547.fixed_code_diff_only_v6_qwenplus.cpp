#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second 
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define repn(i,x) for(int i=1;i<=(int)(x);i++)
#define repo(i,x) for(int i=x-1;i>=0;i--)

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
    // Try all possible splits: remove i from left, k-i from right, for i in [0, k]
    int min_range = inf;
    for (int i = 0; i <= k; i++) {
        int left_remove = i;
        int right_remove = k - i;
        int remaining_left = left_remove;
        int remaining_right = n - 1 - right_remove;
        
        if (remaining_left <= remaining_right) {
            min_range = min(min_range, a[remaining_right] - a[remaining_left]);
        }
    }
    
    cout << min_range << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}