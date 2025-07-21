#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int t, n, k, a[MAXN], b[MAXN];

struct Node {
    int value, index;
};

// Comparator function to sort nodes based on their values in descending order
bool cmp(Node &p1, Node &p2) {
    if (p1.value != p2.value) return p1.value > p2.value;
    return p1.index < p2.index;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            nodes[i] = {a[i], i};
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort nodes based on 'a' values in descending order
        sort(nodes.begin(), nodes.end(), cmp);

        int max_a = 0, sum_b = 0, ans = INT_MAX;
        set<int> selected_indices;

        // Initialize the first K elements
        for (int i = 0; i < k; ++i) {
            max_a = max(max_a, nodes[i].value);
            sum_b += b[nodes[i].index];
            selected_indices.insert(nodes[i].index);
        }

        ans = max_a * sum_b;

        // Try to replace one element with another
        for (int i = k; i < n; ++i) {
            if (!selected_indices.count(nodes[i].index)) {
                continue;
            }

            // Find an element that can be replaced
            int replace_index = -1;
            for (int j = 0; j < k && replace_index == -1; ++j) {
                if (!selected_indices.count(j)) {
                    replace_index = j;
                }
            }

            if (replace_index != -1) {
                int new_max_a = max(max_a, nodes[i].value);
                int old_sum_b = sum_b - b[replace_index] + b[nodes[i].index];
                ans = min(ans, new_max_a * old_sum_b);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}