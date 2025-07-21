#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        int left = lower_bound(A.begin(), A.end(), b) - A.begin();
        int right = left;
        int count = 0;
        ll res = 0;
        
        while (count < k) {
            if (left == 0 && right == N) {
                break;
            }
            ll left_dist = (left > 0) ? b - A[left - 1] : LLONG_MAX;
            ll right_dist = (right < N) ? A[right] - b : LLONG_MAX;
            
            if (left_dist <= right_dist) {
                res = left_dist;
                left--;
            } else {
                res = right_dist;
                right++;
            }
            count++;
        }
        cout << res << '\n';
    }
    return 0;
}