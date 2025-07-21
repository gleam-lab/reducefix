#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_integers() {
    int size;
    cin >> size;
    vector<int> integers(size);
    for (int &i : integers) {
        cin >> i;
    }
    return integers;
}

int solve() {
    int n = 1;
    cin >> n;
    vector<int> toy_sizes = read_integers();
    vector<int> box_sizes = read_integers();

    // Pair up toys and box sizes
    vector<pair<int, int>> toys_boxes;
    for (int i = 0; i < n; ++i) {
        toys_boxes.emplace_back(toy_sizes[i], box_sizes[i]);
    }

    // Sort toys and box sizes in descending order
    sort(toys_boxes.begin(), toys_boxes.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.first > b.first || (a.first == b.first && a.second > b.second);
         });

    // Determine the minimum box size needed
    int min_box_size = -1;
    for (const auto &pair : toys_boxes) {
        if (pair.second <= pair.first) {
            min_box_size = max(min_box_size, pair.second);
        } else {
            // If we find a toy that cannot fit into the largest box we considered so far,
            // we need to purchase a new box of at least the toy's size.
            min_box_size = max(min_box_size, pair.first);
        }
    }

    // Output the minimum box size needed or -1 if no valid configuration exists
    cout << (min_box_size == -1 ? -1 : min_box_size) << endl;
    return 0;
}

int main() {
    solve();
    return 0;
}