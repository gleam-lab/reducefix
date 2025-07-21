#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end(), greater<pair<ll, int>>());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].first;
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = A[i].first + mid;
            int pos = upper_bound(A.begin(), A.end(), make_pair(new_val, N), greater<pair<ll, int>>()) - A.begin();

            if (pos <= M - 1) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            ll sum_needed = 0;
            if (pos > M) {
                sum_needed = new_val * (pos - M) - (prefix[pos] - prefix[M]);
            }

            if (sum_needed <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[A[i].second] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}