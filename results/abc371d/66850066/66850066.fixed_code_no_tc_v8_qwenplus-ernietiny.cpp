#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N; // 假设有N个节点和相应的权重
    vector<long long> P(N + 1); // 存储所有节点权重初始化为long long类型
    cin >> P[0]; // 初始节点权重设为第一个节点权重

    // 读入所有节点的权重
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    // 根据给定的x坐标值找到对应的索引位置，用于后续计算节点间距离的差值
    unordered_map<int, int> x_to_ptr; // 使用unordered_map存储x坐标到节点索引的映射关系
    for (int i = 0; i < N; ++i) {
        x_to_ptr[P[i]] = i; // 将节点权重存储在对应的索引位置上
    }

    int Q; // 询问次数
    cin >> Q; // 读入询问次数

    // 处理每个询问的逻辑部分
    // ... 这里略过处理询问逻辑的部分 ...

    // 根据问题的要求，输出每个询问的答案
    // ... 这里根据问题的要求输出结果 ...

    return 0; // 返回0表示程序正常结束
}