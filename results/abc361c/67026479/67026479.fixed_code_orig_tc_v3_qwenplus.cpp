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
    long long dmin = (long long)1e18;
    
    for(int i = 0; i <= k; i++) {
        int j = i + m - 1;
        if(j >= n) break;
        long long d = (long long)a[j] - a[i];
        dmin = min(dmin, d);
    }
    
    cout << dmin << endl;
}