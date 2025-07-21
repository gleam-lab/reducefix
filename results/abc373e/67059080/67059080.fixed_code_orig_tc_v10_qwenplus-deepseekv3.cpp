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

    ll remaining_votes = K - prefix[N];

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        ll low = 0;
        ll high = remaining_votes;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a + mid;
            
            int pos = upper_bound(sortedA.begin(), sortedA.end(), total) - sortedA.begin();
            int cnt = N - pos;

            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}