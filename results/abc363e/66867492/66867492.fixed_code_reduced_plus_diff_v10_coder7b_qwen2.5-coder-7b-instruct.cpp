#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define em emplace_back
#define pob pop_back
#define el '\n'
#define YES cout<<"Yes"<<el
#define NO cout<<"No"<<el
#define NG cout<<-1<<el
#define ansNG(ans,ng) if(ans==ng){ NG; }else{ cout<<ans<<el; }
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define rrep(i,n)    for(int i = (n)-1; i >= 0; --i)
#define rrep3(i,l,r) for(int i = (r)-1; i >= (l); --i)
#define next_p(x) next_permutation( x )

// Function to check if a cell is within bounds
bool isValid(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

// Function to perform BFS and mark cells as submerged
void bfs(vector<vector<int>>& A, vector<vector<bool>>& used, int level, int H, int W) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!used[i][j] && A[i][j] <= level) {
                q.emplace(i, j);
                used[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            
            if (isValid(nx, ny, H, W) && !used[nx][ny] && A[nx][ny] <= level) {
                q.emplace(nx, ny);
                used[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));

    for (int i = 1; i <= Y; ++i) {
        bfs(A, used, i, H, W);
        int remaining_area = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!used[j][k]) {
                    ++remaining_area;
                }
            }
        }
        cout << remaining_area << el;
    }

    return 0;
}