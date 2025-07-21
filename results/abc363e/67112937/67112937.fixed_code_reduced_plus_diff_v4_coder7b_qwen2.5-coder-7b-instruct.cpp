#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    vector<int> lakeFormation(vector<vector<int>>& A, int Y) {
        int H = A.size(), W = A[0].size();
        vector<int> ans(Y);
        set<pii> q;
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                q.insert(pii(A[i][j], i * W + j));
            }
        }
        while(!q.empty()){
            auto it = begin(q);
            int h = it->first, idx = it->second;
            q.erase(it);
            ans[h-1]++;
            for(auto &d : dir){
                int ni = idx / W + d[0], nj = idx % W + d[1];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                auto it2 = q.find(pii(A[ni][nj], ni * W + nj));
                if(it2 != end(q)){
                    q.erase(it2);
                    ans[h-1]++;
                }
            }
        }
        return ans;
    }
};