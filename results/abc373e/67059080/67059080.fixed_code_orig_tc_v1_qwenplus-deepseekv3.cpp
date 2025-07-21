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
    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll total = A[i] + mid;
            int idx = upper_bound(sortedA.begin(), sortedA.end(), total) - sortedA.begin();
            int cnt = N - idx;
            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans != -1) {
            ll total = A[i] + ans;
            int idx = upper_bound(sortedA.begin(), sortedA.end(), total) - sortedA.begin();
            vector<ll> temp = sortedA;
            temp.push_back(total);
            sort(temp.begin(), temp.end());
            int pos = lower_bound(temp.begin(), temp.end(), total) - temp.begin();
            ll sum_lower = 0;
            for (int j = 0; j < pos; ++j) {
                sum_lower += temp[j];
            }
            ll needed = total * (N - pos) - (prefix[N] - prefix[pos] + (temp[pos] == total ? 0 : sortedA[pos]));
            if (needed <= remaining - ans) {
                res[i] = ans;
            } else {
                res[i] = -1;
            }
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}