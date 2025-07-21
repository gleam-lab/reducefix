#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    long long N, M;
    cin >> N >> M;
    vector<Point> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
    }

    // Sort pieces to process them in order of their coordinates
    sort(pieces.begin(), pieces.end(), [](const Point &a, const Point &b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    // x + y
    vector<long long> sumXPlusY(N + 1, 0);
    // x - y
    vector<long long> sumXMinusY(N + 1, 0);
    vector<long long> maxSumXPlusY(N + 1, 0);
    vector<long long> maxSumXMinusY(N + 1, 0);

    for (const auto &p : pieces) {
        sumXPlusY[p.x + p.y]++;
        sumXMinusY[p.x - p.y]++;
        maxSumXPlusY[p.x + p.y] = max(maxSumXPlusY[p.x + p.y], maxSumXPlusY[p.x + p.y - 1] + 1);
        maxSumXMinusY[p.x - p.y] = max(maxSumXMinusY[p.x - p.y], maxSumXMinusY[p.x - p.y - 1] + 1);
    }

    long long result = N * N;
    for (int i = 0; i <= N; ++i) {
        result -= max(maxSumXPlusY[i], maxSumXMinusY[i]);
    }

    cout << result << endl;
    return 0;
}