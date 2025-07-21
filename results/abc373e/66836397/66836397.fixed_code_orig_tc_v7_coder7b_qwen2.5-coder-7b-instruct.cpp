#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canWin(vector<long long>& A, vector<long long>& P, int M, int i, long long x) {
    int n = A.size();
    long long rem = accumulate(P.begin(), P.end(), 0ll);
    long long sum = A[i] + x;
    int uppercnt = n - (lower_bound(A.begin(), A.end(), sum) - A.begin());

    if (M <= uppercnt) return false;
    int l = uppercnt - M;
    long long cnt = (sum + 1) * (l + 1) - (P[l + 1] - P[l]);
    return rem >= cnt;
}

long long binarySearch(vector<long long>& A, vector<long long>& P, int M, int i) {
    long long low = 0, high = K - accumulate(A.begin(), A.end(), 0ll);
    while (low < high) {
        long long mid = (low + high) / 2;
        if (canWin(A, P, M, i, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<long long> A(N), P(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    partial_sum(A.begin(), A.end(), P.begin());
    
    vector<long long> ans(N);
    for (int i = 0; i < N; ++i) {
        if (A[i] >= K) {
            ans[i] = 0;
        } else {
            ans[i] = binarySearch(A, P, M, i);
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}