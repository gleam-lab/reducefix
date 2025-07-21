#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> toys(N);
    vector<int> boxes(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> toys[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> boxes[i];
    }

    // Sort both the toys and the boxes for efficient searching
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // Try to place each toy in the smallest possible box
    int lastBox = 0; // Pointer for boxes array
    bool possible = true;

    for (int i = 0; i < N; i++) {
        // Move the box pointer to the box that can hold the current toy
        while (lastBox < N - 1 && boxes[lastBox] < toys[i]) {
            lastBox++;
        }

        // If the current toy cannot fit in any box, it's not possible to place all toys
        if (boxes[lastBox] < toys[i]) {
            possible = false;
            break;
        }

        // Move to the next toy
        lastBox++;
    }

    // If it's possible to place all toys without any additional box, print -1
    if (possible) {
        cout << -1 << endl;
    } else {
        // Otherwise, the minimum size of the box needed is the size of the largest toy
        // that cannot fit in any existing box
        cout << toys.back() << endl;
    }

    return 0;
}