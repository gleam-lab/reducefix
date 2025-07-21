#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
set<pair<int, int>> forbidden;

void mark_forbidden(int a, int b) {
    // All 8 possible knight moves
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            forbidden.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    for (auto &piece : pieces) {
        mark_forbidden(piece.first, piece.second);
    }
    
    ll total_squares = (ll)N * N;
    ll forbidden_squares = forbidden.size();
    ll answer = total_squares - forbidden_squares - M; // Subtract M because the pieces' positions are also occupied
    
    cout << answer << endl;
    
    return 0;
}