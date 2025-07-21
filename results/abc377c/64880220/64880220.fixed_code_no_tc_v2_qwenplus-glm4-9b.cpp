#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<Point> pieces(m);
    vector<vector<bool>> capture(n + 1, vector<bool>(n + 1, false));
    
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
        for (int j = 0; j < 8; ++j) {
            long long nx = pieces[i].x, ny = pieces[i].y;
            nx += (j % 2 == 0) ? 2 : 1;
            ny += (j % 4 < 2) ? 1 : -1;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                capture[nx][ny] = true;
            }
        }
    }
    
    long long non_capture_count = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!capture[i][j]) {
                non_capture_count++;
            }
        }
    }
    
    cout << non_capture_count << endl;
    
    return 0;
}