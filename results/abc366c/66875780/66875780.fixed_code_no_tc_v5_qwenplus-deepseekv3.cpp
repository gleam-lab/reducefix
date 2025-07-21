#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve() {
    int Q;
    cin >> Q;
    unordered_map<int, int> count_map;
    int distinct_count = 0;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (count_map[x] == 0) {
                distinct_count++;
            }
            count_map[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (count_map[x] == 1) {
                distinct_count--;
            }
            count_map[x]--;
        } else if (type == 3) {
            cout << distinct_count << "\n";
        }
    }
}

int main() {
    fastIO();

    int t = 1;
    while (t--) {
        Solve();
    }

    return 0;
}