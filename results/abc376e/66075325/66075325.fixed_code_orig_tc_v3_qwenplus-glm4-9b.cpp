#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T, N, K, a, b;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> A(N + 1), B(N + 1);
        
        // Input A and B
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> B[i];
        }
        
        // Sort A and B based on A
        vector<pair<int, int>> ab(N + 1);
        for (int i = 1; i <= N; i++) {
            ab[i] = {A[i], B[i]};
        }
        sort(ab.begin() + 1, ab.end());
        
        // Initialize DP arrays
        vector<long long> dp1(N + 1, 1e18), dp2(N + 1, 1e18);
        dp1[K - 1] = 0;
        
        // Process elements from N to 1
        for (int i = N; i >= 1; i--) {
            int valA = ab[i].first, valB = ab[i].second;
            int j = i + 1; // Start from the next element
            
            // Update dp2 using dp1
            while (j <= N && dp1[j] < dp2[i + 1]) {
                dp2[i + 1] = min(dp2[i + 1], dp1[j] + (long long)valB * valA);
                j++;
            }
            
            // Update dp1 directly
            dp1[i] = min(dp1[i], dp1[i + 1] + (long long)valB * valA);
        }
        
        // Output the result
        cout << dp1[1] << endl;
    }
    return 0;
}