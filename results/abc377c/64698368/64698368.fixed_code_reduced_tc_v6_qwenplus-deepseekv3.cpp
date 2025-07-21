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

int N,M; 
set<pair<int,int>> st;

void set_insert(int a, int b) {
    if (1 <= a && a <= N && 1 <= b && b <= N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;

    vector<pair<int,int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    rep(i, M) {
        int a, b; cin >> a >> b;
        for (auto move : moves) {
            set_insert(a + move.first, b + move.second);
        }
        st.insert({a, b}); // Also mark the existing piece's position as unsafe
    }

    ll total = 1LL * N * N;
    cout << total - st.size() << endl;
}