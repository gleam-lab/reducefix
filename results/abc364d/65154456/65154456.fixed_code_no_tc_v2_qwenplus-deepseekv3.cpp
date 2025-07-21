#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index

        int left = lower_bound(A.begin(), A.end(), b) - A.begin() - 1;
        int right = left + 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        if (left >= 0) {
            pq.push({abs(A[left] - b), left});
        }
        if (right < N) {
            pq.push({abs(A[right] - b), right});
        }

        ll ans = 0;
        while (k--) {
            auto current = pq.top();
            pq.pop();
            int idx = current.second;
            if (idx > 0 && A[idx - 1] < A[idx]) {
                pq.push({abs(A[idx - 1] - b), idx - 1});
            }
            if (idx < N - 1 && A[idx + 1] > A[idx]) {
                pq.push({abs(A[idx + 1] - b), idx + 1});
            }
        }
        ans = pq.top().first;
        cout << ans << '\n';
    }

    return 0;
}