#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to assign each toy to a box such that:
    // - Each toy goes into a box of size >= its size
    // - One toy per box
    // - One extra box of size x is added

    // Strategy: Try to match the largest toys with the largest boxes.
    // If one box is too small, we will replace it with x.

    // Match A[0..n-2] with B[0..n-2], and A[n-1] with x
    // So x must be >= A[n-1]
    // And all B[i] >= A[i+1]

    long long min_x = A[N - 1];  // Start with max toy size

    // Check if current assignments work with one new box of size min_x
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] < A[i + 1]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << min_x << '\n';
        return 0;
    }

    // Binary search on x
    long long low = min_x;
    long long high = 1e18;
    long long answer = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        // Create a list of available boxes: B + [mid]
        // Match each toy in A to a box >= its size, one-to-one

        vector<long long> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        int j = 0;
        for (int i = 0; i < N; ++i) {
            if (j < boxes.size() && boxes[j] >= A[i]) {
                j++;
            } else {
                // Cannot place this toy
                break;
            }
            if (i == N - 1 && j == boxes.size()) {
                // All toys placed successfully
                answer = mid;
                high = mid - 1;
                break;
            }
        }

        if (answer == mid) continue;

        // If not possible, try larger x
        low = mid + 1;
    }

    cout << answer << '\n';
    return 0;
}