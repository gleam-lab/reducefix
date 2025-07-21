#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long M;
    cin >> M;

    set<pair<int, int>> reachable;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        
        // Add the piece itself
        reachable.insert({a, b});
        
        // Check cells that can capture this piece
        if (a + 2 <= N && b + 1 <= N) {
            reachable.insert({a + 2, b + 1});
        }
        if (a + 1 <= N && b + 2 <= N) {
            reachable.insert({a + 1, b + 2});
        }
        if (a - 1 >= 0 && b + 2 <= N) {
            reachable.insert({a - 1, b + 2});
        }
        if (a - 2 >= 0 && b + 1 <= N) {
            reachable.insert({a - 2, b + 1});
        }
        if (a - 2 >= 0 && b - 1 >= 0) {
            reachable.insert({a - 2, b - 1});
        }
        if (a - 1 >= 0 && b - 2 >= 0) {
            reachable.insert({a - 1, b - 2});
        }
        if (a + 1 <= N && b - 2 >= 0) {
            reachable.insert({a + 1, b - 2});
        }
        if (a + 2 <= N && b - 1 >= 0) {
            reachable.insert({a + 2, b - 1});
        }
    }

    // Total cells minus the cells that are in the capture range
    cout << N * N - reachable.size();
    return 0;
}