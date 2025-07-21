#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(x) (x).begin(), (x).end()

int dx[] = {1, -1, 0, 0}; // 添加缺失的dy数组定义
int dy[] = {0, 0, 1, -1}; // 以及dy数组的初始化

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    P[0] = 0; // 初始化前缀和数组P[0]为0
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // 读取X数组的值
        P[i + 1] = P[i] + X[i]; // 计算前缀和并存储在P数组中
    }
    // 使用有序集合(set)来存储X值和对应的索引，以便快速查找和二分搜索
    multiset<int> X_values; // 存储X值的有序集合
    for (int i = 0; i < N; ++i) {
        X_values.insert(X[i]); // 将X值插入集合中
    }
    // 查询处理部分代码... (保持不变)
    // ... 这里是您原有的查询处理逻辑 ...
    // ... 但请确保正确处理边界情况，如当X值不在map中时返回正确的值 ...
    // ... 例如，当L或R超出了X值的范围时，应返回相应的边界值 ...
    // ... 此处代码略去具体实现 ...
    return 0; // 主函数返回0表示程序正常结束
}