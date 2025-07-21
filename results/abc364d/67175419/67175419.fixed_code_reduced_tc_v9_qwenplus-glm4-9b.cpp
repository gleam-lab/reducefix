#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while(q--) {
        int b, k;
        cin >> b >> k;
        
        // Sort the array `a` based on the distance from point `b`
        sort(a.begin(), a.end(), [&](int x, int y) {
            return abs(x - b) < abs(y - b);
        });
        
        // The k-th closest point's value is the k-th element in the sorted array
        int closest = a[k - 1];
        
        // Calculate and print the distance
        cout << abs(closest - b) << endl;
    }
    
    return 0;
}