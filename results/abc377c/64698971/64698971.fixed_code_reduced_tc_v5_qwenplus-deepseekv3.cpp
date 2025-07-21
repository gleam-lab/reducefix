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

int N, M;
set<pair<int, int>> unsafe;

void mark_unsafe(int a, int b) {
    static const vector<pair<int, int>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (const auto &offset : offsets) {
        int x = a + offset.first;
        int y = b + offset.second;
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            unsafe.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (auto &p : pieces) {
        cin >> p.first >> p.second;
        unsafe.insert(p);  // The piece's own position is unsafe for new placement
    }
    
    for (const auto &p : pieces) {
        mark_unsafe(p.first, p.second);
    }
    
    ll total_squares = (ll)N * N;
    ll unsafe_count = unsafe.size();
    ll safe_squares = total_squares - unsafe_count;
    
    cout << safe_squares << endl;
}