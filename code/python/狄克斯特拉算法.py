# 实现Dijstra's 算法
# 1.创建图
# 散列表中包含散列表，存储邻居和前往邻居的开销
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
graph["a"] = {}
graph["a"]["end"] = 1
graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["end"] = 5
graph["end"] = {}
# 2.创建存储开销的散列表
infin = float("inf")
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["end"] = infin
# 3.存储父节点的散列表
parents = {}
parents["a"] = "start"
parents["b"] = "end"
parents["end"] = None
# 4.创建一个数组，用于记录被处理的结果
processsed = []


# 找到开销最低的节点
def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processsed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node


node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] = node
    processsed.append(node)
    node = find_lowest_cost_node(costs)