#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    unordered_set<int> visited;

    for(int i = 0; i < Q; ++i){
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(!visited.count(r * W + c)){
            visited.insert(r * W + c);
            continue;
        }

        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; ++d){
            int nr = r + dr[d], nc = c + dc[d];
            while(nr >= 0 && nr < H && nc >= 0 && nc < W){
                if(!map[nr][nc]) break;
                visited.erase(nr * W + nc);
                map[nr][nc] = false;
                nr += dr[d];
                nc += dc[d];
            }
        }
    }

    cout << H * W - visited.size() << '\n';
    
    return 0;
}