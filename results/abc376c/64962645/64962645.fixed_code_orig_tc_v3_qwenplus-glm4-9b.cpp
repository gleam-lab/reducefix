#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);

    // Read toy sizes and existing box sizes.
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    // Sort the toy sizes in descending order.
    sort(va.begin(), va.end(), greater<int>());

    // Find the minimum box size from the existing boxes.
    int min_box_size = *min_element(vb.begin(), vb.end());

    // Check if each toy can be placed in an existing box.
    for (int toy : va) {
        if (toy > min_box_size) {
            // If the toy's size is larger than the smallest box, update min_box_size.
            min_box_size = toy;
        }
    }

    // If no new box needs to be purchased, the answer is the smallest of the smallest box size and the largest toy size.
    if (min_box_size == *vb.begin()) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;  // No valid box size found.
    }

    return 0;
}