#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
vector<ll> A;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> pre(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pre[i + 1] = pre[i] + sortedA[i];
    }

    ll remaining = K - pre[N];

    vector<ll> ans(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        int pos = upper_bound(sortedA.begin(), sortedA.end(), current) - sortedA.begin();
        if (N - pos < M) {
            ans[i] = 0;
            continue;
        }

        ll low = 0, high = remaining, res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_val) - sortedA.begin();
            if (N - new_pos < M) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (res != -1 && res <= remaining) {
            ans[i] = res;
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}