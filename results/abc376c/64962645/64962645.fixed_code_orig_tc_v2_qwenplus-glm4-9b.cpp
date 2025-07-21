#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n - 1; ++i) cin >> vb[i];

    // Sort toy sizes in descending order and box sizes in ascending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());

    // Check if all toys fit in the existing boxes
    for (int i = 0; i < n; ++i) {
        if (va[i] > vb[i]) {
            // Calculate the minimum box size needed to fit the current toy
            int minBoxSize = va[i] + 1;
            // Check if this box size already exists among the boxes
            if (find(vb.begin(), vb.end(), minBoxSize) != vb.end()) {
                cout << minBoxSize << endl;
                return 0;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // If all toys fit in the existing boxes, the problem statement is unclear
    // about what to do. Assuming we need the minimum box size to fit the smallest toy,
    // we can not find a minimum box size because all toys are already fitting.
    // Thus, return `-1` as the answer.
    cout << -1 << endl;
    return 0;
}