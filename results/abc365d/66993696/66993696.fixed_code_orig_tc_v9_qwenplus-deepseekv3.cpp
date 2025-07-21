#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> segments;
    for (int i = 0; i < n; ++i) {
        char c;
        scanf(" %c", &c);
        if (c == 'P') {
            segments.emplace_back(i, i);
        } else if (c == 'R') {
            segments.emplace_back(i, i + 1);
        } else if (c == 'S') {
            segments.emplace_back(i - 1, i + 1);
        }
    }

    if (segments.empty()) {
        printf("0\n");
        return 0;
    }

    sort(segments.begin(), segments.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 1;
    int last_end = segments[0].second;
    for (size_t i = 1; i < segments.size(); ++i) {
        if (segments[i].first >= last_end) {
            ++count;
            last_end = segments[i].second;
        }
    }

    printf("%d\n", count);
    return 0;
}