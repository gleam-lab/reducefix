#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    int M;
    cin >> M;

    set<pair<int, int>> forbidden;

    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;

        forbidden.insert({a, b});

        // Check all 8 directions
        auto addSquare = [&](int i, int j) {
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                forbidden.insert({i, j});
            }
        };

        addSquare(a + 2, b + 1);
        addSquare(a + 1, b + 2);
        addSquare(a - 1, b + 2);
        addSquare(a - 2, b + 1);
        addSquare(a - 2, b - 1);
        addSquare(a - 1, b - 2);
        addSquare(a + 1, b - 2);
        addSquare(a + 2, b - 1);
    }

    long long total = N * N;
    cout << (total - forbidden.size()) << endl;

    return 0;
}