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
    
    int m = n - k; // number of remaining elements
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long dmin = (long long)a[n-1] - a[0]; // use long long to avoid overflow
    for(int i = 0; i <= k; i++) {
        int j = i + m - 1;
        if (j < n) {
            long long d = (long long)a[j] - a[i];
            dmin = min(dmin, d);
        }
    }
    
    cout << dmin << endl;
    return 0;
}