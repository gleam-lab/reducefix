#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());

        // Use a set to keep track of the sums of B values for subsets of size K
        multiset<long long> sums;

        // Iterate over A and calculate the sums of B for possible subsets
        for (int i = 0; i < n; ++i) {
            long long sumB = 0;
            for (int j = 0; j < n; ++j) {
                if (j >= i + 1 - k) {
                    sumB += B[j];
                }
            }
            sums.insert(sumB);
        }

        // Find the minimum product
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long maxA = A[i];
            auto it = sums.lower_bound(maxA * k);
            if (it != sums.begin()) {
                --it;
                ans = min(ans, maxA * (*it));
            }
        }

        cout << ans << '\n';
    }
    return 0;
}