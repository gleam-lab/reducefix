#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // åå§åå¯æ¾ç½®ä½ç½®æ°éä¸º N^2
    long long free_squares = N * N;

    // éåæ¯ä¸ªæ£å­ï¼æé¤æå¨çè¡ãååå¯¹è§çº¿
    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first;
        int y = pieces[i].second;

        // æé¤è¡ååä¸­çæ¹æ ¼
        if (x > 1) free_squares -= (N - 1);
        if (y > 1) free_squares -= (N - 1);

        // æé¤å¯¹è§çº¿ä¸çæ¹æ ¼
        // å¯¹è§çº¿ i + j = x + y
        if (x + y > 1) free_squares -= (N - (x + y - 1));
        // å¯¹è§çº¿ i - j = x - y
        if (x - y > 1) free_squares -= (N - (x - y - 1));
    }

    cout << free_squares << endl;

    return 0;
}