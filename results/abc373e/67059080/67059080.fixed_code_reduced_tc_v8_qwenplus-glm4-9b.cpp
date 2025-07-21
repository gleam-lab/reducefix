#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;

    // Sort candidates by votes, in case of tie by index
    auto cmp = [&](ll a, ll b) {
        if (a == b) return &a < &b;
        return a < b;
    };
    sort(A.begin(), A.end(), cmp);

    vector<ll> additional_votes(N);
    for (ll i = 0; i < N; ++i) {
        ll additional = M * A[i] - (i >= M ? A[i - M] * M : 0LL) - A[i];
        if (additional > 0) {
            additional_votes[i] = additional;
        } else {
            additional_votes[i] = -1;
        }
    }

    for (ll &v : additional_votes) {
        cout << (v == -1 ? -1 : v) << " ";
    }
    cout << endl;

    return 0;
}