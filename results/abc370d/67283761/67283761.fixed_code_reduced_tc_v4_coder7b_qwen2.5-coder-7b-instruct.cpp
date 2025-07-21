#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <filesystem>
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

int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));

    vector<vector<vector<int>>> cache(4, vector<vector<int>>(H, vector<int>(W, 0)));
    vector<pair<int, int>> dir;
    dir.push_back(make_pair(0, -1)); // L
    dir.push_back(make_pair(0, 1));  // R
    dir.push_back(make_pair(-1, 0)); // U
    dir.push_back(make_pair(1, 0));  // D
    int broken = 0;
    for(int i = 0; i < Q; ++i)
    {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (map[r][c])
        {
            ++broken;
            map[r][c] = false;
        }
        else
        {
            for (int j = 0; j < 4; ++j)
            {
                int ofsh = dir[j].first * cache[j][r][c];
                int ofsw = dir[j].second * cache[j][r][c];
                pair<int, int> next = make_pair(r + ofsh, c + ofsw);
                while (true)
                {
                    next.first += dir[j].first;
                    next.second += dir[j].second;
                    if (next.first >= 0 && next.first < H && next.second >= 0 && next.second < W)
                    {
                        if(map[next.first][next.second])
                        {
                            ++broken;
                            map[next.first][next.second] = false;
                            cache[j][r][c] = max(abs(r - next.first), abs(c - next.second));
                            break;
                        }
                        cache[j][next.first][next.second] = max(cache[j][next.first][next.second], 1);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << (H * W - broken) << endl;

    return 0;
}