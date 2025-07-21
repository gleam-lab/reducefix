#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        ll left = 0;
        ll right = 2e14; // Sufficiently large upper bound for binary search
        ll answer = 0;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count the number of A_i <= b + mid and >= b - mid
            auto lower = lower_bound(A.begin(), A.end(), b - mid);
            auto upper = upper_bound(A.begin(), A.end(), b + mid);
            int count = upper - lower;
            
            if (count >= k) {
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