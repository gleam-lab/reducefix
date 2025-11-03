#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int m = n - k; // number of remaining elements
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    return 0;
}