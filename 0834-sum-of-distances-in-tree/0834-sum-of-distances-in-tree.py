class Solution:
    def __init__(self):
        self.adj = []
        self.sum = []
        self.cnt = []
    
    def build_adj(self, n, edges):
        self.adj = [[] for _ in range(n)]
        for e in edges:
            v, w = e[0], e[1]
            self.adj[v].append(w)
            self.adj[w].append(v)
    
    def dfs0(self, i, parent=None):
        for j in self.adj[i]:
            if j == parent:
                continue
            self.dfs0(j, i)
            self.cnt[i] += self.cnt[j]
            self.sum[i] += self.sum[j] + self.cnt[j]  # subtree for root=i
    
    def reroot(self, i, parent, n):
        for j in self.adj[i]:
            if j == parent:
                continue
            self.sum[j] = self.sum[i] + n - 2 * self.cnt[j]
            self.reroot(j, i, n)
    
    def sumOfDistancesInTree(self, n, edges):
        self.build_adj(n, edges)
        self.sum = [0] * n
        self.cnt = [1] * n
        self.dfs0(0)
        self.reroot(0, -1, n)
        return self.sum

# Initializer for faster IO
def init():
    import sys
    sys.stdin = open(0)
    sys.stdout = open(1, 'w')
    sys.stderr = open(2, 'w')
    return 'c'

init()        