#include <bits/stdc++.h>
using namespace std;
struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using Pi = pair<int, int>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep3(i,l,r) for(int i = (l); i < (r); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define el '\n'

int main(){
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    vvi used(H, vi(W, 0));
    
    // Priority queue to process cells in increasing order of elevation
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    
    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        used[i][0] = 1;
        used[i][W-1] = 1;
    }
    rep3(i, 1, W-1) {
        pq.push({A[0][i], 0 * W + i});
        pq.push({A[H-1][i], (H-1) * W + i});
        used[0][i] = 1;
        used[H-1][i] = 1;
    }
    
    int remaining = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vi results;
    
    while (!pq.empty() && pq.top().first <= Y) {
        auto [elevation, pos] = pq.top();
        pq.pop();
        
        int r = pos / W, c = pos % W;
        
        // This cell will be submerged at year = elevation
        // Record that one more cell is lost at this elevation
        while ((int)results.size() < elevation) {
            results.push_back(remaining);
        }
        remaining--;
        
        // Check neighbors
        rep(d, 4) {
            int nr = r + dy[d], nc = c + dx[d];
            if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
            if (!used[nr][nc]) {
                used[nr][nc] = 1;
                pq.push({A[nr][nc], nr * W + nc});
            }
        }
    }
    
    // Fill in remaining years
    while ((int)results.size() < Y) {
        results.push_back(remaining);
    }
    
    // Output results for each year
    rep(i, Y) {
        cout << results[i] << el;
    }
}