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

    set<pair<long long, long long>> forbidden;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        if (a + 2 <= N && b + 1 <= N) {
            forbidden.insert({a + 2, b + 1});
        }
        if (a + 1 <= N && b + 2 <= N) {
            forbidden.insert({a + 1, b + 2});
        }
        if (a - 1 >= 1 && b + 2 <= N) {
            forbidden.insert({a - 1, b + 2});
        }
        if (a - 2 >= 1 && b + 1 <= N) {
            forbidden.insert({a - 2, b + 1});
        }
        if (a - 2 >= 1 && b - 1 >= 1) {
            forbidden.insert({a - 2, b - 1});
        }
        if (a - 1 >= 1 && b - 2 >= 1) {
            forbidden.insert({a - 1, b - 2});
        }
        if (a + 1 <= N && b - 2 >= 1) {
            forbidden.insert({a + 1, b - 2});
        }
        if (a + 2 <= N && b - 1 >= 1) {
            forbidden.insert({a + 2, b - 1});
        }
    }

    long long total = N * N;
    long long forbidden_count = forbidden.size();
    long long ans = total - forbidden_count;

    cout << ans << endl;

    return 0;
}