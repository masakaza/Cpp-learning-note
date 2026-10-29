# 07A · STL 常用容器详解

本篇配合 [STL 总览](07-stl.md) 学习。容器没有“绝对最好”，应根据访问方式、插入删除位置、是否需要排序和是否需要唯一键来选择。

## 1. 序列容器

### `vector`

动态数组，元素连续存储，支持快速下标访问。末尾添加通常很快；在中间插入或删除通常需要移动后续元素。

```cpp
std::vector<int> v{3, 1, 4};
v.push_back(2);
v.insert(v.begin() + 1, 9); // 在第二个元素前插入
v.erase(v.begin());          // 删除首元素
```

### `deque`

双端队列，支持两端高效插入/删除，支持下标访问。

```cpp
#include <deque>
std::deque<int> d{2, 3};
d.push_front(1);
d.push_back(4);
d.pop_front();
d.pop_back();
```

### `list`

双向链表，不支持 `list[i]`，也不能使用要求随机访问迭代器的 `std::sort`。在已取得位置迭代器时，插入和删除节点很方便。

```cpp
#include <list>
std::list<int> values{3, 1, 2};
values.push_front(0);
values.sort(); // list 自己的成员函数
values.remove(2); // 删除值为 2 的元素
```

## 2. 容器适配器：`stack`、`queue`、`priority_queue`

适配器只暴露特定操作接口，不提供普通序列容器的全部功能。

### `stack`：后进先出（LIFO）

```cpp
#include <stack>
std::stack<int> s;
s.push(10);
s.push(20);
std::cout << s.top(); // 20
s.pop();              // 只删除，不返回元素
```

常见接口：`push`、`pop`、`top`、`empty`、`size`。使用 `top()` 前先判断非空。

### `queue`：先进先出（FIFO）

```cpp
#include <queue>
std::queue<int> q;
q.push(10);
q.push(20);
std::cout << q.front(); // 10
q.pop();                // 删除队首，不返回元素
```

常见接口：`push`、`pop`、`front`、`back`、`empty`、`size`。它适合排队、任务缓存和消息缓冲等场景。

### `priority_queue`：优先队列

默认情况下，数值最大的元素优先出队。

```cpp
#include <queue>
std::priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);
std::cout << pq.top(); // 30
pq.pop();
```

若希望最小值优先，可写：

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
```

这行还需要包含 `<vector>` 和 `<functional>`。

## 3. 有序关联容器：`set` 与 `map`

### `set` / `multiset`

- `set`：元素自动按比较规则排序，且键唯一。
- `multiset`：允许重复键。
- 通常使用平衡搜索树实现，查找、插入、删除的复杂度一般为 `O(log n)`。

```cpp
#include <set>
std::set<int> s{3, 1, 2, 2};
for (int x : s) std::cout << x << ' '; // 1 2 3
if (s.find(2) != s.end()) std::cout << "找到了 2";
s.insert(4);
s.erase(1);
```

### `map` / `multimap`

`map` 保存键值对 `key -> value`，键唯一并按键排序。可以把它理解为“通过键查找对应的值”。

```cpp
#include <map>
#include <string>
std::map<std::string, int> scores;
scores["Alice"] = 95;  // 不存在时会创建键，并对 int 值进行值初始化
scores["Bob"] = 88;

for (const auto& item : scores) {
    std::cout << item.first << ": " << item.second << '\n';
}
```

- `item.first` 是键，`item.second` 是值。
- `map[key]` 在键不存在时会插入一个新元素，因此只查询、不想插入时可考虑 `find()` 或 `at()`。
- `multimap` 允许多个元素具有相同键，但不提供 `operator[]`。

## 4. 无序关联容器：`unordered_set` 与 `unordered_map`

基于哈希表，元素遍历顺序不保证按大小或插入顺序排列。查找、插入平均通常为 `O(1)`，但在哈希冲突严重时可能退化。

```cpp
#include <unordered_map>
#include <string>
std::unordered_map<std::string, int> inventory;
inventory["pen"] = 12;
inventory["book"] = 5;

if (inventory.find("pen") != inventory.end()) {
    std::cout << inventory.at("pen");
}
```

选择有序还是无序容器：需要稳定的键排序时使用 `map` / `set`；更关注平均查找速度且不依赖顺序时，可以考虑 `unordered_map` / `unordered_set`。

## 5. 容器对比速查

| 容器 | 访问方式 | 典型优势 | 注意点 |
|---|---|---|---|
| `vector` | 下标、迭代器 | 随机访问快，末尾追加方便 | 中间插入删除成本高，扩容会使迭代器失效 |
| `deque` | 下标、迭代器 | 两端操作方便 | 内存不保证连续 |
| `list` | 双向迭代器 | 已知位置的插入删除方便 | 无下标随机访问，额外节点开销 |
| `stack` | 只看栈顶 | 后进先出 | 不能遍历或随机访问 |
| `queue` | 队首/队尾 | 先进先出 | 不能随机访问 |
| `priority_queue` | 只看最高优先级 | 快速获取当前优先元素 | 默认最大值优先，不能直接遍历内部元素 |
| `set` | 迭代器、按键查找 | 键唯一且自动排序 | 插入/查找通常 `O(log n)` |
| `map` | 按键访问 | 键值映射且自动排序 | `operator[]` 可能插入新键 |
| `unordered_map` | 按键访问 | 平均查找通常 `O(1)` | 无序，复杂度存在最坏情况 |

## 6. `pair` 与 `map` 的关系

`std::pair<A, B>` 把两个值组合在一起，成员为 `first` 和 `second`。`map` 中每个元素就是键和值组成的 pair。

```cpp
#include <iostream>
#include <utility>
#include <string>
int main() {
    std::pair<std::string, int> student{"Alice", 95};
    std::cout << student.first << ' ' << student.second << '\n';
    auto another = std::make_pair(std::string("Bob"), 88);
}
```

## 7. 常见错误

1. 对空的 `stack` 调用 `top()`、对空的 `queue` 调用 `front()`、对空容器调用 `pop()`：先检查 `empty()`。
2. 认为 `pop()` 会返回删除的元素：不会，需要先读取 `top()` 或 `front()`。
3. 认为 `map[key]` 只是读取：键不存在时它会插入。
4. 对 `list` 使用 `list[i]` 或 `std::sort(list.begin(), list.end())`：不支持。使用 `list.sort()`。
5. 假定 `unordered_map` 遍历顺序固定：不要依赖其顺序。
