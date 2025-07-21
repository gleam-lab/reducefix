#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;

        ll left = 0, right = 2e14;
        ll answer = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            auto it_l = lower_bound(A.begin(), A.end(), b - mid);
            auto it_r = upper_bound(A.begin(), A.end(), b + mid);
            ll count = it_r - it_l;
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}