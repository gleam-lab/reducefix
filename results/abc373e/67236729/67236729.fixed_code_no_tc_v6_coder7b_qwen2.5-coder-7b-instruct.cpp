#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 200010;

int N, M, K;
ll A[MAXN];

bool can_win(ll x) {
    vector<ll> votes(N);
    for (int i = 0; i < N; i++)
        votes[i] = A[i];
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({votes[i], i});
    }

    for (int i = 0; i < M; i++) {
        auto [cur_votes, idx] = pq.top();
        pq.pop();

        cur_votes += x;
        pq.push({cur_votes, idx});

        if (pq.size() < M) {
            continue;
        }

        ll sum = 0;
        for (int j = 0; j < M - 1; j++) {
            sum += pq.top().first;
            pq.pop();
        }

        if (pq.top().first > sum) {
            return true;
        }

        pq.push({sum, pq.top().second});
    }

    return false;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    ll left = 0, right = K - accumulate(A, A + N, 0LL);
    while (left < right) {
        ll mid = (left + right) / 2;
        if (can_win(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (can_win(left)) {
        cout << left << " ";
    } else {
        cout << "-1 ";
    }

    for (int i = 1; i < N; i++) {
        if (A[i] + left >= A[0] + left) {
            cout << "0 ";
        } else {
            cout << "-1 ";
        }
    }

    cout << endl;

    return 0;
}