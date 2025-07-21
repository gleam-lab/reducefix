#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, M;
set<pair<int, int>> unsafe;

void mark_unsafe(int a, int b) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            unsafe.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    for (auto &p : pieces) {
        mark_unsafe(p.first, p.second);
    }

    ll total_squares = (ll)N * N;
    ll unsafe_count = unsafe.size();
    ll occupied_count = M;
    ll safe_squares = total_squares - unsafe_count - occupied_count;

    cout << safe_squares << endl;
    return 0;
}