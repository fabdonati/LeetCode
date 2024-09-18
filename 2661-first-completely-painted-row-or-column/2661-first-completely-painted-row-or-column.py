class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        a = len(arr)
        m = len(mat)
        n = len(mat[0])
        map = {}
        for i in range(m):
            for j in range(n):
                map[mat[i][j]] = [i,j]
        
        rows = [0]*m
        cols = [0]*n

        for i in range(a):
            x = map[arr[i]]
            rows[x[0]] += 1
            cols[x[1]] += 1
            
            if rows[x[0]]==n or cols[x[1]]==m:
                return i