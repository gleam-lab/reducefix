#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // 假设有N个测试点
    vector<ll> P(N + 1), X(N); // P表示待处理的图中的权值，X表示节点的值
    P[0] = 0; // 所有节点初始值设为0
    rep(i, N) cin >> X[i]; // 读入每个节点的初始值
    
    // 处理边的添加操作，并存储在map中以便于后续查询
    map<ll, int> edge_map; // key为边的权值，value为对应的节点索引
    for (int i = 0; i < N - 1; ++i) { // 假设只存在一条边，不包括起始点或结束点
        ll p, q; // p和q为两个节点之间的边的权值
        cin >> p >> q; // 读入边权值
        edge_map[p] = i; // 将边存储在map中，便于后续查询
    }
    
    int Q; // 询问次数
    cin >> Q; // 读入询问次数
    while (Q--) { // 对于每个询问进行处理
        int L, R, l, r; // L和R分别为查询的两个节点，l和r分别为查询的区间范围
        cin >> L >> R; // 读入查询区间范围
        // 检查区间是否超出节点范围或边不存在于区间内
        if (L < 0 || R >= N || !edge_map.count(L)) { // 处理边界情况或边不存在的情况
            cout << "No Solution" << endl; // 输出没有解决方案
            continue; // 跳过询问继续下一个询问
        }
        // 根据区间范围查找对应的节点索引并计算区间内的权值差值
        int ans = P[R] - P[L]; // 计算区间内的权值差值
        cout << ans << endl; // 输出结果
    }
    return 0; // 程序正常结束
}