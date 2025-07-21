#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;

int N, M;
vector<pair<int, int>> pieces; // Stores the pieces' positions
vector<vector<int>> captureAreas; // Stores the rows and columns that are affected by captures

int main() {
    cin >> N >> M;
    pieces.resize(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        pieces[i] = {a, b};
        captureAreas.push_back({a, a, b, b}); // Capture in row and column
        captureAreas.push_back({a, b, a, b}); // Capture in diagonal (a+b)
        captureAreas.push_back({a, 3 * N - b - 1, b, 3 * N - a - 1}); // Capture in diagonal (a-b)
    }

    sort(captureAreas.begin(), captureAreas.end());

    int totalValidPositions = N * N;
    for (int i = 0, j = 0; i < captureAreas.size(); ++i) {
        while (j < captureAreas.size() && captureAreas[j][0] <= captureAreas[i][1]) {
            ++j;
        }
        // Calculate the number of affected positions
        int rowStart = max(captureAreas[i][0], 0);
        int rowEnd = min(captureAreas[i][2], N);
        int colStart = max(captureAreas[i][1], 0);
        int colEnd = min(captureAreas[i][3], N);
        totalValidPositions -= (rowEnd - rowStart + 1) * (colEnd - colStart + 1);

        // Skip all overlapping areas
        while (j < captureAreas.size() && captureAreas[j][0] <= captureAreas[i][2]) {
            ++j;
        }
    }

    cout << totalValidPositions << endl;
    return 0;
}