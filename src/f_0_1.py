# check if value repeated twice in a list, move it on the left / right of the list
def moveToRight(arr:list)->None:
  seen = set()
  l = 0
  r = 0
  while True:
    while r<len(arr) and arr[r] in seen:
      r += 1
    if r==len(arr): break
    seen.add(arr[r])
    arr[l], arr[r] = arr[r], arr[l]
    l += 1
  print(arr)

arr = [1,7,4,8,2,6,8,3,7,9,10]
print(arr)
moveToRight(arr)
arr.sort()
def checkIncreasing(l:list)->bool:
  return all(x<y for x,y in zip(l,l[1:]))
def checkNonDecreasing(l:list)->bool:
  return all(x<=y for x,y in zip(l,l[1:]))

print(checkIncreasing(arr))
print(checkNonDecreasing(arr))

finalList = []
dic = {0:[0,1,2], 1:2, 2:5, 3:[4,5,7]}

def flattenList(l:list)->list:
  flatList = []
  for el in l:
    if isinstance(el, list):
      flatList.extend(flattenList(el))
    else:
      flatList.append(el)
  return flatList

ll = [0,1,2],2,3,[4,5,7]
flattenList(ll)
list1 = flattenList(dic.values())
print(list1)

