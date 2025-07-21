#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> toys(N);
    vector<int> boxes(N - 1);

    // Reading toy sizes and sorting
    for (int i = 0; i < N; ++i) {
        cin >> toys[i];
    }
    sort(toys.begin(), toys.end());

    // Reading box sizes and sorting
    for (int i = 0; i < N - 1; ++i) {
        cin >> boxes[i];
    }
    sort(boxes.begin(), boxes.end());

    // If the largest toy is smaller than the smallest box, no box is needed
    if (toys[N - 1] < boxes[0]) {
        cout << 1 << endl;
        return 0;
    }

    // Find the size of the smallest box that can accommodate the largest toy
    int minBoxSize = 0;
    for (int box : boxes) {
        if (toys[N - 1] <= box) {
            minBoxSize = box;
            break;
        }
        minBoxSize++;
    }

    // If we have already found a box that can accommodate the largest toy, print it
    if (minBoxSize > 0 && toys[N - 1] <= boxes[minBoxSize - 1]) {
        cout << minBoxSize << endl;
    } else {
        // If no box can accommodate the largest toy, we need to buy a new box
        int minBoxSize = toys[N - 1] + 1;
        cout << minBoxSize << endl;
    }

    return 0;
}