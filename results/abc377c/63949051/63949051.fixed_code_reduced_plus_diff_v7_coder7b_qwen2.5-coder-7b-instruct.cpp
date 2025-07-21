#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long piece_num;
    cin >> piece_num;

    set<pair<long long, long long>> anti_dup;

    for (long long i = 1; i <= piece_num; ++i) {
        long long a, b;
        cin >> a >> b;
        anti_dup.insert({a, b});

        auto check_and_add = [&](long long x, long long y) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                anti_dup.insert({x, y});
            }
        };

        check_and_add(a + 2, b + 1);
        check_and_add(a + 1, b + 2);
        check_and_add(a - 1, b + 2);
        check_and_add(a - 2, b + 1);
        check_and_add(a - 2, b - 1);
        check_and_add(a - 1, b - 2);
        check_and_add(a + 1, b - 2);
        check_and_add(a + 2, b - 1);
    }

    long long total_positions = N * N;
    long long invalid_positions = anti_dup.size();
    
    out(total_positions - invalid_positions);
    return 0;
}