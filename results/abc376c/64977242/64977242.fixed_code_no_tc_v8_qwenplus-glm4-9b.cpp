#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> toy_sizes, box_sizes;

int main() {
    cin >> N;
    toy_sizes.resize(N);
    box_sizes.resize(N-1);
    for (int i = 0; i < N; i++) cin >> toy_sizes[i];
    for (int i = 0; i < N - 1; i++) cin >> box_sizes[i];

    // Check if the largest toy can fit into an existing box
    sort(toy_sizes.begin(), toy_sizes.end(), greater<long long>());
    sort(box_sizes.begin(), box_sizes.end(), greater<long long>());

    long long largest_toy_size = toy_sizes[0];
    long long largest_box_size = box_sizes[0];

    if (largest_toy_size <= largest_box_size) {
        // If the largest toy can fit into an existing box, we can use that box
        cout << largest_box_size << endl;
    } else {
        // Otherwise, we need to find the minimum box size that can fit the largest toy
        long long min_extra_box_size = largest_toy_size;
        for (int i = 1; i < N - 1; i++) {
            if (toy_sizes[i] <= box_sizes[i]) {
                min_extra_box_size = min(min_extra_box_size, box_sizes[i]);
            } else {
                // From this point, all boxes are too small for the current toy
                break;
            }
        }

        // Compare the smallest needed box size with the largest existing box size
        cout << min(min_extra_box_size, largest_box_size) << endl;
    }

    return 0;
}