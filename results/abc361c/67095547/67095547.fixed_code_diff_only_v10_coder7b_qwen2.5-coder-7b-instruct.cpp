#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mod 1e9+7
#define inf INT_MAX
#define all(v) v.begin(), v.end()

void solve(){
    int k,n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // Sort the array to facilitate finding min and max easily
    sort(a.begin(), a.end());

    // The optimal strategy is to either:
    // 1. Remove the smallest k elements
    // 2. Remove the largest k elements
    // This way, we minimize the difference between the max and min values of the resulting array
    int min_diff = min(a[n-k] - a[0], a[n-1] - a[k]);

    cout << min_diff;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}