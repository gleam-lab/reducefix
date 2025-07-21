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

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll remaining_votes = K - prefix[N];
    if (remaining_votes < 0) {
        remaining_votes = 0;
    }

    vector<ll> ans(N);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining_votes;
        ll best = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            int idx = upper_bound(sortedA.begin(), sortedA.end(), new_votes) - sortedA.begin();
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
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}