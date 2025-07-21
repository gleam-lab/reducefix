#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
vector<ll> A;

ll solve(int i) {
    ll remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);
    ll low = 0, high = remaining_votes;
    ll min_X = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll current_votes = A[i] + mid;
        
        vector<ll> temp = A;
        temp[i] += mid;
        sort(temp.begin(), temp.end(), greater<ll>());

        int position = 0;
        while (position < N && temp[position] > current_votes) position++;
        if (position < M) {
            min_X = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return min_X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll total = accumulate(A.begin(), A.end(), 0LL);
    ll remaining = K - total;

    for (int i = 0; i < N; ++i) {
        ll current_votes = A[i];
        vector<ll> others = A;
        others.erase(others.begin() + i);
        sort(others.begin(), others.end(), greater<ll>());

        if (remaining < 0) {
            cout << -1 << ' ';
            continue;
        }

        // Check if already elected
        int cnt = 0;
        for (ll v : others) {
            if (v > current_votes) cnt++;
        }
        if (cnt < M) {
            cout << 0 << ' ';
            continue;
        }

        // Binary search for the minimal X
        ll low = 0, high = remaining, min_X = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_votes = current_votes + mid;
            int cnt_more = 0;
            for (ll v : others) {
                if (v > new_votes) cnt_more++;
            }
            if (cnt_more < M) {
                min_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << min_X << ' ';
    }

    return 0;
}