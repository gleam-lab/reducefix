#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    ll val;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i + 1;
    }

    sort(a.begin(), a.end(), [](const Candidate &x, const Candidate &y) {
        return x.val < y.val;
    });

    vector<ll> prefix(N + 1);
    prefix[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + a[i].val;
    }

    ll remaining = K - accumulate(a.begin(), a.end(), 0LL, [](ll sum, const Candidate &x) { return sum + x.val; });

    vector<ll> answer(N);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining + a[i].val;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i].val + mid;
            int pos = upper_bound(a.begin(), a.end(), Candidate{new_val, 0}, 
                [](const Candidate &x, const Candidate &y) { return x.val < y.val; }) - a.begin();
            int greater = N - pos;
            if (greater < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        answer[a[i].idx - 1] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}