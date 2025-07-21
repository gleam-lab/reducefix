#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200000 + 1;  // Adjusted for a_i and b_j values to fit within the array bounds

int a[N], b[N];  // a to store the count of points to the left, b to store the coordinates

bool check(int mid, int x, int y) {
    // Adjust the indices to the left half of the array
    int leftIdx = x - mid - 1;
    int rightIdx = x + mid;
    
    // If the point goes out of the left boundary, start from 0
    leftIdx = max(0, leftIdx);
    // If the point goes out of the right boundary, end at N-1
    rightIdx = min(N - 1, rightIdx);
    
    // Return true if the distance between the farthest point on the left and the nearest point on the right is at least y
    return b[rightIdx] - b[leftIdx] >= y;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) cin >> b[i];
    
    // Initialize the array with zeros
    memset(a, 0, sizeof(a));
    
    // Calculate the number of points less than each point a_i
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (i - a[i - 1]);
    }
    
    // Process each query
    for (int i = 0; i < q; i++) {
        int x = b[i];
        int k = n - b[i];
        
        // Perform binary search to find the k-th closest point to x
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid, x, k)) l = mid;
            else r = mid - 1;
        }
        
        // Output the distance between the k-th closest point and x
        cout << k << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}