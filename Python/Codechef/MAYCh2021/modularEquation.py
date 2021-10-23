import sys


def Ints(): return map(int, sys.stdin.readline().strip().split())
def Strs(): return map(str, sys.stdin.readline().strip().split())
def Array(): return list(map(int, sys.stdin.readline().strip().split()))
def Str(): return sys.stdin.readline().strip()
def Int(): return int(sys.stdin.readline().strip())
def MOD(): return 1000000007

def modd(m,a,b):
    return ((m%a)%b)==((m%b)%a)

t=Int()
for _ in range(t):
    n,m = Ints()
    od = 0
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if (modd(m,i,j)):
                print(m,i,j)
                od+=1
    print(od)