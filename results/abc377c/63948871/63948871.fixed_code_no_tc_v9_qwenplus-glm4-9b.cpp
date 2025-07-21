#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    vector<vector<bool>> can_place(N + 1, vector<bool>(N + 1, true));
    for (long long i = 1, a, b; i <= M; ++i) {
        cin >> a >> b;
        can_place[a][b] = false;

        // Check the 8 possible capture positions
        if (a + 2 <= N && b + 1 <= N) can_place[a + 2][b + 1] = false;
        if (a + 1 <= N && b + 2 <= N) can_place[a + 1][b + 2] = false;
        if (a - 1 >= 1 && b + 2 <= N) can_place[a - 1][b + 2] = false;
        if (a - 2 >= 1 && b + 1 <= N) can_place[a - 2][b + 1] = false;
        if (a - 2 >= 1 && b - 1 >= 1) can_place[a - 2][b - 1] = false;
        if (a - 1 >= 1 && b - 2 >= 1) can_place[a - 1][b - 2] = false;
        if (a + 1 <= N && b - 2 >= 1) can_place[a + 1][b - 2] = false;
        if (a + 2 <= N && b - 1 >= 1) can_place[a + 2][b - 1] = false;
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (can_place[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}