#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;
int N, Q;

void solve() {
    sort(A.begin(), A.end());
    for(int i = 0; i < Q; ++i) {
        int b, k; cin >> b >> k;
        --k; // Convert to zero-based index
        vector<int> dists;
        auto it = lower_bound(A.begin(), A.end(), b);
        if(it != A.end()) dists.push_back(*it - b);
        if(it != A.begin()) dists.push_back(b - *(--it));
        cout << dists[k] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> Q;
    A.resize(N); B.resize(Q);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < Q; ++i) cin >> B[i];

    solve();

    return 0;
}