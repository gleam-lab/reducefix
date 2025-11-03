#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x,y) x = min(x,y)
using ll = long long;
const int INF = 1001001001;

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
    // The remaining sequence B must be a contiguous subsequence of the sorted array
    // to minimize max - min. So we try all possible contiguous subarrays of length (n-k).
    
    int len = n - k;
    if (len == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = a[len - 1] - a[0]; // First window
    for (int i = 1; i + len - 1 < n; i++) {
        chmin(ans, a[i + len - 1] - a[i]);
    }
    
    cout << ans << endl;
}