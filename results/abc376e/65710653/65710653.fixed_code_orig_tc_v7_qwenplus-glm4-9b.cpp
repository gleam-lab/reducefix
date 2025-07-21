#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        
        long long min_val = A[K-1] * accumulate(B.begin(), B.begin() + K, 0LL);
        cout << min_val << endl;
    }
    return 0;
}