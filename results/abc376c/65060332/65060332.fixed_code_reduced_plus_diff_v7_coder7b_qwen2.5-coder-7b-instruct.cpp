#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    
    // Read toy sizes
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read box sizes
    for(int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }

    // Sort toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;  // Index for boxes
    int minBoxSize = 0;  // Track the minimum box size needed
    
    for(int i = 0; i < n; ++i) {
        while(j < n-1 && b[j] < a[i]) {
            ++j;
        }
        
        if(j == n-1 && b[j] < a[i]) {
            cout << "-1" << endl;
            return 0;
        }
        
        minBoxSize = max(minBoxSize, a[i]);
        ++j;
    }
    
    cout << minBoxSize << endl;
    
    return 0;
}