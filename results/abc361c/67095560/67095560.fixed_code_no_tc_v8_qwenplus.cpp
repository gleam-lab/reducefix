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
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Try all possible contiguous subarrays of length (n - k)
    int min_diff = a[n-1] - a[0];
    int len = n - k;
    
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}