#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    // We sort both the toy sizes and box sizes in descending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    
    // We need to check if there is a box size that can fit all toys
    bool isPossible = true;
    for (int i = 0; i < n - 1; i++) {
        // If a toy is larger than the next smallest box, then we need to buy a larger box
        if (va[i] > vb[i + 1]) {
            isPossible = false;
            break;
        }
        // We need at least the size of the largest toy to fit all toys
        int x = va[i];
        // Check if this box size x can fit the remaining toys
        for (int j = i + 1; j < n; j++) {
            if (va[j] > x) {
                cout << x + 1 << endl;
                return 0;
            }
        }
    }
    
    // If it's not possible to fit all toys with the current boxes and at least one new box,
    // then we need to increase the box size to the size of the largest toy
    if (isPossible) {
        cout << va[0] + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}