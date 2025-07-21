#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll val;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.begin(), a.end(), [](const Node &x, const Node &y) {
        return x.val > y.val;
    });

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + a[i].val;
    }

    ll remaining = K - prefix[N];

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i].val + mid;
            int pos = -1;

            // Find the first position where a[j].val <= new_val
            int left = 0, right = N;
            while (left < right) {
                int mid_pos = (left + right) / 2;
                if (a[mid_pos].val > new_val) {
                    left = mid_pos + 1;
                } else {
                    right = mid_pos;
                }
            }
            pos = left;

            // The number of candidates with votes > new_val is pos
            if (pos < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[a[i].idx] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}