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

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = sortedA[i].first;
        ll low = 0;
        ll high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_current = current + mid;
            
            int upper = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_current, N)) - sortedA.begin();
            int cnt_above = N - upper;

            if (cnt_above < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[sortedA[i].second] = answer;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}