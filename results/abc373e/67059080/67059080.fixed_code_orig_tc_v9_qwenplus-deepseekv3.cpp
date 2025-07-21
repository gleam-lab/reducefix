#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll remaining = K - prefix[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = A[i] + mid;

            int idx = upper_bound(sortedA.begin(), sortedA.end(), newVotes) - sortedA.begin();
            int cnt = N - idx;

            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[i] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}