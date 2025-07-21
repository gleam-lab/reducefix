#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;

int N, M;
ll A[MAXN], B[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    set<ll> st;
    for(int i = 1; i <= M; ++i){
        cin >> A[i] >> B[i];
        st.insert(A[i]);
        st.insert(B[i]);
        st.insert(A[i] + B[i]);
        st.insert(A[i] - B[i]);
    }

    cout << (N*N - st.size()) << '\n';

    return 0;
}