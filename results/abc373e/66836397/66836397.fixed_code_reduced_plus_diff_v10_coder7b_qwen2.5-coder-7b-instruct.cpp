#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binary_search(vector<ll>& votes, ll target, ll m) {
    ll left = 0, right = 1e12;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for (ll vote : votes) {
            if (vote + mid > target) sum++;
        }
        if (sum <= m) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> votes(n);
    for (ll& vote : votes) cin >> vote;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        A[i] = votes[i];
        K -= votes[i];
    }

    sort(begin(A), end(A));

    vector<ll> C(n);
    for (ll i = 0; i < n; ++i) {
        if (A[i] >= K + m) {
            C[i] = 0;
        } else {
            C[i] = binary_search(A, K + m, m) - A[i];
        }
    }

    for (ll c : C) cout << c << " ";
    cout << endl;

    return 0;
}