#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>A[i][j];

    vector<vector<bool>>visited(H,vector<bool>(W,false));
    vector<queue<pair<int,int>>>Q(Y+1);

    // Initialize the queue with border cells and mark them as visited
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i == 0 || i == H - 1 || j == 0 || j == W - 1){
                visited[i][j] = true;
                Q[A[i][j]].push({i,j});
            }
        }
    }

    int total_area = H * W;
    vector<int>remaining_area(Y + 1, total_area);

    for(int y = 1; y <= Y; y++){
        while(!Q[y].empty()){
            auto [x, y] = Q[y].front(); Q[y].pop();
            remaining_area[y]--;
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= y){
                    visited[nx][ny] = true;
                    Q[y].push({nx, ny});
                }
            }
        }
        if(y < Y) cout << remaining_area[y + 1] << '\n';
    }

    return 0;
}