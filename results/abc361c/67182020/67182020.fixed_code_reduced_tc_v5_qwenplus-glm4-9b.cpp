#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = INT_MAX;
    int l = 0, r = N - 1;

    // Use two pointers to find the optimal removal of K elements
    while (r - l + 1 >= K) {
        // Calculate the maximum and minimum of the remaining elements
        int max_val = max(A[r], A[r - K + 1]);
        int min_val = min(A[l], A[l + K - 1]);

        // Update the answer with the minimum difference found
        ans = min(ans, max_val - min_val);

        // Move the pointers to explore other possible removals
        l++;
        r--;
    }

    cout << ans << endl;
    return 0;
}