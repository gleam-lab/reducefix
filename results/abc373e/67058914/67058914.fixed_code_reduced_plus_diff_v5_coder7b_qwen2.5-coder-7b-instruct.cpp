#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
    ll val;
    int idx;
};

bool can_win(int i, const vector<int>& A, const vector<int>& prefix, ll X) {
    ll remain = K - prefix.back() - X;
    ll cur = A[i] + X;
    ll tar = cur + 1;
    int zan = lower_bound(A.begin() + i + 1, A.end(), tar) - A.begin();
    int cnt = (N - zan + 1);
    if (cnt >= M) return false;
    ll need = tar * cnt - (prefix[zan] - prefix[zan - cnt]);
    if (zan - cnt < i) need -= (X + 1);
    return need <= remain;
}

int main() {
    cin >> N >> M >> K;

    vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.begin(), a.end());

    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1].val;
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
        if (a[i].val + K - prefix.back() >= a.back()) {
            ans[i] = 0;
            continue;
        }
        int left = 0, right = K - prefix.back() - a[i].val;
        while (left < right) {
            int mid = (left + right) / 2;
            if (can_win(i, a, prefix, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans[i] = left;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}