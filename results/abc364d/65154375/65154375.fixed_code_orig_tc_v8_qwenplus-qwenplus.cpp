#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_OFFSET = 2e8;
const int TOTAL_SIZE = 4 * MAX_OFFSET + 10; // Sufficient size to cover the range

ll a[TOTAL_SIZE]; // Offset array to handle negative indices

// Function to find the k-th smallest distance from A to b
ll findKthDistance(int Q_b, int Q_k, const ll* counts) {
    int pos = Q_b + MAX_OFFSET;
    int left = pos;
    int right = pos;
    int remaining = Q_k;
    
    while (true) {
        if (left >= 0 && counts[left] > 0) {
            int take = min(counts[left], remaining);
            remaining -= take;
            if (remaining == 0) {
                return abs(left - pos);
            }
        }
        if (right < TOTAL_SIZE && counts[right] > 0 && left != right) {
            int take = min(counts[right], remaining);
            remaining -= take;
            if (remaining == 0) {
                return abs(right - pos);
            }
        }
        left--;
        right++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize frequency array with zeros
    memset(a, 0, sizeof(a));

    // Read A values and populate the frequency array with offset
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        a[x + MAX_OFFSET]++;
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        cout << findKthDistance(b, k, a) << "\n";
    }

    return 0;
}