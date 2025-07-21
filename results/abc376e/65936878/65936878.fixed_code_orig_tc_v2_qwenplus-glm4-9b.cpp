#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        long long sumB = 0;
        long long maxA = A[0];
        long long result = A[0] * sumB; // Start with the first element
        
        for (int i = 1; i <= n - k; i++) {
            sumB += B[i + k - 1] - B[i - 1];
            maxA = max(maxA, A[i + k - 1]);
            result = min(result, maxA * sumB);
        }
        
        cout << result << endl;
    }
    
    return 0;
}