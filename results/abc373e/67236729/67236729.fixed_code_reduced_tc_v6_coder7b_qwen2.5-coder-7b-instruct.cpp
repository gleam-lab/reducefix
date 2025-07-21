#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
        cin >> A[i];

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];

    vector<ll> result(N, -1);
    for (ll i = 0; i < N; i++) {
        ll target_votes = sorted_A[i] + 1;
        ll num_stronger_candidates = N - (upper_bound(sorted_A.begin(), sorted_A.end(), target_votes - 1) - sorted_A.begin());
        
        if (num_stronger_candidates < M) {
            ll needed_votes = (M - num_stronger_candidates) * target_votes - prefix_sum[M - num_stronger_candidates];
            result[i] = max(0LL, needed_votes);
        }
    }

    for (ll i = 0; i < N; i++)
        cout << result[i] << " ";

    return 0;
}