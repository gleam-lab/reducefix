#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Input the elevations and initialize the priority queue
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            visited[i][j] = false;
            // Start with the borders and any sections <= the initial sea level
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1 || a[i][j] <= 0) {
                visited[i][j] = true;
                pq.emplace(a[i][j], make_pair(i, j));
            }
        }
    }

    int total_area = h * w;
    int years_passed = 0;

    while (!pq.empty() && years_passed < y) {
        years_passed++;
        int current_level = pq.top().first;
        pq.pop();

        // Process all sections that are about to sink
        while (!pq.empty() && pq.top().first == current_level) {
            auto [i, j] = pq.top().second;
            pq.pop();

            // Check all adjacent sections and update the queue and visited array
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && a[ni][nj] <= current_level) {
                        visited[ni][nj] = true;
                        pq.emplace(a[ni][nj], make_pair(ni, nj));
                    }
                }
            }
        }

        // Calculate the remaining area
        int remaining_area = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << endl;
    }

    return 0;
}