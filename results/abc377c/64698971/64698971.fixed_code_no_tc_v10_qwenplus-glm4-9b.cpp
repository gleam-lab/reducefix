#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define rrepi(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define ALL(a) (a).begin(), (a).end()
#define ALL_(a) (a), (a) + (int)(a).size()
#define IF_T if (Is_test)

using namespace std;

ll N, M;
set<pair<int, int>> st;

void set_insert(int a, int b) {
    if (0 <= a && a < N && 0 <= b && b < N) st.insert({a, b});
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>>VC = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        vector<pair<int, int>>VCtemp = VC;
        while (!VCtemp.empty()) {
            auto p = VCtemp.back();
            VCtemp.pop_back();
            int x = a + p.first, y = b + p.second;
            if (0 <= x && x < N && 0 <= y && y < N) {
                st.insert({x, y});
                VCtemp.insert(VCtemp.end(), VC,VC.end());
            }
        }
    }

    cout << (N * N) - (ll)st.size();
}