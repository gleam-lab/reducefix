#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        // Calculate the distance between B_j and all A_i
        vector<long long> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(b - a[i]);
        }
        // Sort the distances to find the k-th closest
        sort(distances.begin(), distances.end());
        // Output the k-th closest distance
        cout << distances[k - 1] << endl;
    }

    return 0;
}