#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

// Function to binary search the kth smallest distance
ll binary_search(vector<ll>& distances, int k) {
    ll low = 0, high = 1e9;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        int count = 0;
        for (auto dist : distances) {
            if (dist <= mid) {
                count++;
            } else {
                break;
            }
        }
        if (count >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> A(n), B(q);
    vector<int> K(q);

    // Read coordinates of points A
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Read coordinates of points B and their corresponding k values
    for (int i = 0; i < q; ++i) {
        cin >> B[i] >> K[i];
    }

    // Sort the coordinates of points A
    sort(A.begin(), A.end());

    // For each query
    for (int i = 0; i < q; ++i) {
        vector<ll> distances;
        
        // Calculate distances from B[i] to all points in A
        for (int j = 0; j < n; ++j) {
            distances.push_back(abs(B[i] - A[j]));
        }

        // Sort the calculated distances
        sort(distances.begin(), distances.end());

        // Binary search for the k-th smallest distance
        ll result = binary_search(distances, K[i]);
        
        // Print the result
        cout << result << "\n";
    }

    return 0;
}