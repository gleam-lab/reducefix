#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;

int N, M, K;
vector<ll> A;

ll check(ll X) {
    ll current_votes = 0;
    ll current_votes_needed = 0;

    for (ll i = 0; i < N; ++i) {
        current_votes += A[i];
        current_votes_needed += A[i];
        if (current_votes_needed - A[i] > X) {
            current_votes_needed -= A[i];
            current_votes = A[i];
        } else {
            current_votes_needed += X;
        }

        if (current_votes > current_votes_needed) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N >> M >> K;
    A.resize(N);
    for (ll &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end(), greater<ll>());

    ll left = 0, right = K;
    ll result = -1;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    for (ll i = 0; i < N; ++i) {
        cout << result + A[i] << " ";
    }
    cout << endl;

    return 0;
}