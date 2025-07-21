#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    sort(va.begin(), va.end(), greater<int>()); // Sort toys in descending order
    sort(vb.begin(), vb.end()); // Sort boxes in ascending order

    int x = -1; // Initialize x to -1
    for (int i = 0; i < n; i++) {
        bool canFit = false;
        for (int j = 0; j < n - 1; j++) {
            if (vb[j] >= va[i]) {
                canFit = true;
                break;
            }
        }
        if (!canFit) { // If the toy doesn't fit in any box
            x = va[i];
            break;
        }
    }

    cout << x << endl; // Output the minimum x
    return 0;
}