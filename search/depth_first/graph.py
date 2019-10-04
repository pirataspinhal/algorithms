"""
Simple graph class
"""
from typing import Dict, List


class Graph:
    """
    A graph represented by a dictionary of adjacency lists
    """
    def __init__(self):
        self.edges = {}

    def neighbours(self, node: str) -> List:
        return self.edges[node]

    def __str__(self) -> Dict:
        return self.edges

    def __unicode__(self) -> Dict:
        return self.edges

    def __repr__(self) -> Dict:
        return self.edges
