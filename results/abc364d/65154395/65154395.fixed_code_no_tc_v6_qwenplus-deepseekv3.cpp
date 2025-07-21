#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll B, K;
        cin >> B >> K;
        
        // Binary search to find the k-th smallest distance
        ll left = 0, right = 2e18;
        ll answer = 0;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count the number of elements A[i] <= B + mid and >= B - mid
            ll lower = B - mid;
            ll upper = B + mid;
            
            auto it_low = lower_bound(A.begin(), A.end(), lower);
            auto it_high = upper_bound(A.begin(), A.end(), upper);
            
            ll count = it_high - it_low;
            
            if (count >= K) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << '\n';
    }

    return 0;
}