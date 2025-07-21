#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    ll remaining_votes = K;
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = sortedA[i].first;
        ll left = 0;
        ll right = remaining_votes;
        ll answer = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_votes = current_votes + mid;
            
            int pos = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_votes, N)) - sortedA.begin();
            int cnt = N - pos;

            if (cnt < M) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (answer != -1) {
            res[sortedA[i].second] = answer;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}