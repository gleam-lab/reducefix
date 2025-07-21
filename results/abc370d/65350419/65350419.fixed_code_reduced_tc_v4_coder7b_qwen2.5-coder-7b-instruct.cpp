#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
using ll = long long;
using PII = pair<int, int>;

const int INF = 1e9+7;
vector<vector<int>> bombs(400005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<PII> walls(h*w);
    iota(begin(walls), end(walls), 0);
    
    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        bool found = false;
        for(auto& [x,y]: bombs) {
            if(x == r && y == c) {
                found = true;
                break;
            }
        }
        
        if(!found) {
            for(auto& [x,y]: walls) {
                if(x == r && y == c) {
                    found = true;
                    break;
                }
            }
            
            if(found) {
                for(auto& [x,y]: walls) {
                    if(x == r && y == c) {
                        walls.erase(find(begin(walls), end(walls), make_pair(r, c)));
                        break;
                    }
                }
                
                for(int dx = -1; dx <= 1; ++dx) {
                    for(int dy = -1; dy <= 1; ++dy) {
                        if(dx == 0 && dy == 0) continue;
                        int nx = r + dx, ny = c + dy;
                        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
                            bool flag = true;
                            for(auto& [x,y]: walls) {
                                if(x == nx && y == ny) {
                                    flag = false;
                                    break;
                                }
                            }
                            
                            if(flag) {
                                walls.erase(find(begin(walls), end(walls), make_pair(nx, ny)));
                            }
                        }
                    }
                }
            }
        }
        
        if(!found) {
            bombs.pb(make_pair(r, c));
        }
    }
    
    cout << walls.size() + bombs.size() << '\n';
    return 0;
}