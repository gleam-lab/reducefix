#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefixSum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i].first;
    }

    ll remainingVotes = K - prefixSum[N];
    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        ll currentVotes = sortedA[i].first;
        ll low = 0;
        ll high = remainingVotes;
        ll bestX = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = currentVotes + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), make_pair(newVotes, INT_MAX));
            int countAbove = sortedA.end() - it;

            if (countAbove < M) {
                bestX = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (bestX != -1) {
            result[sortedA[i].second] = bestX;
        } else if (i >= N - M) {
            result[sortedA[i].second] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}