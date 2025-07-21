#include <bits/stdc++.h>
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
    // We need to find the smallest box size x such that all toys can fit into the boxes
    // including the newly purchased box of size x.
    // For each toy, we need to ensure that there exists a box of size >= toy's size.
    // We will iterate over each toy and find the smallest box size that can fit the toy.
    
    int box_size = 0;
    for (int i = 0; i < n; i++) {
        // For each toy, find the smallest box that can fit it by checking from the smallest box backwards.
        for (int j = n - 2; j >= 0; j--) {
            if (vb[j] >= va[i]) {
                box_size = vb[j];
                break;
            }
        }
        // After placing the toy, update the box size for the next toy.
        // If the current toy's size is greater than the box_size, we need to find a larger box or a new box.
        if (va[i] > box_size) {
            box_size = va[i];
        }
    }
    // The box_size is the minimum size of the box that can fit all toys.
    cout << box_size << endl;
}