#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> segments;
    int current_length = 0;
    bool is_segment_open = false;

    for (int i = 0; i < n; ++i) {
        if ((s[i] == '<' || s[i] == '^') && !is_segment_open) {
            is_segment_open = true;
            current_length = 0;
        } else if ((s[i] == '>' || s[i] == 'v') && is_segment_open) {
            is_segment_open = false;
            segments.push_back(current_length);
            current_length = 0;
        } else if (is_segment_open) {
            current_length++;
        }
    }

    long long total_length = 0;
    for (int length : segments) {
        total_length += length;
    }

    long long ans = total_length;

    for (size_t i = 1; i < segments.size() - 1; ++i) {
        if (segments[i] > 1 && segments[i - 1] > 1 && segments[i + 1] > 1) {
            ans--;
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}