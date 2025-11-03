#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x, y) x = min(x, y)
using ll = long long;

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
    
    // We are removing exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // Initial case: remove last k elements
    
    // Try all possible contiguous segments of length 'keep'
    // The idea is that the optimal remaining sequence is always a contiguous segment in the sorted array
    for (int i = 1; i + keep - 1 < n; i++) {
        chmin(ans, a[i + keep - 1] - a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}