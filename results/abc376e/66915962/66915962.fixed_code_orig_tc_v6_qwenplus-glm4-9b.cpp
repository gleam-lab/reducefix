#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i].first >> p[i].second;
        }
        sort(p.begin(), p.end(), greater<pair<int, int>>());
        int sumB = 0, maxA = p[0].first;
        for (int i = 0; i < K; i++) {
            sumB += p[i].second;
            maxA = max(maxA, p[i].first);
        }
        cout << maxA * sumB << endl;
    }
    return 0;
}