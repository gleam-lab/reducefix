#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i].first;
    }

    ll total_remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll a_i = sorted_A[i].first;
        ll low = 0, high = total_remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a_i = a_i + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_a_i, N));
            int cnt = sorted_A.end() - it;

            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best != -1) {
            res[sorted_A[i].second] = best;
        } else {
            res[sorted_A[i].second] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}