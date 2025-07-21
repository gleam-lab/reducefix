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

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> pre(N + 1);
    for (int i = 0; i < N; ++i) {
        pre[i + 1] = pre[i] + sortedA[i].first;
    }

    ll remaining = K;
    remaining -= pre[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll a = sortedA[i].first;
        int idx = sortedA[i].second;

        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (sortedA[mid].first > a) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int cnt = N - left;

        if (cnt >= M) {
            res[idx] = -1;
            continue;
        }

        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a + mid;
            int L = 0, R = N;
            while (L < R) {
                int m = (L + R) / 2;
                if (sortedA[m].first > new_a) {
                    R = m;
                } else {
                    L = m + 1;
                }
            }
            int new_cnt = N - L;

            if (new_cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best != -1) {
            res[idx] = best;
        } else {
            res[idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}