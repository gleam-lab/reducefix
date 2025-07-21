#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k) {
    // Find the lower bound of b in A
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
    
    int left = pos - 1;
    int right = pos;

    // We need to find the k-th closest using two pointers
    while (k > 0) {
        if (left < 0) {
            right++;
        } else if (right >= A.size()) {
            left--;
        } else if (abs(A[left] - b) <= abs(A[right] - b)) {
            left--;
        } else {
            right++;
        }
        k--;
    }

    // Now we have to determine the actual distance
    if (left >= 0 && right < A.size()) {
        return min(abs(A[left] - b), abs(A[right] - b));
    } else if (left >= 0) {
        return abs(A[left] - b);
    } else {
        return abs(A[right] - b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b, k;
        cin >> b >> k;
        cout << abs(A[lower_bound(A.begin(), A.end(), b) - A.begin() - 1] - b) << endl;
    }

    return 0;
}