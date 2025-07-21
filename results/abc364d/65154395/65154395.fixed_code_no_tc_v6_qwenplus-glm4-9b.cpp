#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(2 * INF + 1, 0);
    vector<int> b;

    // Read all coordinates and accumulate them in array 'a'
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x + INF]++; // Offset by INF to handle negative coordinates
    }

    // Read all queries
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        b.emplace_back(x + INF); // Offset by INF to handle negative coordinates
    }

    // Prepare to output the results
    vector<int> results(q);

    // For each query, find the k-th closest point from A to B
    for (int i = 0, j = 0; i < q; ++i) {
        // Use a pointer to iterate through the prefix sum array 'a'
        while (j < 2 * INF && a[j] < k) {
            j++;
        }
        // Output the distance of the k-th closest point
        results[i] = j - INF; // Unoffset the result
    }

    // Print all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}