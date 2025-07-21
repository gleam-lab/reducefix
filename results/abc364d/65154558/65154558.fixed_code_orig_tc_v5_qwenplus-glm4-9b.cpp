#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    int b, k, index;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<Query> queries;
    queries.reserve(q);

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.push_back({b, k, i});
    }

    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.b < b.b;
    });

    // Sort the points A_i
    sort(a.begin(), a.end());

    // Calculate the distances and store them in a new vector
    vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        distances[i] = abs(a[i] - queries[0].b);
    }

    // Answer the queries
    for (int i = 0; i < q; ++i) {
        // Binary search for the k-th closest point
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (distances[mid] <= queries[i].k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        // Output the distance for the query
        cout << distances[left] << endl;
    }

    return 0;
}