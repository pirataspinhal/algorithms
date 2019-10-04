"""
Depth first search algorithm
"""
from search.depth_first.graph import Graph


def dfs(graph: Graph, source: str, target: str):
    """
    Given a graph and a source node, find a target using Depth-first search

    Great for traversing directed acyclic graphs, and thus job scheduling.
    """
    visited = [source]
    path = []
    steps = 1
    while visited:
        node = visited.pop()
        if node == target:
            print(f'Found {target} in {steps} steps')
            return
        if node in path:
            continue
        path.append(node)
        for neighbour in graph.neighbours(node):
            visited.append(neighbour)
            steps += 1