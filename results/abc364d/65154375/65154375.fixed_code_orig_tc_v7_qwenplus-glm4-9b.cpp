#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100010; // Maximum N + 1, as we use 0-based indexing.
int points[MAX_N]; // Points on the number line.

int main() {
    int N, Q, b, k;
    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        cin >> points[i];
    }

    for (int q = 0; q < Q; ++q) {
        cin >> b >> k;
        
        // Binary search to find the k-th closest point to b
        int left = 0, right = N - 1, ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if the point at index mid is a valid candidate
            if (abs(points[mid] - b) <= abs(points[mid] - (b - k)) && abs(points[mid] - b) <= abs(points[mid] - (b + k))) {
                ans = points[mid];
                left = mid + 1; // Try to find a closer point on the right side
            } else if (abs(points[mid] - b) < abs(points[mid] - (b - k))) {
                right = mid - 1; // Try to find a closer point on the left side
            } else {
                left = mid + 1; // Continue searching on the right side
            }
        }
        
        // Output the distance
        cout << abs(ans - b) << endl;
    }

    return 0;
}