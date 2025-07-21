#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (auto& query : queries) {
        int b = query.first;
        int k = query.second;

        // Find the k-th closest point to b
        int left = -1, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            vector<int> distances(n);
            for (int j = 0; j < n; ++j) {
                distances[j] = abs(A[j] - b);
            }
            sort(distances.begin(), distances.end());
            if (distances[mid] == distances[k - 1]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        // Output the distance between the k-th closest point and b
        cout << abs(A[right] - b) << endl;
    }

    return 0;
}