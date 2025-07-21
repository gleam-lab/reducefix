#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>(n);
    vector<int>ç®±å­(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> ç©[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> ç®±å­[i];
    }

    // Sort the toy sizes in ascending order
    sort(.begin(), ç©.end());
    // Sort the box sizes in descending order
    sort(ç®±å­.begin(), ç®±å­.end(), greater<int>());

    int nextToyIndex = 0;  // Index for the next toy that needs to be placed in a box
    int boxIndex = 0;      // Index for the next box to check
    long long minBoxSize = LLONG_MAX;  // Initialize with the maximum possible size

    // Iterate over the boxes to determine the smallest box size we need to buy
    while (boxIndex < n - 1 && nextToyIndex < n) {
        // If the current toy can be placed in the current box
        if ([nextToyIndex] <= ç®±å­[boxIndex]) {
            ++nextToyIndex;  // Move to the next toy
        }
        // Update the minimum box size
        minBoxSize = min(minBoxSize, ç®±å­[boxIndex + 1]);
        ++boxIndex;  // Move to the next box
    }

    // If we have placed all toys, print the minimum box size needed
    if (nextToyIndex == n) {
        cout << minBoxSize << endl;
    } else {
        // If there are toys that cannot be placed, print -1
        cout << -1 << endl;
    }

    return 0;
}