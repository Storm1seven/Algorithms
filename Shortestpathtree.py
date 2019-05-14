import heapq
from collections import defaultdict
from sys import stdin
input = stdin.readline
def SPT(adjacency_list, src, v):
    heap = []
    visited = set([])
    spt = []
    total = 0
    max_dist = 10**9
    dist={i: max_dist for i in range(1, v+1)}
    dist[src] = 0
    heapq.heappush(heap, [0, 0, src, 0])
    while heap:
        first_dist, weight, vertex, edge_num = heapq.heappop(heap)
        if vertex not in visited:
            spt.append(edge_num)
            total+=weight
            visited.add(vertex)
            for _vertex, _weight, _edgenum in adjacency_list[vertex]:
                if _vertex not in visited:
                    dist[_vertex] = min(dist[_vertex], first_dist+_weight)
                    heapq.heappush(heap, [first_dist+_weight, _weight, _vertex, _edgenum])
    return (spt, total, dist)