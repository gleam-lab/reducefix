#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binary_search(vector<ll>& votes, ll total_votes, ll m, ll target) {
    ll left = 0, right = total_votes + 1;
    while(left < right) {
        ll mid = left + (right - left) / 2;
        ll excess = 0;
        for(auto vote : votes) {
            excess += max(0LL, vote + mid - target);
        }
        if(excess > (ll)m * (target - votes.size())) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    ll total_votes = 0;
    for(ll i = 0; i < n; i++) {
        cin >> votes[i];
        total_votes += votes[i];
    }

    vector<ll> result(n);
    for(ll i = 0; i < n; i++) {
        ll needed = binary_search(votes, total_votes - votes[i], m, votes[i]);
        if(needed > total_votes - votes[i]) {
            result[i] = -1;
        } else {
            result[i] = needed;
        }
    }

    for(ll i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}