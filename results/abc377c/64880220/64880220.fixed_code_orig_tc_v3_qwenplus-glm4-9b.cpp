#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Placeholder for the union-find data structure
    // This should have functions to find and unite sets efficiently

    // Initialize occupied_squares set
    unordered_map<long long, unordered_map<long long, int>> occupied;

    // Check capture conditions for each piece
    for (auto& p : pieces) {
        long long x = p.first;
        long long y = p.second;
        // Check all 8 possible capture moves
        // If any of these moves are within the bounds of the grid and hit an occupied square,
        // then mark this square and any square it can move to as occupied
        // This logic needs to be implemented within the union-find framework
    }

    // Calculate the total number of squares that can be occupied
    // Subtract the occupied count from the total number of squares (N*N)
    long long total_squares = N * N;
    long long occupied_squares = 0; // This would be set to the correct value after the above logic

    cout << total_squares - occupied_squares << endl;

    return 0;
}