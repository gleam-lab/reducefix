#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 200000; // Adjusted according to problem constraints

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    vector<int> count(MAXN + 1, 0);

    // Preprocess points to create the frequency array
    for (int i = 0; i < n; ++i) {
        ++count[points[i] + 1]; // +1 because we want to count inclusive
    }
    for (int i = 1; i < MAXN; ++i) {
        count[i] += count[i - 1];
    }

    vector<int> distances(q);
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = MAXN;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            // Check if there are at least k points within distance `mid`
            int pos = b + mid;
            if (pos <= MAXN && count[pos] >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        // Calculate the distance to the k-th closest point
        int kthPointIndex = b + left;
        int kthPoint = points[lower_bound(points.begin(), points.end(), kthPointIndex) - points.begin()];
        distances[j] = abs(kthPoint - b);
    }

    // Output the results
    for (int i = 0; i < q; ++i) {
        cout << distances[i] << endl;
    }

    return 0;
}