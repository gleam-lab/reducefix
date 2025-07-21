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

vector<pair<int,int>> movements = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    set<pair<int, int>> threatened;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        occupied.insert({a, b});

        for (auto& move : movements) {
            int new_a = a + move.first;
            int new_b = b + move.second;

            while (isValid(new_a, new_b, N)) {
                if (!occupied.count({new_a, new_b})) {
                    threatened.insert({new_a, new_b});
                }
                new_a += move.first;
                new_b += move.second;
            }
        }
    }

    ll total_squares = N * N;
    ll usable_squares = total_squares - threatened.size();

    cout << usable_squares << endl;

    return 0;
}