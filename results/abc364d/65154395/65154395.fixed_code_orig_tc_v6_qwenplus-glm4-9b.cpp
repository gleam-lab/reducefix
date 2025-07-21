#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        
        // Binary search for the k-th closest point A_i to B_j
        int left = 1, right = n, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int dist = abs(b - a[mid]);
            
            // Find the distance to the k-th closest point
            if (dist <= abs(b - a[mid - 1])) {
                if (mid == 1 || dist <= abs(b - a[mid + 1])) {
                    ans = dist;
                    break;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}