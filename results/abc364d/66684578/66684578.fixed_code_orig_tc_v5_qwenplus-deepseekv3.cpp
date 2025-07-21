#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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

        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            int cnt = upper_bound(A.begin(), A.end(), b + mid) - lower_bound(A.begin(), A.end(), b - mid);
            if (cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}