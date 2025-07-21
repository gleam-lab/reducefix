#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, K;
    cin >> n >> m >> K;
    vector<long long> A(n);
    for(long long i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<long long> B(n);
    B[0] = A[0];
    for(long long i = 1; i < n; i++) {
        B[i] = B[i-1] + A[i];
    }

    vector<long long> C(n);
    C[n-1] = A[n-1];
    for(long long i = n-2; i >= 0; i--) {
        C[i] = C[i+1] + A[i];
    }

    for(long long i = 0; i < n; i++) {
        if(B[i] + A[i] * (n-i-1) >= K && C[i] + A[i] * i >= K) {
            cout << 0 << " ";
        } else {
            long long lo = 0, hi = K - B[i];
            while(lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                if(B[i] + A[i] * (n-i-1) + mid * (n-i-1) >= K && C[i] + A[i] * i + mid * i >= K) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << lo << " ";
        }
    }

    return 0;
}