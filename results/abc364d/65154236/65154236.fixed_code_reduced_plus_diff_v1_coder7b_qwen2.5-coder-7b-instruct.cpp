#include <bits/stdc++.h>
using namespace std;

vector<int> dist;

void solve(vector<int>& A, vector<int>& B, int k) {
    dist.clear();
    for (int a : A) {
        dist.push_back(abs(a - B[k]));
    }
    sort(dist.begin(), dist.end());
    cout << dist[k - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> A(n), B(q);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> B[i] >> k;
        --k; // Adjusting to zero-based index
        solve(A, B[i], k);
    }

    return 0;
}