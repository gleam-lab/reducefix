#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 2e5 + 1;
const long long INF = 1e18;
long long a[MAX_N];

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<long long, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i;  // Store original index to output the correct point later
    }

    // Sorting the points for binary search
    sort(A.begin(), A.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first < b.first;
    });

    // Processing each query
    for (int i = 0; i < q; ++i) {
        long long b, kj;
        cin >> b >> kj;

        // Binary search for the kj-th closest point
        long long low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            long long distance = abs(A[mid].first - b);
            if (mid < kj - 1 || (mid > kj - 1 && abs(A[mid - 1].first - b) > distance)) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        // Output the distance to the kj-th closest point
        long long distance = abs(A[low].first - b);
        cout << distance << endl;
    }

    return 0;
}