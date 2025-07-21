#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can place N-1 toys in the existing boxes without the new box
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // Now, we need to find the smallest x such that the largest remaining toy can fit into x
    // The largest remaining toy is A[N-1], and it cannot be placed in any existing box unless B[i] >= A[N-1]
    // But since the existing boxes are already used for the first N-1 toys, the new box must accommodate the largest toy not fitted in any existing box
    // So, the minimal x is A[N-1], but we need to ensure that the other N-1 toys can fit into the existing boxes
    // Wait, the previous check already ensures that the first N-1 toys can be placed in the first N-1 boxes
    // So the only remaining toy is A[N-1], which must be placed in the new box. Thus, x must be at least A[N-1]

    cout << A.back() << endl;

    return 0;
}