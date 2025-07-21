#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200010

int n, k;
vector<int> A, B;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        A.resize(n);
        B.resize(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());
        
        int min_value = INT_MAX;
        int sum = 0;
        
        // We start from k-1 because we need at least k elements to form a subset of size k
        for (int i = 0; i < n - k + 1; ++i) {
            sum += B[i];
            if (i >= k - 1) {
                int max_A = A[i + k - 1];
                min_value = min(min_value, max_A * sum);
                sum -= B[i];
            }
        }
        
        cout << min_value << "\n";
    }
    return 0;
}