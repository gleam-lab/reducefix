# 最终数据集配置总结

## ✅ 完成时间
$(date)

## 数据集配置

### 项目和案例
- **php-src**: 1 case - arvo-51180
- **mupdf**: 5 cases - arvo-46541, 55076, 36500, 36519, 36463  
- **poppler**: 5 cases - arvo-25221, 29386, 22430, 8616, 20200

**总计**: 11 cases

## 选择标准

1. ✅ **单文件修改**: ground truth patch 只修改 1 个文件
2. ✅ **Testcase 大小**: > 4KB
3. ✅ **Patch 最小化**: 优先选择 patch 最小的案例（便于 APR）
4. ✅ **数据完整性**: testcase、metadata.json、fix.patch 全部就绪

## 数据完整性

| 项目 | Cases | Testcase | Metadata | Patch | Reduce 结果 |
|------|-------|----------|----------|-------|-------------|
| php-src | 1 | ✓ | ✓ | ✓ | ✓ (1/1) |
| mupdf | 5 | ✓ | ✓ | ✓ | ✓ (5/5) |
| poppler | 5 | ✓ | ✓ | ✓ | 🔄 (0/5, 运行中) |

## Poppler Testcase 补齐过程

由于 poppler 的 testcase 文件之前丢失（符号链接断裂），通过以下方式成功恢复：

1. 从 ARVO 元数据提取 testcase_id
2. 使用 curl 从 OSS-Fuzz 公开 URL 下载
3. 成功下载 7 个案例，选择 patch 最小的 5 个

### 下载的案例
- arvo-25221: 163,136 bytes (patch: 957B)
- arvo-29386: 12,066 bytes (patch: 2,484B)  
- arvo-22430: 16,297 bytes (patch: 5,012B)
- arvo-8616: 15,308 bytes (patch: 5,929B)
- arvo-20200: 56,760 bytes (patch: 6,034B)

## Reduce 任务状态

- ✅ php-src: 已完成
- ✅ mupdf: 已完成
- 🔄 poppler: 运行中（PID=1381970）
  - 日志: /tmp/reduce_poppler.log
  - 预计完成时间: ~1-2 小时

## 配置文件

- ✅ selected_large_cases.json: 11 cases
- ✅ project_groups.json: 3 projects  
- ✅ cases.json: 11 cases
- ✅ cases_data/: 11 个完整目录

## 监控命令

\`\`\`bash
# 查看 poppler reduce 进度
tail -f /tmp/reduce_poppler.log

# 检查任务状态
ps aux | grep run_complete_reducefix

# 检查 reduce 结果
bash /home/barty/research/reduce/oss_fuzz/check_reduce_status.sh
\`\`\`

## 下一步

等待 poppler reduce 任务完成后：
1. 验证所有 11 个 cases 都有 reduce 结果
2. 开始 APR 修复实验
