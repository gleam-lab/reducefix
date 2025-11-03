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
    
    int ans = a[n-1] - a[0];
    // We remove exactly K elements. So we keep (n-k) elements.
    // We can choose any contiguous segment of length (n-k) in the sorted array.
    // Because to minimize max-min, it's optimal to take consecutive elements.
    int len = n - k;
    for (int i = 0; i + len - 1 < n; i++) {
        ans = min(ans, a[i + len - 1] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}