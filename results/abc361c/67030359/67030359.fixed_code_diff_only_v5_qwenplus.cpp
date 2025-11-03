#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using vi = vector<int>;

template<typename T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(all(A));
    
    // We need to remove exactly K elements, leaving N-K elements
    // The key insight: the optimal solution will always be a contiguous subarray 
    // of length (N-K) in the sorted array
    int remaining = N - K;
    int ans = A[remaining - 1] - A[0]; // Initial candidate
    
    // Try all possible contiguous subarrays of length (N-K)
    for (int i = 1; i + remaining - 1 < N; i++) {
        chmin(ans, A[i + remaining - 1] - A[i]);
    }
    
    cout << ans << endl;
    return 0;
}