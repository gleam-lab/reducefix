#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<pair<int, int>> queries;
vector<int> answers;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

void preprocess() {
    sort(a.begin(), a.end());
    vector<int> prefix(a.size() + 1, 0);
    for(int i = 0; i < a.size(); i++) {
        prefix[i + 1] = prefix[i] + (i > 0 ? a[i] - a[i - 1] : a[i]);
    }
    for(auto& query : queries) {
        int idx = lower_bound(a.begin(), a.end(), query.first) - a.begin();
        int rank = query.second;
        int left_sum = idx * rank - prefix[idx];
        int right_sum = prefix[a.size()] - prefix[idx] - (a.size() - idx) * rank;
        answers.push_back(left_sum + right_sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    queries.resize(q);
    for(int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i].first = b;
        queries[i].second = k - 1; // Adjusting for zero-based indexing
    }

    preprocess();

    for(int ans : answers)
        cout << ans << '\n';

    return 0;
}