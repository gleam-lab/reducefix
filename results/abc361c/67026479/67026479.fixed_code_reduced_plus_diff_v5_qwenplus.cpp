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
    
    int m = n - k;
    if(m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long dmin = (long long)a[m-1] - a[0];
    for(int i = 1; i <= k; i++) {
        long long d = (long long)a[i + m - 1] - a[i];
        dmin = min(dmin, d);
    }
    
    cout << dmin << endl;
    return 0;
}