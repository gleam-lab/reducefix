#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool is_safe(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Point> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
        --pieces[i].x; --pieces[i].y;
    }

    set<pair<int, int>> occupied;
    for (auto& p : pieces) {
        vector<Point> moves = {
            Point(0, 0), Point(2, 1), Point(1, 2), Point(-1, 2),
            Point(-2, 1), Point(-2, -1), Point(-1, -2), Point(1, -2),
            Point(2, -1)
        };
        for (auto& move : moves) {
            if (is_safe(p.x + move.x, p.y + move.y, N)) {
                occupied.insert({p.x + move.x, p.y + move.y});
            }
        }
    }

    long long total_squares = N * N;
    long long captured_squares = occupied.size();
    cout << total_squares - captured_squares << endl;

    return 0;
}