# 07A · STL 常用容器详解与选择

本篇是 STL 容器的总览索引。每种容器的结构图、核心概念、可用数据操作接口和易错点已拆分到独立笔记，方便按主题学习。

## 1. 序列容器

| 容器 | 结构与特点 | 独立笔记 |
|---|---|---|
| `vector` | 连续动态数组，随机访问快 | [vector](07-stl-vector.md) |
| `string` | 自动管理字符序列，支持查找和拼接 | [string](07-stl-string.md) |
| `deque` | 双端队列，两端操作方便 | [deque](07-stl-deque.md) |
| `list` | 双向链表，已知位置插入删除方便 | [list](07-stl-list.md) |

## 2. 容器适配器

| 容器 | 访问规则 | 独立笔记 |
|---|---|---|
| `stack` | LIFO，后进先出，只访问栈顶 | [stack](07-stl-stack.md) |
| `queue` | FIFO，先进先出，只访问队首/队尾 | [queue](07-stl-queue.md) |
| `priority_queue` | 优先级最高的元素先访问，默认最大堆 | [priority_queue](07-stl-priority-queue.md) |

适配器只提供受限接口，不像 vector/list 一样提供迭代器供外部遍历。

## 3. 关联容器

| 容器 | 主要特点 | 独立笔记 |
|---|---|---|
| `set` / `multiset` | 按键排序；前者键唯一，后者允许重复 | [set / multiset](07-stl-set.md) |
| `map` / `multimap` | 按 key 排序保存键值对；multimap 允许重复 key | [map / multimap](07-stl-map.md) |
| `unordered_set` / `unordered_multiset` | 基于哈希表的集合 | [无序关联容器](07-stl-unordered.md) |
| `unordered_map` / `unordered_multimap` | 基于哈希表的键值映射 | [无序关联容器](07-stl-unordered.md) |

## 4. 工具类型

- [pair](07-stl-pair.md)：将两个可能不同类型的值组合成一个对象。它不是容器，但常用于 map 元素和 set/map 的插入返回结果。

## 5. 如何选择容器

| 需求 | 可优先考虑 |
|---|---|
| 频繁下标访问、尾部追加 | `vector` |
| 头尾都要频繁插入删除 | `deque` |
| 已知位置频繁插入删除，且不需要随机访问 | `list` |
| 后进先出 | `stack` |
| 先进先出 | `queue` |
| 每次取出当前最大/最小优先级 | `priority_queue` |
| 元素唯一且自动排序 | `set` |
| key-value 映射且按 key 排序 | `map` |
| 不要求顺序，关注平均查找效率 | `unordered_set` / `unordered_map` |

## 6. 学习建议

先掌握 vector 和 string，再学习 deque/list 的结构差异；随后学习 stack、queue 和 priority_queue 的访问规则；最后比较 set/map 与 unordered 系列。每篇独立笔记均列出对应容器可以使用的数据操作，不要把不同容器的接口混为一谈。

算法是独立于具体容器的一组通用操作，见 [STL 算法、迭代器与 lambda](07-stl-algorithms.md)。
