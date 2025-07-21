#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<pair<long long, int>> queries(q);

    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {abs(a[k] - b), k};
    }

    sort(queries.begin(), queries.end());

    for (auto& q : queries) {
        // Binary search to find the k-th closest point to b_j
        int low = 0, high = n;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (abs(a[mid] - q.second) <= abs(a[mid + 1] - q.second)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        long long distance = abs(a[low] - q.second);
        cout << distance << endl;
    }

    return 0;
}