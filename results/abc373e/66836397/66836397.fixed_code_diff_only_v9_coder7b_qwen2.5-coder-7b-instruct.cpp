#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binarySearch(vector<ll>& a, ll k, ll m) {
    ll left = 0, right = k;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll na = a[0] + mid;
        ll upperCount = 0;
        for (ll i = 1; i < a.size(); ++i) {
            if (a[i] > na) ++upperCount;
        }
        if (upperCount >= m) {
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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(rall(a));

    for (ll i = 0; i < n; ++i) {
        ll remainingVotes = k - accumulate(a.begin(), a.end(), 0LL);
        if (remainingVotes < 0) {
            cout << -1 << " ";
            continue;
        }
        ll additionalVotes = binarySearch(a, remainingVotes, m);
        if (additionalVotes > remainingVotes) {
            cout << -1 << " ";
        } else {
            cout << additionalVotes << " ";
        }
    }

    return 0;
}