#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // 假设 N 是一个合法的输入值
    vector<ll> P(N + 1), X(N); // P 是一个以 X[i] 为值的向量，初始值为 X 的元素
    P[0] = 0; // X[0] 可能被意外忽略了，所以设置为0
    rep(i, N) cin >> X[i]; // 读入每个 X[i]
    
    // 其他代码保持不变...
    int Q; // 询问次数
    cin >> Q; // 读入询问次数
    
    // 处理询问逻辑，基于查询区间和索引来更新结果
    for (int q = 0; q < Q; ++q){ // 处理每个询问
        int L, R; // 查询左边界和右边界
        cin >> L >> R; // 读入查询的左右边界
        auto L_ptr = x_to_ptr.lower_bound(L); // 获取左边界对应的索引
        auto R_ptr = x_to_ptr.upper_bound(R); // 获取右边界对应的索引
        if (L_ptr == end(x_to_ptr)) { // 如果左边界不在映射中，则直接返回错误或异常处理
            cout << "Invalid query" << endl; // 处理错误情况
            continue; // 跳过当前询问并继续下一个询问的处理
        }
        // 根据查询区间更新 P 值并计算结果
        int ans = P[R] - P[L]; // 更新结果并输出
        cout << ans << endl; // 输出结果
    }
    return 0; // 程序正常结束
}