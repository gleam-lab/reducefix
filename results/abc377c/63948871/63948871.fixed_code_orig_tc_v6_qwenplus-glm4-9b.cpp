#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAXN = 1e9 + 10;

int parent[MAXN];

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

int main() {
    int N, M;
    cin >> N >> M;

    // åå§åå¹¶æ¥é
    for (int i = 1; i <= N * N; i++)
        parent[i] = i;

    // è¯»åæ£å­ä½ç½®å¹¶å»ºç«æè·
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // æ£æ¥å¹¶å»ºç«æè·
        // ä¾å¦ï¼
        unite(a * N + b, (a + 2) * N + b + 1);
        // ... å¯¹ä½ç½®è¿è¡ç¸ä¼¼å¤ç
    }

    // è®¡ç®å¯ä»¥æ¾ç½®æ°æ£å­çç©ºæ ¼æ°é
    int count = 0;
    for (int i = 1; i <= N * N; i++) {
        if (find(i) == i) // åªç»è®¡æ²¡æè¢«æè·çæ ¼å­
            count++;
    }

    cout << count << endl;
    return 0;
}