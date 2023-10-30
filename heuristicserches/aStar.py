import heapq
grid=[
    [1,1,1,0],
    [1,0,1,1],
    [1,1,0,1],
    [0,0,1,1],
    ]
unvisited=[[len(grid)*len(grid),0,0,0]]
target=[3,2]
visited=set()
ans=-1
parents={0:0}
def is_availble(li:list,x:int,y:int,a:int,b:int,grid:list)->bool:
    if a+li[0]<0 or a+li[0]>=x or b+li[1]<0 or b+li[1]>=x : 
        return False
    if grid[a+li[0]][b+li[1]]==0:
        return False
    return True
vec=[[1,0],[0,1],[-1,0],[0,-1]]
while len(unvisited):
    curr=heapq.heappop(unvisited)
    a=curr[2]
    b=curr[3]
    visited.add(a*len(grid)+b)
    if [a,b]==target:
        ans=[a,b]
        break
    dis=curr[1]+1
    for i in vec:
        if is_availble(i,len(grid),len(grid[0]),a,b,grid) and (a+i[0])*len(grid)+b+i[1] not in visited:
            parents[(a+i[0])*len(grid)+b+i[1]]=a*len(grid)+b
            heapq.heappush(unvisited,[dis+len(grid)-1-a-i[0]+len(grid)-1-b-i[1],dis,a+i[0],b+i[1]])
def getIndex(index:int,x:int):
    return [index//x,index%x]
if ans==-1:
    print("The element is not present in the grid")
else:
    i=ans[0]*len(grid)+ans[1]
    ans=[]
    while(parents[i]!=i):
        ans.append(getIndex(i,len(grid)))
        i=parents[i]
    ans.append(getIndex(i,len(grid)))
    print("The path will is as follow : ")
    ans.reverse()
    for i in ans:
        print(i)
