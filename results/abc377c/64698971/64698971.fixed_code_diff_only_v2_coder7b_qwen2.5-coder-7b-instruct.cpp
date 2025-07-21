#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

const int dr[8] = {2, 2, 1, -1, -2, -2, -1, 1};
const int dc[8] = {1, -1, -2, -2, -1, 1, 2, 2};

int N, M;
unordered_set<long long> st;

void set_insert(int a, int b) {
    if (0 <= a && a < N && 0 <= b && b < N) {
        st.insert(((long long)a << 32) | b);
    }
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        rep(j, 8) {
            int na = a + dr[j];
            int nb = b + dc[j];
            set_insert(na, nb);
        }
    }

    ll total_squares = 1LL * N * N;
    ll occupied_squares = st.size();

    cout << total_squares - occupied_squares << endl;
}