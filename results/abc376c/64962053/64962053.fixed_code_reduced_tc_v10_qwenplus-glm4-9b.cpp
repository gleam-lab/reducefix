#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);

    // Input toy sizes and box sizes
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    // Sort toy sizes and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // If the smallest toy is larger than the smallest box, it's impossible
    if (va[0] > vb[0]) {
        cout << -1 << endl;
        return 0;
    }

    // If the largest toy is larger than any box, find the minimum possible box size
    int minBoxSize = 0;
    for (int i = 0; i < n - 1; i++) {
        if (va[n - 1] > vb[i]) {
            minBoxSize = vb[i] + 1;
        }
    }

    // If no box can accommodate the largest toy, it's impossible
    if (minBoxSize == 0) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }

    return 0;
}