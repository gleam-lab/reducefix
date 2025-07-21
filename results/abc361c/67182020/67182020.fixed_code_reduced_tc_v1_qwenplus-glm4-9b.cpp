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
    
    if (K % 2 == 0) {
        cout << A[N - 1 - K / 2] - A[K / 2] << endl;
    } else {
        int max_diff1 = A[N - 1 - (K / 2)] - A[(K + 1) / 2];
        int max_diff2 = A[N - 2 - (K / 2)] - A[(K - 1) / 2];
        cout << max(max_diff1, max_diff2) << endl;
    }
    
    return 0;
}