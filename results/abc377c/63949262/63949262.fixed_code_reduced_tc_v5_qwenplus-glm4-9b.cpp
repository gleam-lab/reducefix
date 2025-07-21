#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captureSet;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // Add the squares that can be captured by the piece at (a, b)
        captureSet.insert({a - 2, b - 1});
        captureSet.insert({a - 1, b - 2});
        captureSet.insert({a + 1, b - 2});
        captureSet.insert({a + 2, b - 1});
        captureSet.insert({a + 2, b + 1});
        captureSet.insert({a + 1, b + 2});
        captureSet.insert({a - 1, b + 2});
        captureSet.insert({a - 2, b + 1});
    }

    // The number of safe squares is the total squares minus the number of captured squares
    cout << N * N - captureSet.size() << endl;

    return 0;
}