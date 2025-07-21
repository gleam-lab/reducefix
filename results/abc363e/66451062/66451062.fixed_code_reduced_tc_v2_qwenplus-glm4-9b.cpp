#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    Node(int x, int y, int val) : x(x), y(y), val(val) {}
    bool operator < (const Node &a) const {
        return val < a.val;
    }
};

int h, w, y;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];

int main() {
    close;
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    
    priority_queue<Node, vector<Node>, greater<Node>> q;
    int area = 0;
    
    // Initialize the priority queue with edges and corners of the grid
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                if (!vis[i][j]) {
                    q.push(Node(i, j, grid[i][j]));
                    vis[i][j] = 1;
                    area++;
                }
            }
        }
    }
    
    for (int level = 1; level <= y; ++level) {
        int current_area = 0;
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            if (cur.val <= level) {
                area--;
            } else {
                current_area++;
                for (int i = 0; i < 4; ++i) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny] <= level) {
                        q.push(Node(nx, ny, grid[nx][ny]));
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << current_area << endl;
    }
    
    return 0;
}