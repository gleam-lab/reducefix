#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000000 + 1; // Maximum value for N
const int MAX_M = 200000 + 1;     // Maximum value for M

vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    long long n, m;
    cin >> n >> m;

    // Used to keep track of occupied cells
    vector<int> used(MAX_N * MAX_N + 2, 0);
    
    long long ans = n * n; // Total number of cells

    for (long long i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        // Mark the current piece and the 8 possible moves it can make
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                used[x * n + y] = 1;
            }
        }
    }

    // Subtract the number of occupied cells from the total
    for (long long i = 1; i <= MAX_N * MAX_N + 1; ++i) {
        if (used[i]) {
            ans--;
        }
    }

    cout << ans << endl;

    return 0;
}