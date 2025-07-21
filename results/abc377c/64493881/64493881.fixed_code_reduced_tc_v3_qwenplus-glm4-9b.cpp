#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> positions;
    vector<long long> x_mins(N+1, N), y_mins(N+1, N);
    vector<long long> x_maxs(N+1, 0), y_maxs(N+1, 0);

    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        positions.push_back({x, y});

        x_mins[min(x-2, N-1)] = min(x_mins[min(x-2, N-1)], y-1);
        x_maxs[max(x+1, 0)] = max(x_maxs[max(x+1, 0)], y+2);
        y_mins[min(y-2, N-1)] = min(y_mins[min(y-2, N-1)], x-1);
        y_maxs[max(y+1, 0)] = max(y_maxs[max(y+1, 0)], x+2);
    }

    long long count = 1;
    for (long long i = 1; i < N; ++i) {
        count *= x_maxs[i] - x_mins[i] + 1;
        if (count == 0) break;
        count *= y_maxs[i] - y_mins[i] + 1;
        if (count == 0) break;
    }

    cout << count * N * N - positions.size() << endl;

    return 0;
}