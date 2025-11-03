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
    // The remaining sequence must be contiguous in the sorted array to minimize range.
    int min_range = a[n-1] - a[0];
    
    // Try all possible contiguous subarrays of length (n - k)
    for (int i = 0; i + (n - k) - 1 < n; i++) {
        int j = i + (n - k) - 1;
        min_range = min(min_range, a[j] - a[i]);
    }
    
    cout << min_range;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}