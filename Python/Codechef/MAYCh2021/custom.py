# # '''
# # # Sample code to perform I/O:

# # name = input()                  # Reading input from STDIN
# # print('Hi, %s.' % name)         # Writing output to STDOUT

# # # Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
# # '''

# # # Write your code here
# # def path(m,s,d,l,vis):
# #     vis.append(s)
# #     for i in m.get(s,[]):
# #         if i not in vis:
# #             if(i==d):
# #                 l.append(s)

# #             else:
# #                 path(m,i,d,l,vis)
# #     return l
               
    
# # n=int(input())
# # m={}
# # for _ in range(n):
# #     m[int(input())]=[]
# # e = int(input())
# # for _ in range(e):
# #     u,v = map(int,input().split())
# #     m[u].append(v)
# #     # m[v].append(v)
# # print(" ".join(map(str,path(m,int(input()),int(input()),[],[]))))



# # '''
# # # Sample code to perform I/O:

# # name = input()                  # Reading input from STDIN
# # print('Hi, %s.' % name)         # Writing output to STDOUT

# # # Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
# # '''

# # # Write your code here
# # n=int(input())
# # m={}
# # l=[]
# # for _ in range(n):
# #     temp = int(input())
# #     m[temp]={}
# #     l.append(temp)
# # e=int(input())
# # for _ in range(e):
# #     u,v,d = map(int,input().split())
# #     m[u][v]=d

# # for k in l:
# #     for i in l:
# #         for j in l:
# #             if((m.get(i,{})).get(k,None)==None or (m.get(k,{})).get(j,None)==None):
# #                 continue
# #             d1=(m.get(i,{})).get(j,1e9)
# #             d2=(m.get(i,{})).get(k,1e9)
# #             d3=(m.get(k,{})).get(j,1e9)
# #             if(d1>d2+d3):
# #                 m[i][j]=d2+d3
# #             d1=(m.get(j,{})).get(i,1e9)
# #             d2=(m.get(j,{})).get(k,1e9)
# #             d3=(m.get(k,{})).get(i,1e9)
# #             if(d1>d2+d3):
# #                 m[j][i]=d2+d3



# # a=int(input())
# # b=int(input())
# # print(m.get(a,{}).get(b,-1))


# # '''
# # # Sample code to perform I/O:

# # name = input()                  # Reading input from STDIN
# # print('Hi, %s.' % name)         # Writing output to STDOUT

# # # Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
# # '''
# # def path(m,s,d,vis):
# #     vis.append(s)
# #     for i in m.get(s,[]):
# #         if i not in vis:
# #             if i==d:
# #                 return True
# #             elif path(m,i,d,vis):
# #                 return True
# #     return False
# # # Write your code here
# # n = int(input())
# # m={}
# # for _ in range(n):
# #     m[int(input())]=[]

# # e = int(input())
# # for _ in range(e):
# #     u,v = map(int,input().split())
# #     m[u].append(v)
# #     # m[v].append(u)

# # a= int(input())
# # b = int(input())
# # if path(m,a,b,[]):
# #     print(1)
# # else:
# #     print(0)



# #     '''
# # # Sample code to perform I/O:

# # name = input()                  # Reading input from STDIN
# # print('Hi, %s.' % name)         # Writing output to STDOUT

# # # Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
# # '''

# # # Write your code here
# # def path(m,s,d,l,vis):
# #     vis.append(s)
# #     for i in m.get(s,[]):
# #         if i not in vis:
# #             if(i==d):
# #                 l.append(s)

# #             else:
# #                 l=l+path(m,i,d,l,vis)
# #     return l
               
    
# # n=int(input())
# # m={}
# # for _ in range(n):
# #     m[int(input())]=[]
# # e = int(input())
# # for _ in range(e):
# #     u,v = map(int,input().split())
# #     m[u].append(v)
# #     m[v].append(v)
# # ans=list(set(path(m,int(input()),int(input()),[],[])))

