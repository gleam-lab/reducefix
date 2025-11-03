#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We need to remove exactly K elements
    // The remaining sequence will be a contiguous segment of length (n - k)
    // Try all possible contiguous segments of length (n - k) in the sorted array
    long long ans = 1e18;
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        ans = min(ans, (long long)a[j] - a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}