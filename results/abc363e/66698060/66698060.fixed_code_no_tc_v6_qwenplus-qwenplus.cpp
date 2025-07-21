#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vl years(y + 2); // years[i] will store the number of cells submerged at level i
    vl heights(h * w);
    ll idx = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ll a;
            cin >> a;
            heights[idx++] = a;
        }
    }

    sort(heights.begin(), heights.end());
    
    // Initialize all cells as land
    vl count(100001, 0);
    for (auto& h : heights) {
        count[h]++;
    }

    // Prepare prefix sums to get how many cells are <= sea level
    vl prefix(100001);
    prefix[0] = count[0];
    for (ll i = 1; i <= 100000; ++i) {
        prefix[i] = prefix[i - 1] + count[i];
    }

    // Simulate multi-source BFS with priority queue
    priority_queue<vl, vector<vl>, greater<vl>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<ll>> grid(h, vector<ll>(w));

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Push all boundary cells into the priority queue
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({grid[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    vl sea_level(Y + 2);
    for (ll i = 1; i <= Y; ++i) {
        sea_level[i] = i;
    }

    vl res(Y + 2, 0);
    ll total_cells = h * w;

    // To process each sea level in order
    vl current_sea_level;
    for (ll i = 0; i <= Y; ++i) {
        current_sea_level.push_back(i);
    }

    ll cur_idx = 0;
    vl remaining(total_cells + 1, total_cells);

    // Use BFS to simulate flood fill
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll height = top[0];
        ll x = top[1];
        ll y = top[2];

        for (ll k = 0; k < 4; ++k) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (height <= Y) {
                    years[height]--;
                }
                pq.push({grid[nx][ny], nx, ny});
            }
        }

        // Update how many cells are flooded at this height
        if (height <= Y) {
            years[height]++;
        }
    }

    // Compute cumulative sum of flooded cells up to year i
    vl flooded_up_to(Y + 2);
    for (ll i = 1; i <= Y; ++i) {
        flooded_up_to[i] = flooded_up_to[i - 1] + years[i];
        cout << h * w - flooded_up_to[i] << endl;
    }

    return 0;
}