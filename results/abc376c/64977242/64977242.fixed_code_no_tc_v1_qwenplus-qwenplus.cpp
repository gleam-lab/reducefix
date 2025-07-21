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

    // Sort toys and boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit all but one toy into the available boxes
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

    // Find the minimal x such that the largest toy fits in the purchased box
    long long min_box_size = max(A[N - 1], B[0]);

    cout << min_box_size << endl;

    return 0;
}