# class NaryTree:
#     def __init__(self,parent=None) -> None:
#         self.isLock=False
#         self.isLocable = True
#         self.parent=None
#         self.children=[]
    
# def Lock(node:NaryTree):
#     if not node.isLocable:
#         return
#     t = node
#     flag = False
#     while(t!=None):
#         if(t.isLock):
#             flag = True
#             break 
#         t=t.parent
#     if flag:
#         return
#     else:
#         node.isLock=True
#         t=node
#         while(t!=None):
#             t.isLocable = False
#             t=t.parent
# def Unlock(node:NaryTree):
#     if not node.isLock:
#         return 
#     node.isLock = False
#     t=node
#     while(t!=None):
#         t.isLocable = True
#         t=t.parent

# if __name__ == "__main__":
#     root = NaryTree()
#     ch1 = NaryTree(root)
#     ch2 = NaryTree(root)
#     ch3 = NaryTree(root)

#     root.children +=[ch1,ch2,ch3]
#     Lock(ch3)
#     print(ch3.isLocable)
#     Lock(ch1)
#     print(ch1.isLocable)
#     Unlock(ch3)
#     print(ch3.isLocable)
#     print(ch3.isLocable)
#     Lock(ch1)
#     print(ch1.isLocable)
    
class MaryTree:
    __children=None
    __nChild=None
    def __init__(self,value) -> None:
        self._isLocked=False
        self._isLocable = True
        self._value=value
        self.__children=[]   
        self.lockedBy=None
    def add(self,node):
        self.__children.append(node)
    def numOfChildren(self):
        return len(self.__children)
    def children(self):
        return self.__children
    def lock(self,value):
        self._isLocked = value
    def lockable(self,value):
        self._isLocable = value
    def value(self):
        return self._value
    def isLocked(self):
        return self._isLocked
    def isLockable(self):
        return self._isLocable
    
def get(t,m):
    if t.numOfChildren()<m:
        return t
    sub = [i for i in t.children()]
    for i in sub:
        if i.numOfChildren()<m:
            return i
        else:
            sub+=[i for i in i.children()]
def printTree(t):
    if t!=None:
        print(t.value())
        printList = t.children()

        for i in printList:
            print(i.value())
            printList+=i.children()

def Lock(node:MaryTree,uid):
    if not node.isLockable():
        return False
    t = node
    flag = False
    child = [i for i in t.children()]
    for i in child:
        if(i.isLocked() and i.lockedBy!=uid):
            flag = True
            break         
        child+=[ii for ii in i.children()]
    if flag:
        return False
    else:
        node.lock(True)
        node.lockedBy=uid
        node.lockable(False)
        temp=[i for i in node.children()]
        for i in temp:
            i.lockable(False)
            temp+=[ii for ii in i.children()]
        return True


def Unlock(node:MaryTree,uid):
    if not node.isLocked():
        return False
    if node.lockedBy !=uid:
        return False
    node.lock(False)
    node.lockedBy=None
    node.lockable(True)
    t=[i for i in node.children()]
    for i in t:
        i.lockable(True)
        t+=[ii for ii in i.children()]
    return True

def upgradeLock(node:MaryTree,uid):
    flag = False
    child = [i for i in node.children()]
    upgrade=[]
    for i in child:
        if i.isLocked():
            if i.lockedBy!=uid:
                flag = True
                break        
            else:
                upgrade.append(i)
        child+=[ii for ii in i.children()]
    if flag:
        return False
    else:
        for i in upgrade:
            Unlock(i,uid)
        return Lock(node,uid)



n=int(input())
m=int(input())
q=int(input())
root=None
temp=None
nodes={}
for i in range(n):
    t=input()
    tNode = MaryTree(t)
    nodes[t]=tNode
    if i==0:
        root=tNode
        temp = root
    elif temp.numOfChildren()<m:
        temp.add(tNode)
    else:
        temp = get(root,m)
        temp.add(tNode)

for i in range(q):
    op,node,id = map(str,input().split())
    if op=="1":
        print(Lock(nodes[node],id))
    elif op=="2":
        print(Unlock(nodes[node],id))
    elif op=="3":
        print(upgradeLock(nodes[node],id))

    