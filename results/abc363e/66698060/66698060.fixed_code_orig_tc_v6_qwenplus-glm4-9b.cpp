#include <bits/stdc++.h>
using namespace std;
#define ll long long

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> used;
vector<vector<pair<int, int>>> pq;

void initialize() {
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    used.resize(H, vector<bool>(W, false));
    pq.resize(H, vector<pair<int, int>>(W));
}

void findBoundary() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq[i][j] = {A[i][j], true}; // Boundary should be processed first
            } else {
                pq[i][j] = {A[i][j], false};
            }
        }
    }
    sort(pq.begin(), pq.end(), [](const pair<pair<int, int>, bool>& a, const pair<pair<int, int>, bool>& b) {
        return a.first > b.first;
    });
}

ll simulateYears() {
    ll ans = H * W;
    int currentSeaLevel = 0;
    while (currentSeaLevel < Y) {
        currentSeaLevel++;
        bool sink = false;
        while (!pq.empty() && pq.top().first <= currentSeaLevel) {
            auto top = pq.top();
            pq.pop();
            int r = top.first.first;
            int c = top.first.second;
            // Sink this cell
            used[r][c] = true;
            ans--;
            // Check neighbors
            if (r > 0 && !used[r-1][c] && A[r-1][c] <= currentSeaLevel) {
                pq.push({{A[r-1][c], r-1, c}, false});
            }
            if (r < H-1 && !used[r+1][c] && A[r+1][c] <= currentSeaLevel) {
                pq.push({{A[r+1][c], r+1, c}, false});
            }
            if (c > 0 && !used[r][c-1] && A[r][c-1] <= currentSeaLevel) {
                pq.push({{A[r][c-1], r, c-1}, false});
            }
            if (c < W-1 && !used[r][c+1] && A[r][c+1] <= currentSeaLevel) {
                pq.push({{A[r][c+1], r, c+1}, false});
            }
            sink = true;
        }
        if (sink) {
            sort(pq.begin(), pq.end(), [](const pair<pair<int, int>, bool>& a, const pair<pair<int, int>, bool>& b) {
                return a.first > b.first;
            });
        }
    }
    return ans;
}

int main() {
    initialize();
    findBoundary();
    ll remainingArea = simulateYears();
    for (int i = 1; i <= Y; i++) {
        cout << remainingArea << endl;
    }
    return 0;
}