#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    vector<pair<ll, ll>> sortedA(N);
    for (ll i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> sortedValues(N);
    for (ll i = 0; i < N; ++i) {
        sortedValues[i] = sortedA[i].first;
    }

    vector<ll> prefixSum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedValues[i];
    }

    vector<ll> result(N);

    for (ll i = 0; i < N; ++i) {
        ll origIndex = i;
        ll currentVotes = A[origIndex];

        // Binary search for minimal X
        ll low = 0;
        ll high = rem;
        ll answer = -1;

        auto isEnough = [&](ll X) {
            ll newScore = currentVotes + X;
            ll left = 0;
            ll right = N;
            while (left < right) {
                ll mid = (left + right) / 2;
                if (sortedValues[mid] >= newScore)
                    right = mid;
                else
                    left = mid + 1;
            }
            ll pos = left;

            ll candidatesAbove = N - pos;

            if (candidatesAbove < M)
                return true;

            ll needed = max(0LL, candidatesAbove - (M - 1));
            ll idx = pos + needed - 1;
            if (idx >= N)
                idx = N - 1;

            ll required = (newScore + 1) * needed - (prefixSum[idx + 1] - prefixSum[pos]);
            return (rem - X) >= required;
        };

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (isEnough(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[origIndex] = (answer != -1 ? answer : -1);
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}