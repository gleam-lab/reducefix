#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5e5 + 5; // Maximum points A_i and queries B_j

int A[N]; // Array to store the frequency of each point after shifting
int freq[401]; // Frequency array to count occurrences

int main() {
    int n, q;
    cin >> n >> q;

    // Read the coordinates of points A_i
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Shift the points A_i by (N-5)/2 and count frequencies
    for (int i = 0; i < n; ++i) {
        A[i] += (n - 5) / 2;
        freq[A[i]]++;
    }

    // Compute prefix sums to get the cumulative frequency
    for (int i = 1; i <= 400; ++i) {
        freq[i] += freq[i - 1];
    }

    // Process each query
    while (q--) {
        int x, k;
        cin >> x >> k;

        // Binary search to find the smallest distance such that there are at least k points within that distance
        int l = 0, r = 2e8; // Search range for distance
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int num = freq[min(400, mid + x)] - freq[max(0, x - mid)];
            if (num >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }

        // Output the result for this query
        cout << r << endl;
    }

    return 0;
}