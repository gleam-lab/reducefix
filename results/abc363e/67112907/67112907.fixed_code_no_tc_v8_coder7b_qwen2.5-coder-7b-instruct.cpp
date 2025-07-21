#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int h, x, y;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Node> pq;
    for(int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        visited[i][0] = true;
    }
    for(int j = 1; j < W; ++j) {
        pq.emplace(A[0][j], 0, j);
        visited[0][j] = true;
    }
    for(int i = 1; i < H; ++i) {
        pq.emplace(A[i][W-1], i, W-1);
        visited[i][W-1] = true;
    }
    for(int j = 0; j < W-1; ++j) {
        pq.emplace(A[H-1][j], H-1, j);
        visited[H-1][j] = true;
    }

    while(Y--) {
        int ans = H * W;
        while(!pq.empty()) {
            auto [h, x, y] = pq.top(); pq.pop();
            if(h <= Y+1) {
                ans--;
                for(auto &[dx, dy]: vector<pair<int,int>>{{x-1,y},{x+1,y},{x,y-1},{x,y+1}}) {
                    if(dx>=0 && dx<H && dy>=0 && dy<W && !visited[dx][dy] && A[dx][dy]<=Y+1) {
                        pq.emplace(A[dx][dy], dx, dy);
                        visited[dx][dy] = true;
                    }
                }
            } else break;
        }
        cout << ans << '\n';
    }

    return 0;
}