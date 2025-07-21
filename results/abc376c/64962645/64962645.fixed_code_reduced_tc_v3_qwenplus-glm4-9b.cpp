#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> toys(n);
    vector<int> boxes(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }

    // Sort the toy sizes in descending order and the box sizes in ascending order
    sort(toys.rbegin(), toys.rend());
    sort(boxes.rbegin(), boxes.rend());

    // Remove leading zeros in the boxes vector
    while (boxes.size() > 0 && boxes[0] == 0) {
        boxes.erase(boxes.begin());
    }

    // If there are no boxes, we need to find the smallest box that can fit the largest toy
    if (boxes.empty()) {
        cout << toys[0] << endl;
        return 0;
    }

    // Check if the smallest box can fit the largest toy
    if (toys[0] > boxes[0]) {
        cout << toys[0] << endl;
        return 0;
    }

    // Iterate through the boxes to find the smallest box that can fit the largest toy
    for (int i = 0; i < boxes.size(); i++) {
        if (toys[0] <= boxes[i]) {
            cout << boxes[i] << endl;
            return 0;
        }
    }

    // If no box can fit the largest toy, we need to find the minimum box size that can accommodate the next largest toy
    // This is done by comparing the smallest box size with the second largest toy size
    cout << boxes[0] << endl;

    return 0;
}