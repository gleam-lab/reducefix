#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x, y) x = min(x, y)
using ll = long long;
const int INF = 1e9;

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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The remaining elements must be contiguous in the sorted array to minimize (max - min).
    // Try all possible contiguous subarrays of length (n - k)
    
    int ans = INF;
    int keep = n - k;
    
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        chmin(ans, a[j] - a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}