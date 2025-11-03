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
    
    // We need to remove exactly K elements, leaving (n-k) elements
    // The remaining elements must be contiguous in the sorted array to minimize range
    // Try all possible contiguous segments of length (n-k)
    int ans = a[n-k-1] - a[0]; // initial value: take first (n-k) elements
    
    for (int i = 0; i <= k; i++) {
        // Remove i elements from left, (k-i) elements from right
        // So we keep elements from index i to index (n-1-(k-i)) = n-k+i-1
        int left_idx = i;
        int right_idx = n - k + i - 1;
        if (left_idx <= right_idx && right_idx < n) {
            chmin(ans, a[right_idx] - a[left_idx]);
        }
    }
    
    cout << ans << endl;
}