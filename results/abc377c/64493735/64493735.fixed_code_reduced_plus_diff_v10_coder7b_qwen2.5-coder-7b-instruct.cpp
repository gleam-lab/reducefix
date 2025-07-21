#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>

class Sub {
public:
    int solve() {
        ll N, M;
        cin >> N >> M;

        s(p<ll, ll>> occupied_squares;

        for (ll i = 0; i < M; ++i) {
            ll a, b;
            cin >> a >> b;
            occupied_squares.insert({a, b});
        }

        ll total_empty_squares = N * N;
        ll total_occupied_squares = static_cast<ll>(occupied_squares.size());

        // Calculate the number of empty squares
        ll empty_squares = total_empty_squares - total_occupied_squares;

        cout << empty_squares << '\n';

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}