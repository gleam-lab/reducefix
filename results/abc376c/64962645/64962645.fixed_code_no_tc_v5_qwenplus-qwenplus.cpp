#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys in descending order of size
    sort(A.begin(), A.end(), greater<>());

    // Sort boxes in descending order
    sort(B.begin(), B.end(), greater<>());

    // We need to find the minimum x such that we can assign all toys to boxes,
    // including one box of size x.

    // The idea is to try placing the largest toy in the purchased box.
    // Then assign remaining toys greedily to available boxes.

    // Since we want to minimize x, we binary search over possible x values
    long long low = 1, high = 1e18;
    long long answer = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;

        // Create a list of available boxes: original ones + new box of size mid
        vector<long long> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end(), greater<>());

        // Check if we can assign toys
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] > boxes[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
}