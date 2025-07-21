#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int h; // height
    vector<Point> adj; // adjacent points
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > 0) {
                pq.push({A[i][j], {{i, j}}});
                if (i > 0) pq.push({A[i][j], {{i - 1, j}}});
                if (j > 0) pq.push({A[i][j], {{i, j - 1}}});
                if (i < H - 1) pq.push({A[i][j], {{i + 1, j}}});
                if (j < W - 1) pq.push({A[i][j], {{i, j + 1}}});
            }
        }
    }

    int remaining_area = H * W;
    for (int year = 1; year <= Y; ++year) {
        int sea_level = year;
        while (!pq.empty() && pq.top().h <= sea_level) {
            Edge e = pq.top(); pq.pop();
            for (Point p : e.adj) {
                if (!visited[p.x][p.y]) {
                    visited[p.x][p.y] = true;
                    remaining_area--;
                    for (Point np : A[p.x][p.y].adj) {
                        if (A[np.x][np.y] > sea_level && !visited[np.x][np.y]) {
                            pq.push({A[np.x][np.y], A[np.x][np.y].adj});
                        }
                    }
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}