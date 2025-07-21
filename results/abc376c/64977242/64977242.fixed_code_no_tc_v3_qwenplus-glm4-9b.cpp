#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<long long> A, B;

    cin >> N;
    A.resize(N);
    B.resize(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // We need to ensure each toy can fit into a box, so we check if the largest toy
    // can fit into the smallest box we can use.
    if (A.back() > B.back()) {
        cout << B.back() + 1 << endl; // The largest toy needs a box one size larger than the smallest existing box.
    } else {
        // If the largest toy can fit in the smallest box, but there are toys that cannot fit into any existing boxes,
        // then we need to find the smallest possible size of a box that can fit all toys.
        // We will use a set to avoid duplicate box sizes and then check if there is a gap between the largest box size
        // that can fit any toy and the smallest box size that cannot fit any toy.
        vector<int> uniqueBoxSizes;
        for (long long boxSize : B) {
            if (uniqueBoxSizes.empty() || boxSize != uniqueBoxSizes.back()) {
                uniqueBoxSizes.push_back(boxSize);
            }
        }
        sort(uniqueBoxSizes.begin(), uniqueBoxSizes.end());

        // Create a set of toy sizes to check for gaps.
        vector<int> toySizes;
        for (long long toySize : A) {
            toySizes.push_back(toySize);
        }
        sort(toySizes.begin(), toySizes.end());

        for (int i = 0, j = 0; i < toySizes.size(); i++) {
            // Find the smallest box that can fit the current toy.
            while (j < uniqueBoxSizes.size() && uniqueBoxSizes[j] < toySizes[i]) {
                j++;
            }
            // If there's no box that can fit the current toy, then we need a new box.
            if (j == uniqueBoxSizes.size()) {
                cout << uniqueBoxSizes.back() + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl; // If no solution is found, print -1.
    return 0;
}