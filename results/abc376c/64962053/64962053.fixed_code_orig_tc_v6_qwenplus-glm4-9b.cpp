#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];
    sort(vb.begin(), vb.end()); // Sort the box sizes
    sort(va.begin(), va.end()); // Sort the toy sizes

    // Find the largest toy that no box can contain
    int maxToy = 0;
    for (int i = 0; i < n; i++) {
        bool canPlaceToyInBox = false;
        for (int j = 0; j < n - 1; j++) {
            if (vb[j] >= va[i]) {
                canPlaceToyInBox = true;
                break;
            }
        }
        if (!canPlaceToyInBox) {
            maxToy = va[i];
        }
    }

    // If no toy cannot be placed in any box, the minimum box size is the size of the largest toy
    if (maxToy == 0) {
        cout << va[n - 1] << endl;
    } else {
        cout << maxToy + 1 << endl;
    }

    return 0;
}