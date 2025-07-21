#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Node {
    int x, y, d;
    Node(int _x, int _y, int _d): x(_x), y(_y), d(_d) {}
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    
    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            queue<Node> q;
            q.push(Node(r, c, 0));
            
            while(!q.empty()) {
                auto [x, y, d] = q.front(); q.pop();
                
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w || !grid[nx][ny]) continue;
                    
                    if(dist[nx][ny] > d + 1) {
                        dist[nx][ny] = d + 1;
                        q.push(Node(nx, ny, d + 1));
                    }
                }
            }
            
            for(int i = 0; i < 4; ++i) {
                int nx = r, ny = c, d = dist[r][c];
                
                while(true) {
                    nx += dx[i]; ny += dy[i];
                    
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w || !grid[nx][ny]) break;
                    
                    grid[nx][ny] = false;
                    dist[nx][ny] = d + 1;
                    
                    if(i == 0) nx++;
                    else if(i == 1) ny--;
                    else if(i == 2) nx--;
                    else ny++;
                }
            }
        }
    }
    
    int ans = 0;
    for(auto& row : grid) 
        for(bool b : row) 
            if(b) ans++;
    
    cout << ans << '\n';
    
    return 0;
}