#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

ll midpoint(ll a, ll b) {
    return a + (b - a) / 2;
}

bool checkVictory(ll i, ll x, ll *votes, ll totalVotes, ll m, ll n) {
    ll newVotes = votes[i] + x;
    ll rank = 1;
    for (ll j = 0; j < n; ++j) {
        if (j != i && votes[j] > newVotes) {
            ++rank;
        }
    }
    return rank <= m;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> votes(n);
    for (ll i = 0; i < n; ++i) {
        cin >> votes[i];
        K -= votes[i];
    }

    sort(votes.begin(), votes.end());

    vector<ll> result(n);
    for (ll i = 0; i < n; ++i) {
        if (checkVictory(i, 0, votes.data(), K, m, n)) {
            result[i] = 0;
            continue;
        }

        ll low = 0, high = K;
        while (low < high) {
            ll mid = midpoint(low, high);
            if (checkVictory(i, mid, votes.data(), K, m, n)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low >= K) {
            result[i] = -1;
        } else {
            result[i] = low;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << result[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}