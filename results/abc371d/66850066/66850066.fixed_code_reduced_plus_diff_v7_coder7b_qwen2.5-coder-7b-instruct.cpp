#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> X(N);
    for(int i = 0; i < N; ++i) cin >> X[i];

    vector<long long> prefix_sum(N + 1);
    for(int i = 0; i < N; ++i) prefix_sum[i + 1] = prefix_sum[i] + X[i];

    map<long long, int> pos_map;
    for(int i = 0; i < N; ++i) pos_map[X[i]] = i;

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;

        auto lb = pos_map.lower_bound(L);
        auto ub = pos_map.upper_bound(R);

        long long sum = 0;
        if(lb != pos_map.end()) sum += prefix_sum[lb->second + 1];
        if(ub != pos_map.begin()) sum -= prefix_sum[(--ub)->second];

        cout << sum << '\n';
    }

    return 0;
}