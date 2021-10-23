'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
# Write your code here
def arr():
    return []
def bfs(g,a,b,n):
    
    vis=[]
    q=[a]
    
    parent={}
    while(len(q)>0):
        t = q.pop(0)
        vis.append(t)
        n+=1
        for i in g.get(t,[]):
            if i not in vis:
                parent[i]=t
                if i==b:
                    return n+1,parent
                q.append(i)
    return -1,{}


n,m,t,c = map(int,input().split())

g = {}

for _ in range(m):
    a,b = map(int,input().split())
    if g.get(a)==None:
        g[a]=[]
    if g.get(b)==None:
        g[b]=[]
    g[a].append(b)
    g[b].append(a)

c,p=bfs(g,1,n,0)
print(c)
pp=[n]
s=n
while(p.get(s)!=None):
    pp.append(p.get(s))
    s=p.get(s)
pp.reverse()
print(" ".join(map(str,pp)))

