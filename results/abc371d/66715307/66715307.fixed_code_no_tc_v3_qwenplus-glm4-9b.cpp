#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), a(n + 1);
    
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    a[1] = p[1];
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        
        // Find the smallest index where x[index] >= l
        while (l1 < r1) {
            int mid = (l1 + r1) / 2;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        
        // Find the largest index where x[index] <= r
        while (l2 < r2) {
            int mid = (l2 + r2 + 1) / 2;
            if (x[mid] <= r) l2 = mid;
            else r2 = mid - 1;
        }
        
        // Ensure the indices are within bounds and correctly represent the range
        if (l1 > r2 || l2 > r1) cout << "0\n"; // No valid indices within range
        else {
            // Calculate the sum of elements in the range [l1, r2] based on prefix sums
            cout << a[r2] - (l1 == 1 ? 0 : a[l1 - 1]) << endl;
        }
    }
    return 0;
}