# # ans.sort()
# # print(" ".join(map(str,ans)))

# import sys
# def Ints(): return map(int, sys.stdin.readline().strip().split())
# def Strs(): return map(str, sys.stdin.readline().strip().split())
# def Array(): return list(map(int, sys.stdin.readline().strip().split()))
# def Str(): return sys.stdin.readline().strip()
# def Int(): return int(sys.stdin.readline().strip())
# def MOD(): return 1000000007

# # n = Int()
# # for _ in range(n):
# #     d=list(map(int,input().split()))
# #     g = d[0]
# #     pd = d[1]
# #     i=11
# #     days=0
# #     nop = sum(d[g+2:])
# #     days+=nop//pd
# #     mdays=0
# #     mxdays=0 
# #     mmod = nop%pd
# #     if (mmod==0):
# #         if(d[g+1]%pd==0):
# #             mdays = days+1
# #             mxdays = days+1
# #         else:
# #             mdays = days+1
# #             mxdays = days+2
# #     else:
# #         if((mmod+d[g+1])%pd==0):
# #             mdays=days+1
# #             mxdays=days+1
# #         else:
# #             mdays = days+1
# #             mxdays = days+2

# #     print(mdays,mxdays)    
# # def isSafe(c,d,x,y):
# #     if(x>c or y>d):
# #         return False
    

# # def pathValue(a,b,c,d):
# #     x,y = a,b
# #     v=0
# #     for i in range(c+1):
# #         v+=d[i][0]
# #     for i in range(d+1):
# #         v+=d[c][i]
# #     print(v)
# # d=[]
# # j=0
# # i=0
# # col=2
# # tt=0
# # for i in range(1001):
# #     t=tt+1
# #     f=[0]*1001
# #     if(i==0):
# #         f[0]=1
# #     else:
# #         f[0]=d[i-1][0]+col
# #         col+=1
# #     for j in range(1,1001):
# #         f[j]=f[j-1]+t
# #         t+=1
# #     d.append(f)
# #     tt+=1
# # for i in d:
# #     print(i)
# # t=Int()
# # for _ in range(t):
# #     x1,y1,x2,y2 = map(int,input().split())
# #     pathValue(x1-1,y1-1,x2-1,y2-1)
# def swap(a,x,y):
#     t=a[x]
#     a[x]=a[y]
#     a[y]=t
#     return a

# def permute(a,p,n):
#     b=[0]*n
#     for i in range(n):
#         b[p[i]]=a[i]
#     return b

# def pri(a,x):
#     print(a[x])
# t= Int()
# for _ in range(t):
#     n=Int()
#     A=list(map(int,input().split()))
#     P=list(map(int,input().split()))
#     Q=Int()
#     for _ in range(Q):
#         l=list(map(int,input()))
#         if(l[0]==1):
#             A=permute(A,P,n)
#         elif(l[0]==2):
#             A=swap(A,l[0],l[1])
#         elif(l[0]==3):
#             pri(A,l[1])

import sys


def Ints(): return map(int, sys.stdin.readline().strip().split())
def Strs(): return map(str, sys.stdin.readline().strip().split())
def Array(): return list(map(int, sys.stdin.readline().strip().split()))
def Str(): return sys.stdin.readline().strip()
def Int(): return int(sys.stdin.readline().strip())
def MOD(): return 1000000007

t= Int()
for _ in range(t):
    d={}
    s,pn=Ints()
    ss=Array()
    d[1]={}
    for i in range(1,s+1):
        if(ss[i-1]==1):
            d[1][i]=0
            j=1
            while(j!=s):
                if d.get(j) == None:
                    d[j]={}
                d[j][j+1]=1
                
                j+=1
        elif(ss[i-1]==2):
            d[1][i]=0
            j=i
            while(j!=1):
                if d.get(j) == None:
                    d[j]={}
                d[j][j-1]=1
                j-=1
    # p=Array()
    print(d)

