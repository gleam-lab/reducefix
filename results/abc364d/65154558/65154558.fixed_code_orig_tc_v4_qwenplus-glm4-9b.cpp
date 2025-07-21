#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using dist_t = pair<int, int>; // pair of distance, index of A_i

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<dist_t> distances;

    // Reading and storing the points A_i
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Priority queue to maintain the distances in sorted order
    priority_queue<dist_t, vector<dist_t>, greater<dist_t>> pq;

    // Process each query for B_j
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        int sum = 0, idx = -1;

        // Calculate the sum of distances from B_j to A_i and keep track of the k-th smallest distance
        for (int i = 0; i < n; ++i) {
            int distance = abs(a[i] - b);
            if (sum < k) {
                sum += distance;
            } else if (sum == k) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            // If something goes wrong, print 0 as a fallback
            cout << 0 << endl;
        } else {
            // Output the k-th smallest distance
            cout << distances[k - 1].first << endl;
        }
    }

    return 0;
}