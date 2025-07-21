#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to calculate the number of overlapping squares between two rows or columns
int overlapping_squares(int row1, int row2, int col1, int col2) {
    // Your implementation here
}

// Function to solve the problem
int solve(int N, int M, vector<pair<int, int>>& pieces) {
    // Calculate initial number of unsafe squares
    int unsafe_squares = 0;

    // Iterate over all pairs of pieces to calculate additional unsafe squares
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            // Calculate overlapping squares between piece i and piece j
            int overlap = overlapping_squares(pieces[i].first, pieces[j].first, pieces[i].second, pieces[j].second);
            // Update the count of unsafe squares
            unsafe_squares += overlap;
        }
    }

    // Calculate the number of safe squares
    int safe_squares = N * N - unsafe_squares;

    return safe_squares;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Solve the problem and output the result
    int result = solve(N, M, pieces);
    cout << result << endl;

    return 0;
}