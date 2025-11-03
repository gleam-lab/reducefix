#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w,y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    int di[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin >> height[i][j];
            if(i==0 || i == h-1 || j == 0 || j == w-1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j],i,j}); 
            }
        }
    }
    
    while(!pq.empty()) {
        auto [H,r,c] = pq.top();
        pq.pop();
        if(sink[r][c] < H) continue; // already processed with lower value
        
        for(int i=0;i<4;i++) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            
            int new_sink = max(H, height[nr][nc]);
            if(new_sink < sink[nr][nc]) {
                sink[nr][nc] = new_sink;
                pq.push({new_sink, nr, nc});
            }
        }
    }
    
    vector<int> area(y+1, h*w);
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(sink[i][j] <= y) {
                area[sink[i][j]]--;
            }
        }
    }
    
    for(int i=1;i<=y;i++) {
        area[i] += area[i-1];
        cout << area[i] << '\n';
    }
}