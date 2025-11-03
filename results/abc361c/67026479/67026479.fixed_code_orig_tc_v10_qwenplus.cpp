#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int m = n - k; // size of remaining sequence
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long dmin = 1e18; // Use larger initial value to avoid issues
    
    // Try all possible contiguous segments of length m in sorted array
    for (int i = 0; i <= n - m; i++) {
        long long d = (long long)a[i + m - 1] - a[i];
        dmin = min(dmin, d);
    }
    
    cout << dmin << endl;
    return 0;
}