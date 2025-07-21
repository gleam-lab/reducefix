#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        long long a = pieces[i].first;
        long long b = pieces[i].second;
        attacked.insert((a - 1) * N + b); // Mark the piece's position as attacked
    }

    for (const auto& p : pieces) {
        long long a = p.first;
        long long b = p.second;

        // Check all 8 possible knight moves
        if (a + 2 <= N && b + 1 <= N) {
            attacked.insert((a + 1) * N + (b + 1 - 1));
        }
        if (a + 1 <= N && b + 2 <= N) {
            attacked.insert((a + 1 - 1) * N + (b + 2 - 1));
        }
        if (a - 1 >= 1 && b + 2 <= N) {
            attacked.insert((a - 1 - 1) * N + (b + 2 - 1));
        }
        if (a - 2 >= 1 && b + 1 <= N) {
            attacked.insert((a - 2 - 1) * N + (b + 1 - 1));
        }
        if (a - 2 >= 1 && b - 1 >= 1) {
            attacked.insert((a - 2 - 1) * N + (b - 1 - 1));
        }
        if (a - 1 >= 1 && b - 2 >= 1) {
            attacked.insert((a - 1 - 1) * N + (b - 2 - 1));
        }
        if (a + 1 <= N && b - 2 >= 1) {
            attacked.insert((a + 1 - 1) * N + (b - 2 - 1));
        }
        if (a + 2 <= N && b - 1 >= 1) {
            attacked.insert((a + 2 - 1) * N + (b - 1 - 1));
        }
    }

    long long total = N * N;
    long long unsafe = attacked.size();
    long long safe = total - unsafe;

    cout << safe << endl;

    return 0;
}