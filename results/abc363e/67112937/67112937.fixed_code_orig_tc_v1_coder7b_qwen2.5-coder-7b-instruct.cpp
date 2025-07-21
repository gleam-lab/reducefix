#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    auto valid = [&](int x, int y) -> bool{
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    auto push_adjacent = [&](int x, int y) -> void{
        static const array<pair<int, int>, 4> dir = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        for(auto& [dx, dy]: dir){
            int nx = x + dx, ny = y + dy;
            if(valid(nx, ny) && !visited[nx][ny]){
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], make_pair(nx, ny));
            }
        }
    };

    for(int i = 0; i < H; ++i){
        visited[i][0] = true;
        visited[i][W - 1] = true;
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W - 1], make_pair(i, W - 1));
    }

    for(int j = 0; j < W; ++j){
        visited[0][j] = true;
        visited[H - 1][j] = true;
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H - 1][j], make_pair(H - 1, j));
    }

    while(!pq.empty()){
        int h = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        if(h <= Y){
            push_adjacent(x, y);
        } else {
            break;
        }
    }

    int res = 0;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            res += visited[i][j];
        }
    }

    cout << res << endl;

    return 0;
}