#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

#define MAXN 1000000000 // Maximum possible value for N

// Helper function to mark captured cells
void markCapturedCells(const vector<int>& a, const vector<int>& b, bitset<MAXN> &canCapture) {
    for (int i = 0; i < a.size(); ++i) {
        int x = a[i];
        int y = b[i];

        // Check all possible capture positions
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 1 && nx <= MAXN && ny >= 1 && ny <= MAXN) {
                canCapture.set((nx - 1) * MAXN + (ny - 1));
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    // Use a bitset to mark captured cells
    bitset<MAXN> canCapture;
    fill(canCapture.begin(), canCapture.end(), 0);

    // Mark captured cells for each piece
    markCapturedCells(a, b, canCapture);

    // Calculate the number of safe cells
    int count = 0;
    fill(canCapture.begin(), canCapture.end(), 0); // Reset the bitset
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!canCapture.test((i - 1) * MAXN + (j - 1))) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}