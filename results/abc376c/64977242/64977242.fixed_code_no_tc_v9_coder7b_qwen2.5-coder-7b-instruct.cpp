#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

// Function to check if we can fit all toys into boxes using a box of size x
bool canFit(int x, vector<int>& A, vector<int>& B) {
    int j = 0;
    for (int i = 0; i < A.size(); ++i) {
        // If current toy can fit into the current box
        if (A[i] <= x) {
            // Move to the next box
            if (j < B.size() && A[i] <= B[j]) {
                ++j;
            } else {
                // If we don't have enough boxes or the box is too small, return false
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Sort both arrays in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Binary search for the minimum size of the box needed
    int low = 0, high = 1e9 + 1; // Box size cannot exceed 1e9 as per constraints
    while (low < high) {
        int mid = (low + high) / 2;
        if (canFit(mid, A, B)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // Check if a valid solution was found
    if (high == 1e9 + 1) {
        cout << -1 << endl;
    } else {
        cout << high << endl;
    }

    return 0;
}