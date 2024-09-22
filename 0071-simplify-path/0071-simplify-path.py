class Solution:
    def simplifyPath(self, path: str) -> str:
        delimiters = ['/','//', '///']
        for delimiter in delimiters:
            path = " ".join(path.split(delimiter))
        path = path.split()
        
        res = []
        for word in path:
            if word =='.':
                continue
            elif word =='..':
                res = res[:-1]
            else:
                res.append(word)
        output = "/".join(res)
        return '/'+output
        
            