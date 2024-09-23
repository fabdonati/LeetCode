class Solution:
    def numTrees(self, n: int) -> int:
        numTree = [1]*(n+1)
        
        for nodes in range(2,n+1): # loop over all elements except 0,1
            total = 0
            for root in range(1,nodes+1): # for each root up to the element above
                left = root-1 # consider left as the root-1 (left part goes on the left as it needs to be smaller than root)
                right = nodes-root # consider right part 
                total += numTree[left]*numTree[right]
            numTree[nodes] = total
        return numTree[n]
                