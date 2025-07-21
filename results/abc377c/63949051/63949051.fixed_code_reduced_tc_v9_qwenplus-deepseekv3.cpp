#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> threatened;
    set<pair<long long, long long>> pieces_set;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces_set.insert({a, b});

        // Check all 8 possible moves
        if (a + 2 <= N && b + 1 <= N) {
            threatened.insert({a + 2, b + 1});
        }
        if (a + 1 <= N && b + 2 <= N) {
            threatened.insert({a + 1, b + 2});
        }
        if (a - 1 >= 1 && b + 2 <= N) {
            threatened.insert({a - 1, b + 2});
        }
        if (a - 2 >= 1 && b + 1 <= N) {
            threatened.insert({a - 2, b + 1});
        }
        if (a - 2 >= 1 && b - 1 >= 1) {
            threatened.insert({a - 2, b - 1});
        }
        if (a - 1 >= 1 && b - 2 >= 1) {
            threatened.insert({a - 1, b - 2});
        }
        if (a + 1 <= N && b - 2 >= 1) {
            threatened.insert({a + 1, b - 2});
        }
        if (a + 2 <= N && b - 1 >= 1) {
            threatened.insert({a + 2, b - 1});
        }
    }

    // The safe squares are N^2 - (threatened.size() + pieces_set.size())
    // because pieces_set contains the original positions of the pieces, which are also unsafe
    long long total_safe = N * N - threatened.size() - pieces_set.size();
    cout << total_safe << endl;

    return 0;
}