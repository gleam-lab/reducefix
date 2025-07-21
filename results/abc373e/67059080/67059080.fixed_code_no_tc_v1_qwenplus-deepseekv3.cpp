#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i].first;
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = sorted_A[i].first;
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_votes, N));
            int count = sorted_A.end() - it;

            if (count < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1) {
            res[sorted_A[i].second] = answer;
        } else {
            res[sorted_A[i].second] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}