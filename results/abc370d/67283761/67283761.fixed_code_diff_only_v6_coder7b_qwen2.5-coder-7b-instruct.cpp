#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <climits>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;
#pragma warning(disable: 4189)
#pragma warning(disable: 4267)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    
    vector<vector<int>> cache(H, vector<int>(W, 0));
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int broken = 0;
    
    for(int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (map[r][c]) {
            ++broken;
            map[r][c] = false;
        } else {
            for (int j = 0; j < 4; ++j) {
                int ofsh = dir[j].first;
                int ofsw = dir[j].second;
                pair<int, int> next = {r + ofsh, c + ofsw};
                
                while (true) {
                    if (next.first >= 0 && next.first < H && next.second >= 0 && next.second < W) {
                        if (map[next.first][next.second]) {
                            ++broken;
                            map[next.first][next.second] = false;
                            break;
                        }
                        cache[next.first][next.second] = 1;
                    } else {
                        break;
                    }
                    
                    next.first += ofsh;
                    next.second += ofsw;
                }
            }
        }
    }
    
    cout << (H * W - broken) << endl;
    return 0;
}