#include <bits/stdc++.h>
using namespace std;

struct Element {
    int max_val, sum_val;
};

bool compare(Element e1, Element e2) {
    return e1.max_val * e2.sum_val > e2.max_val * e1.sum_val;
}

vector<Element> elements;

void addElement(int a, int b) {
    elements.emplace_back(a, b);
}

long long calculateMinValue(int k) {
    sort(elements.begin(), elements.end(), compare);
    vector<long long> prefix_sum(k + 1), max_values(k + 1);
    long long result = LLONG_MAX;
    
    for(int i = 1; i <= k; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + elements[i - 1].sum_val;
        max_values[i] = max(max_values[i - 1], (long long)elements[i - 1].max_val);
        result = min(result, max_values[i] * prefix_sum[i]);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        elements.clear();

        for(int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            addElement(a, b);
        }

        cout << calculateMinValue(k) << "\n";
    }

    return 0;
}