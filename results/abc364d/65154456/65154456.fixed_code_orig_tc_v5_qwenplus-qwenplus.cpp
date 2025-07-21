#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int OFFSET = 1e8;  // To handle negative indices

// Binary indexed tree (Fenwick Tree) implementation
class BIT {
private:
    vector<ll> tree;
    int size;

public:
    BIT(int sz) : size(sz), tree(sz + 2, 0) {}

    // Add count to position idx
    void update(int idx, int count) {
        while (idx <= size) {
            tree[idx] += count;
            idx += idx & -idx;
        }
    }

    // Query prefix sum up to idx
    ll query(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    // Find the smallest x such that the prefix sum >= k
    int find_kth(int k) {
        int curr = 0, sum = 0;
        for (int i = 26; i >= 0; --i) {  // since 2^26 > 2e8
            int next = curr + (1 << i);
            if (next <= size && sum + tree[next] < k) {
                curr = next;
                sum += tree[next];
            }
        }
        return curr + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    const int MAX_COORD = 2 * (int)1e8 + 2;  // With offset
    BIT bit(MAX_COORD);

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        int pos = a + OFFSET + 1;  // +1 to avoid zero index in BIT
        bit.update(pos, 1);
    }

    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        int pos = b + OFFSET + 1;

        // Binary search on distance
        int left = 0, right = 2e8 + 1;
        int ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int l = max(1, pos - mid);
            int r = min(MAX_COORD, pos + mid);
            ll cnt = bit.query(r) - bit.query(l - 1);

            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}