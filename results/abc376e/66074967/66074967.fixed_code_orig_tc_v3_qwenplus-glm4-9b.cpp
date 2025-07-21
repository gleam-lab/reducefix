#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<pair<int, int>> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });

        long long sum = 0, min_value = LLONG_MAX;
        for (int i = 0; i < K; ++i) {
            sum += a[i].second + 1;
            min_value = min(min_value, sum * a[i].first);
        }
        cout << min_value << endl;
    }
    return 0;
}