#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        // Using a vector to store distances from A_i to B_j
        vector<int> distances(n + 1);
        for (int i = 1; i <= n; ++i) {
            distances[i] = abs(a[i] - b);
        }

        // Sorting distances to find the k-th closest point
        sort(distances.begin(), distances.end());

        // Output the distance of the k-th closest point
        cout << distances[k - 1] << endl;
    }

    return 0;
}