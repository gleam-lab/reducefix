#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k) {
    // Find the insertion point of b in A
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();

    int left = pos - 1;
    int right = pos;

    // We'll use a two-pointer approach to find the k-th closest
    // Priority queues are too slow for this problem's constraints
    // Two pointers approach gives O(Q * N) in worst case which is not acceptable
    // So we switch to partial sort

    vector<ll> distances;
    for (int i = max(0, pos - k + 1); i < min((int)A.size(), pos + k); ++i) {
        distances.push_back(abs(A[i] - b));
    }

    // If we collected less than k elements, add more from both ends
    while (distances.size() < k) {
        if (left >= 0 && right < A.size()) {
            if (abs(A[left] - b) < abs(A[right] - b)) {
                distances.push_back(abs(A[left] - b));
                --left;
            } else {
                distances.push_back(abs(A[right] - b));
                ++right;
            }
        } else if (left >= 0) {
            distances.push_back(abs(A[left] - b));
            --left;
        } else {
            distances.push_back(abs(A[right] - b));
            ++right;
        }
    }

    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}