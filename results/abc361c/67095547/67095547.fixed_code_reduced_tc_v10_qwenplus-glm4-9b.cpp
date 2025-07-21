#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate the minimum difference by removing either smallest or largest K elements
    int min_diff = max(a[0] - a[k], a[n-k-1] - a[n-1]);
    
    cout << min_diff << endl;
    
    return 0;
}