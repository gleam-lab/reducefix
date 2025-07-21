#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e9 + 7;

struct Item {
    int a, b;
};

bool cmp(Item &a, Item &b) {
    return a.a > b.a || (a.a == b.a && a.b < b.b);
}

int solve(int n, int k, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    int res = INF;
    long long sum_b = 0;
    for (int i = 0; i < n; ++i) {
        sum_b += items[i].b;
        if (i >= k - 1) {
            res = min(res, (long long)items[i].a * sum_b);
            sum_b -= items[i + 1 - k].b;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Item> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].a >> items[i].b;
        }
        cout << solve(n, k, items) << '\n';
    }
    return 0;
}