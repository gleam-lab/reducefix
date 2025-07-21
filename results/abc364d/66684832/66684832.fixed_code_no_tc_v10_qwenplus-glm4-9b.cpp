#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
vector<int> a;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        // Find the closest point A_i to B_j
        auto it = lower_bound(a.begin(), a.end(), b);
        int idx = distance(a.begin(), it);
        int closestDist = *it - b;
        
        // We need to find the k-th closest distance to B_j
        // Since we want the k-th smallest, we need to find the (k-th smallest index)
        vector<int> distances(n);
        for (int i = 0; i < n; i++) {
            distances[i] = abs(a[i] - b);
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << endl;
    }

    return 0;
}