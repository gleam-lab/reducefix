#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    set<pair<int, int>> pieces;

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Check all possible moves of a knight
        if (a + 2 <= N && b + 1 <= N) pieces.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) pieces.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) pieces.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) pieces.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) pieces.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) pieces.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) pieces.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) pieces.insert({a + 2, b - 1});
    }

    // Total squares minus the squares occupied by pieces and their captures
    cout << (long long)N * N - pieces.size() << endl;

    return 0;
}