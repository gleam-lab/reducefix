#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        int left = lower_bound(a.begin(), a.end(), b) - a.begin();
        int right = left + k - 1;
        
        if (right >= n) {
            // If the k-th closest point is beyond the last point, the distance is
            // the difference between the farthest point and b
            cout << (a[n-1] - b) * 2 << endl;
        } else {
            // Otherwise, calculate the distance between the k-th closest point and b
            cout << (a[right] - b) << endl;
        }
    }
    
    return 0;
}