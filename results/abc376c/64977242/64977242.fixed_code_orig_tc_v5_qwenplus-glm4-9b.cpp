#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Find the maximum size `B[i]` that can accommodate any toy from `A`.
    int min_box_size = 0;
    for (int i = 0; i < N - 1; i++) {
        int max_b_i = 0;
        // Find the largest toy that can fit in box i
        for (int j = 0; j < N; j++) {
            if (B[i] >= A[j]) {
                max_b_i = max(max_b_i, A[j]);
            }
        }
        // Update the minimum box size needed
        min_box_size = max(min_box_size, max_b_i);
    }

    // Check if the toys can fit into the boxes
    for (int toy : A) {
        bool can_fit = false;
        for (int box : B) {
            if (toy <= box) {
                can_fit = true;
                break;
            }
        }
        if (!can_fit) {
            min_box_size = max(min_box_size, toy);
        }
    }

    // Output the minimum box size needed or -1 if it's impossible
    if (min_box_size == 0) {
        cout << -1 << endl;
    } else {
        cout << min_box_size << endl;
    }

    return 0;
}