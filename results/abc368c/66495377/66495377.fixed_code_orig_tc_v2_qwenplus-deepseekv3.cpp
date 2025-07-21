#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(ll T, const vector<ll>& H) {
    ll total_attacks = 0;
    for (ll h : H) {
        ll damage = (T / 3) * 5 + (T % 3 == 1 ? 1 : (T % 3 == 2 ? 2 : 0));
        if (damage < h) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll left = 0;
    ll right = 60047223146478LL; // Upper bound based on constraints
    ll answer = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (isPossible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}