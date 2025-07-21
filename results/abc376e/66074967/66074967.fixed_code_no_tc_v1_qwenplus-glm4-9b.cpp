#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200000 + 9;

int N, K;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        A.clear();
        B.clear();

        cin >> N >> K;
        A.resize(N);
        B.resize(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        sort(A.begin(), A.end(), greater<int>()); // Sort A in descending order for better performance

        int ans = INT_MAX;
        int current_sum = 0;
        int pointers = 0;

        // Use a sliding window approach
        for (int i = 0; i < N; ++i) {
            // Remove elements outside the current window
            while (pointers > 0 && pointers + K - 1 <= i) {
                current_sum -= B[pointers - 1];
                pointers--;
            }

            // Add the current element to the sum if it's within the window
            if (i >= K - 1) {
                current_sum += B[i];
                pointers++;
            }

            // Check if the current window is valid (has exactly K elements)
            if (pointers == K) {
                ans = min(ans, (long long)A[i] * current_sum);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}