#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;
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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The remaining elements must be contiguous in the sorted array to minimize range.
    // Try all possible contiguous subarrays of length (n - k)
    int ans = a[n - 1] - a[0]; // worst case: keep everything
    int len = n - k;
    
    for (int i = 0; i + len - 1 < n; i++) {
        chmin(ans, a[i + len - 1] - a[i]);
    }
    
    cout << ans << endl;
}