#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    // We need to remove exactly K elements, leaving N-K elements.
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Try all possible contiguous subarrays of length (n-k)
    int ans = a[n-k-1] - a[0]; // First window: [0, n-k-1]
    
    for (int i = 1; i + (n-k) <= n; i++) {
        chmin(ans, a[i + (n-k) - 1] - a[i]);
    }
    
    cout << ans << endl;
}