#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's already possible to store all toys in existing boxes
    bool canStore = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            canStore = false;
            break;
        }
    }

    if (canStore) {
        // If we can store all toys in existing boxes, the minimum x is 1
        cout << 1 << endl;
    } else {
        // If not, we need the smallest x such that all toys can be stored
        long long min_x = LLONG_MAX;
        for (int i = 0; i < N; i++) {
            // We need to find the smallest size that can fit all remaining toys
            long long maxToySize = 0;
            for (int j = 0; j < N; j++) {
                if (A[j] <= A[i]) {
                    maxToySize = max(maxToySize, A[j]);
                }
            }
            // Update the minimum x needed to store all toys starting from size A[i]
            min_x = min(min_x, maxToySize + 1);
        }
        // If no valid x is found, output -1
        if (min_x == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << min_x << endl;
        }
    }

    return 0;
}