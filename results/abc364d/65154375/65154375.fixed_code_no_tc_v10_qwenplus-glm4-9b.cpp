#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e5 + 5; // Adjusted based on the problem constraints

int a[N], b[N], k[N];

bool check(int mid, int idx) {
    // Calculate the number of points to the left and right of mid
    int left = upper_bound(a, a + k[idx], b[idx] - mid) - a;
    int right = lower_bound(a, a + k[idx], b[idx] + mid) - a;
    
    // The total number of points is k[idx], so the number of points within distance mid
    return left + (k[idx] - right) == k[idx];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
    }
    
    // Sort the points A to ensure we can use binary search
    sort(a, a + n);
    
    for (int i = 0; i < q; i++) {
        int x = b[i];
        int y = k[i];
        
        // Binary search for the minimum distance to the k-th closest point
        int l = 0, r = 2e8;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, i)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        // Output the result for each query
        cout << r << endl;
    }
    
    return 0;
}