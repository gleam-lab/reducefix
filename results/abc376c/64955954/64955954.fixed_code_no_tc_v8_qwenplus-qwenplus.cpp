#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to match N toys to N boxes: N-1 existing and one additional box
    // For each toy, we must assign a box that is >= its size
    // Each box can contain at most one toy

    // Binary search on the minimum size x of the additional box

    long long left = 1, right = 2e9;
    long long answer = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        // Create a list of all available boxes including the new one
        vector<long long> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        // Try greedy matching: largest toy with largest possible box it fits in
        int toy_ptr = N - 1;
        int box_ptr = N - 1;
        bool valid = true;

        while (toy_ptr >= 0 && box_ptr >= 0) {
            if (boxes[box_ptr] >= A[toy_ptr]) {
                toy_ptr--;
            }
            box_ptr--;
        }

        if (toy_ptr == -1) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}