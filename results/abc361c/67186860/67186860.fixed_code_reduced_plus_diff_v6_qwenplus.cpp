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
    
    int remaining = n - k;
    long long ans = 1e18;
    
    // Try all possible contiguous segments of length (n-k)
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        ans = min(ans, (long long)(a[j] - a[i]));
    }
    
    cout << ans << endl;
    return 0;
}