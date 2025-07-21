#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e18;

struct Data {
    int a, b, idx;
};

bool cmp(Data &a, Data &b) {
    return a.a > b.a || (a.a == b.a && a.b < b.b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Data> data(n);
        for (int i = 0; i < n; ++i) {
            cin >> data[i].a;
            data[i].idx = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> data[i].b;
        }
        sort(data.begin(), data.end(), cmp);

        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + data[i - 1].b;
        }

        long long ans = INF;
        for (int i = k - 1; i < n; ++i) {
            long long max_a = data[i].a;
            long long sum_b = prefix_sum[i + 1] - prefix_sum[i - k + 1] + data[i - k + 1].b;
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << endl;
    }
    return 0;
}