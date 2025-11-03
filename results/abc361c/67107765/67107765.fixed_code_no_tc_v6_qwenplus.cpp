#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x,y) x = min(x,y)
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
    
    // We need to remove exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // initial candidate: take first 'keep' elements
    
    // Try all possible contiguous segments of length 'keep'
    // The optimal remaining sequence is always a contiguous segment in sorted order
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        chmin(ans, a[j] - a[i]);
    }
    
    cout << ans << endl;
}