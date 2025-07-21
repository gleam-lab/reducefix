#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N), B(Q), K(Q);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < Q; ++i) cin >> B[i] >> K[i];

    sort(A.begin(), A.end());

    for(int i = 0; i < Q; ++i) {
        int b = B[i], k = K[i] - 1;
        auto it = lower_bound(A.begin(), A.end(), b);
        int dist = abs(b - *it);
        if(it != A.begin()) dist = min(dist, abs(b - *(--it)));
        cout << dist << endl;
    }

    return 0;
}