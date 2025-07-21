#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int N = 200100; // A large enough array size to handle the sum of N over all test cases

vector<int> A, B;
int dp[2][N+1];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        A.resize(n);
        B.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        // Initialize dp array
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = std::numeric_limits<int>::max();
        }
        dp[0][0] = 0;
        pq.push(0); // Push the sum of B for an empty subset

        for (int i = 0; i < n; ++i) {
            // Update dp array for the current element
            for (int j = 0; j <= k; ++j) {
                if (j > 0) {
                    while (!pq.empty() && pq.top() > sum + B[i]) {
                        pq.pop();
                    }
                    if (!pq.empty()) {
                        dp[1][j] = min(dp[1][j], dp[0][j-1] + pq.top() * A[i]);
                    }
                }
                dp[1][j] = min(dp[1][j], dp[0][j]); // Carry forward the previous value
            }
            sum += B[i];
            swap(dp[0], dp[1]); // Move to the next element
            pq.push(sum); // Push sum of B for the current subset
        }

        // The answer is the minimum value in the last row of the dp array
        cout << *min_element(dp[0] + 1, dp[0] + k + 1) << endl;
    }
    return 0;
}