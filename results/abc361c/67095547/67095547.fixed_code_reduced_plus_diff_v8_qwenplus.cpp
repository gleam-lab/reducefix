#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second 
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define repn(i,x) for(int i=1;i<=(int)(x);i++)
#define repo(i,x) for(int i=x-1;i>=0;i--)
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    sort(all(a));
    
    // We are removing exactly K elements
    // So we keep (n - k) elements
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // initial candidate: remove last k
    
    // Try all possible contiguous subarrays of length (n-k)
    // That means we remove some from left and rest from right
    for(int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        int remaining_start = left_removed;
        int remaining_end = n - 1 - right_removed;
        
        if (remaining_start <= remaining_end) {
            ans = min(ans, a[remaining_end] - a[remaining_start]);
        }
    }
    
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}