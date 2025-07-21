#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    ll totalUsed = prefix[N];
    ll remaining = K - totalUsed;

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll currentA = sortedA[i].first;
        ll left = 0, right = remaining, answer = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll newA = currentA + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), make_pair(newA, N));
            int count = sortedA.end() - it;
            if (count < M) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        res[sortedA[i].second] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}