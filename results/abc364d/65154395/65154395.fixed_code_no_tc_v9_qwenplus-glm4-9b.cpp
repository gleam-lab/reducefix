#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100000;

vector<int> a(N * 2 + 5);

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x + N]++; // Increment the count at x + N to shift the index
    }
    
    // Prefix sum to get the cumulative count
    for (int i = N + 1; i < N * 2 + 5; i++) {
        a[i] += a[i - 1];
    }
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = N;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            // Check if there are at least k points from b to a[2N - mid]
            if (a[b + N - mid] >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // Output the distance for the closest point
        cout << abs(b - (N - r)) << endl;
    }
    
    return 0;
}