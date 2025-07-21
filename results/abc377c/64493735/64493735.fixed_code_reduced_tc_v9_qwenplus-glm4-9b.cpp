#include <iostream>
#include <vector>
using namespace std;

int solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }

    long long totalSpots = (long long)N * N;
    long long capturedSpots = 0;

    // Process each piece
    for (int i = 0; i < M; i++) {
        int x = a[i] - 1; // Convert to 0-based index
        int y = b[i] - 1;
        // Check all possible capturing positions
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    // Calculate the total number of spots captured by this piece
                    capturedSpots += (long long)(min(N - 1 - nx, abs(dx)) * min(N - 1 - ny, abs(dy)));
                }
            }
        }
    }

    // Calculate the number of spots that can be placed without being captured
    cout << totalSpots - capturedSpots << endl;
    return 0;
}

int main() {
    solve();
    return 0;
}