#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Find the largest box size that can fit all toys
    int minBoxSize = INT_MAX;
    for(int i = 0; i < n-1; ++i) {
        if(b[i] >= a[n-1]) {
            minBoxSize = min(minBoxSize, b[i]);
        }
    }
    
    // If no suitable box found, print -1
    if(minBoxSize == INT_MAX) {
        cout << "-1";
    } else {
        cout << minBoxSize;
    }
    
    return 0;
}