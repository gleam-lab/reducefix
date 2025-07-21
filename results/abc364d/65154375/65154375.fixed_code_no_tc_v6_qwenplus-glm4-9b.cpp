#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> distance(n + 1);

    // Read all coordinates A_i
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // For each query, read the point B_j and the k_j-th closest index
    for (int j = 1; j <= q; ++j) {
        int b, k;
        cin >> b >> k;

        // Calculate the distance between each point A_i and B_j
        for (int i = 0; i <= n; ++i) {
            distance[i] = abs(a[i] - b);
        }

        // Sort the distances to find the k-th closest
        sort(distance.begin(), distance.begin() + n);

        // The k-th closest distance is the answer for this query
        cout << distance[k - 1] << endl;
    }

    return 0;
}