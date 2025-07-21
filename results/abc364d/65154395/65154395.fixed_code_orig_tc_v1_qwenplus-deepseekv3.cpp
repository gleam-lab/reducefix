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
        ll b;
        int k;
        cin >> b >> k;
        --k; // convert to 0-based index

        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);
            int count = right - left;

            if (count > k) {
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