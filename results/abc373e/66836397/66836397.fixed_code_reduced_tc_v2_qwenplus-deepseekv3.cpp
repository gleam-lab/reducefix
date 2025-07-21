#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll &a : A) {
        cin >> a;
        sum += a;
    }
    ll rem = K - sum;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    auto check = [&](ll i, ll x) {
        ll new_votes = A[i] + x;
        ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();
        ll upper_count = N - pos;
        if (upper_count >= M) {
            return false;
        }
        ll needed = M - 1 - upper_count;
        if (needed < 0) {
            return true;
        }
        ll left = pos - needed;
        if (left < 0) {
            return false;
        }
        ll total = new_votes * needed - (prefix[pos] - prefix[left]);
        if (total <= rem - x) {
            return true;
        }
        return false;
    };

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = rem;
        ll ans = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(i, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " \n"[i == N - 1];
    }

    return 0;
}