#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
vector<ll> A[MAXN], B(MAXN);

void preprocess() {
    for(int i = 1; i < MAXN; ++i) {
        sort(A[i].begin(), A[i].end());
    }
}

ll query(int idx, int k) {
    return A[idx][k - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    
    for(int i = 1; i <= N; ++i) {
        int a; cin >> a;
        A[a].push_back(a);
    }

    preprocess();

    for(int i = 1; i <= Q; ++i) {
        int b, k; cin >> b >> k;
        cout << query(b, k) << '\n';
    }

    return 0;
}