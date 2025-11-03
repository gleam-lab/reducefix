#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll=int64_t;
using ld=long double;
int inf=1000000001;
ll INF=1e18;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (ll)x.size()
template<typename T>bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    rep(i,H)rep(j,W)cin>>A[i][j];
    
    // We'll simulate the flooding in increasing order of sea level
    // Instead of processing year-by-year with nested queues, use one BFS with events
    
    int total = H * W;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    // Initially, all border cells are adjacent to the sea
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            pq.push({A[i][j], i, j});
            submerged[i][j] = true;
        }
    }
    
    vector<int> result(Y + 1); // result[y] = area after y years
    int remaining = total - pq.size();
    
    // Process cells in order of their elevation (when they get submerged)
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top(); pq.pop();
        
        // This cell gets submerged when sea level reaches elev
        // So it affects years >= elev
        if (elev <= Y) {
            // All years from 'elev' onwards lose this cell
            // But we want per-year output, so we record when each cell is lost
            // Instead: we simulate year by year using the priority queue
            // Actually, better: process all cells that submerge at or below current sea level
            // We'll instead do offline simulation: handle each year incrementally
        }
    }
    
    // Better approach: let's rework completely.
    // We want for each year y (from 1 to Y), the number of cells with value > y 
    // AND still connected to the interior without being cut off by lower boundary?
    // No: the flooding spreads: any cell with elevation <= sea level that is connected 
    // (through other <= sea level cells) to the border gets flooded.

    // Correct idea: reverse time. Start from high sea level and go backwards? 
    // Or: for each year y, we can do BFS from borders with condition A[i][j] <= y, but Y up to 1e5 and H,W up to 1000 -> 1e6*1e5 = 1e11 operations.

    // Instead: offline approach. Sort cells by elevation. Process from low to high.
    // When sea level reaches 'h', all cells with elevation <= h on the border start flooding,
    // and flood spreads to adjacent cells with elevation <= h.

    // We can simulate increasing sea levels and maintain the set of submerged cells.
    // Use union-find or just BFS per sea level? But sea level goes to 1e5, we can't do BFS for each.

    // Alternate: process elevations in increasing order. At sea level = h, we add:
    //   - any border cell with A[i][j] == h
    //   - then flood from existing submerged area to any neighbor with A[i][j] <= h
    // But we need to do it incrementally.

    // Let's maintain a queue for BFS. We will iterate h from 1 to Y.
    // Also keep a global submerged grid.
    // At sea level h, we check all cells with A[i][j] == h that are adjacent to already submerged region or on border.

    // But how to quickly find A[i][j] == h? We can pre-sort.

    // Revised plan:
    // 1. Pre-group coordinates by elevation.
    // 2. Maintain a deque or queue for BFS of currently active frontier.
    // 3. For h from 1 to Y:
    //    - Add all border cells with A[i][j] == h (but might be already added?) -> no, only if not submerged
    //    - Actually: at sea level h, any cell with A[i][j] <= h that is connected to border gets flooded.
    //    - So we can maintain a BFS queue that contains all cells that are submerged and can flood neighbors.
    //    - Initially, at h=0, nothing is submerged.
    //    - For h from 1 to Y:
    //        a. Add all cells (i,j) with A[i][j] == h that are on the border and not yet submerged -> add to queue and mark
    //        b. Also, during the BFS, when we have a submerged cell with neighbor (ni,nj) with A[ni][nj] <= h and not submerged, add it.
    //        c. But note: a cell with A[ni][nj] < h might not have been processed because we didn't see it at its own level? 
    //           Actually, we should have processed it earlier.
    //
    // However, a cell with A[i][j] = k < h should have been considered at sea level k.
    // But if it was not connected to the border until now? Then it wouldn't have been flooded.
    //
    // Actually, flooding happens simultaneously: when sea level is h, all cells with elevation <= h that are connected to the sea (via other <= h cells) sink.
    // So we cannot do it incrementally by adding only A[i][j]==h.
    //
    // Instead, we do:
    //   Use a min-heap (priority queue) that stores (elevation, i, j) for cells that are candidates to be flooded.
    //   Start by pushing all border cells with their elevation.
    //   Then, while the smallest elevation in heap <= current sea level h, pop and flood it, then push its unvisited neighbors.
    //   But we want to answer for every h from 1 to Y.
    //
    // We can simulate h from 1 to Y, and at each step, pop all cells with elevation <= h from the heap.
    //
    // Algorithm:
    //   Let's have a min-heap: priority_queue<tuple<int,int,int>, vector<...>, greater<...>> pq; // (elev, i, j)
    //   submerged[H][W] array.
    //   Initially, push all border cells with their elevation, mark them as to-be-submerged (but not yet counted per year).
    //   Then for h from 1 to Y:
    //       While pq not empty and top.elev <= h:
    //           Pop cell (elev,i,j)
    //           If already submerged, skip.
    //           Else, mark as submerged, decrement remaining count, and push all un-submerged neighbors into pq.
    //       Record remaining count for year h.
    //
    // This way, we process each cell once.
    //
    // Note: a cell might be pushed multiple times? But we check if already submerged before processing.
    // To avoid duplicates, we could mark when pushing, but then a cell with high elevation might block a low one? 
    // Actually, we should only push a neighbor when we flood its parent, and only if not already in the queue or submerged.
    // But to keep it simple, we can allow duplicates and check at pop time.
    //
    // Since H*W <= 1e6, and each cell has 4 neighbors, total operations ~ 4e6, which is acceptable.

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> is_submerged(H, vector<bool>(W, false));
    int remaining = H * W;

    // Directions: only up, down, left, right
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    // Initialize: add all border cells
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
            }
        }
    }

    // We'll store answers for each year
    vector<int> ans(Y+1); // ans[h] for year h

    // Process each sea level from 1 to Y
    for (int h = 1; h <= Y; h++) {
        // Process all cells that can be submerged at sea level h
        while (!pq.empty()) {
            auto [elev, i, j] = pq.top();
            if (elev > h) break; // cannot submerge yet
            pq.pop();

            if (is_submerged[i][j]) continue; // already processed

            // Submerge this cell
            is_submerged[i][j] = true;
            remaining--;

            // Check neighbors
            rep(d,4) {
                int ni = i + dr[d];
                int nj = j + dc[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (!is_submerged[ni][nj]) {
                        pq.push({A[ni][nj], ni, nj});
                    }
                }
            }
        }
        ans[h] = remaining;
    }

    // Output for each year from 1 to Y
    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}