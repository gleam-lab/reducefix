#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // Use a vector to store the points A_i
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // For each query, find the k_j-th closest point to B_j
    while (Q--) {
        int B, k_j;
        cin >> B >> k_j;

        // Sort A to find the k_j-th closest point
        sort(A.begin(), A.end());

        // The k_j-th closest point is A[k_j - 1]
        int closest_point = A[k_j - 1];

        // Calculate and print the distance
        cout << abs(closest_point - B) << endl;
    }

    return 0;
}