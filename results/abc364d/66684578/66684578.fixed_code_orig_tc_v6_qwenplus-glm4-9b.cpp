#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < q; j++) {
        int b, k;
        cin >> b >> k;

        // Collect distances for each point A_i to B_j and sort them
        vector<int> distances;
        for (int i = 0; i < n; i++) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());

        // Output the k-th closest distance
        cout << distances[k - 1] << endl;
    }

    return 0;
}