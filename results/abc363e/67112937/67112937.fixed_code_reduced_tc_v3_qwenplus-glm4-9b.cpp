#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> P;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int MAXN = 1005;

int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<P> pq;

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int main() {
    cin >> H >> W >> Y;
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the priority queue with the edges
    for (int i = 0; i < W; i++) {
        pq.push({A[0][i], 0, i});
        visited[0][i] = true;
    }
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = true;
    }
    for (int i = 0; i < W; i++) {
        pq.push({A[H-1][i], H-1, i});
        visited[H-1][i] = true;
    }
    for (int i = 0; i < H; i++) {
        pq.push({A[i][W-1], i, W-1});
        visited[i][W-1] = true;
    }

    int remainingArea = H * W;
    while (Y--) {
        vector<P> newPq;
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            if (p.first <= Y) { // If the section will sink this year
                remainingArea--;
                for (int d = 0; d < 4; d++) {
                    int nx = p.second + dx[d], ny = p.third + dy[d];
                    if (isValid(nx, ny) && !visited[nx][ny] && A[nx][ny] <= Y) {
                        newPq.push_back({A[nx][ny], nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            } else {
                newPq.push_back(p);
            }
        }
        swap(pq, newPq);
    }
    cout << remainingArea << endl;

    return 0;
}