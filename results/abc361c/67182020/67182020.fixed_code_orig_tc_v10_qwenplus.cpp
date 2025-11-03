#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    // We are removing exactly K elements, so we keep (N - K) elements.
    // The optimal strategy is to remove some number of smallest elements and some number of largest elements.
    // Try all possible ways: remove i smallest and (K - i) largest, for i from 0 to K.
    ll min_diff = LLONG_MAX;
    
    for (int i = 0; i <= K; ++i) {
        int left = i;           // number of smallest elements removed
        int right = K - i;      // number of largest elements removed
        int remaining_start = left;
        int remaining_end = N - 1 - right;
        
        if (remaining_start <= remaining_end) {
            ll diff = (ll)A[remaining_end] - (ll)A[remaining_start];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}