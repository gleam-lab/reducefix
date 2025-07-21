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

int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));

    for(int i = 0; i < Q; ++i)
    {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (map[r][c])
        {
            map[r][c] = false;
        }
        else
        {
            for(int j = 0; j < 4; ++j)
            {
                int x = r, y = c;
                while(true)
                {
                    x += j == 0 ? -1 : j == 2 ? 1 : 0;
                    y += j == 1 ? 1 : j == 3 ? -1 : 0;
                    if(x >= 0 && x < H && y >= 0 && y < W && map[x][y])
                    {
                        map[x][y] = false;
                        break;
                    }
                }
            }
        }
    }

    int count = 0;
    for(auto& row : map)
        for(bool cell : row)
            if(cell) count++;

    cout << count << endl;

    return 0;
}