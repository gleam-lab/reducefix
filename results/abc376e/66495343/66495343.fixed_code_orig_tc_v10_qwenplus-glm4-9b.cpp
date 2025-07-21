#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int A[N], B[N];
vector<tuple<int, int>> C; // Stores pairs (A_i, B_i)

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        // Create combined pairs and sort by A_i descending
        for (int i = 0; i < n; ++i) {
            C.emplace_back(A[i], B[i]);
        }
        sort(C.begin(), C.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
            return get<0>(a) > get<0>(b);
        });

        int prefixSum = 0, maxA = 0, answer = INT_MAX;
        // Calculate prefix sums of B
        for (int i = 0; i < n; ++i) {
            if (i < k - 1) { // Only consider first k-1 elements for max A
                maxA = max(maxA, get<0>(C[i]));
                prefixSum += get<1>(C[i]);
            } else { // Consider from k-1 to n-1 for answer calculation
                maxA = max(maxA, get<0>(C[i]));
                int sumB = prefixSum;
                for (int j = k - 1; j <= i; ++j) {
                    sumB += get<1>(C[j]);
                }
                answer = min(answer, maxA * sumB);
            }
        }

        cout << answer << endl;
    }
    return 0;
}