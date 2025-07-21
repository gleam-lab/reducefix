#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }

    // Pair each toy with its index and sort by size
    vector<pair<int, int>> toy_sizes;
    for (int i = 0; i < n; i++) {
        toy_sizes.emplace_back(A[i], i);
    }
    sort(toy_sizes.begin(), toy_sizes.end());

    // Sort boxes by size
    sort(B.begin(), B.end());

    // Check if toys can fit into boxes without additional purchases
    for (int i = 0; i < n; i++) {
        int toy_size = toy_sizes[i].first;
        int toy_box_index = toy_sizes[i].second;
        int required_box_size = toy_size + 1;
        // Find the smallest box that can fit the toy
        auto it = lower_bound(B.begin(), B.end(), required_box_size);
        // Check if the box is available before the toy is placed
        if (it != B.begin() && distance(it, B.begin()) <= toy_box_index) {
            // If no suitable box is found, we need to make a purchase
            bool possible = false;
            for (int b : B) {
                if (b >= required_box_size) {
                    cout << b << endl;
                    possible = true;
                    break;
                }
            }
            if (!possible) {
                cout << -1 << endl;
            }
            return 0;
        }
    }

    // If all toys fit without additional purchases
    cout << 1 << endl;
    return 0;
}