# ————二叉树————
tree = [0]
nb = 0
def father(x):
    return x//2
def leftSon(x):
    return 2*x
def rightSon(x):
    return 2*x+1
# ——————————————
# ————小根堆————
# 子节点总是比它的父节点要大，可用于维护一个数组的最小值
def Swap(x,y):
    global tree
    tmp = tree[y]
    tree[y]=tree[x]
    tree[x]=tmp
def UP(a):
    global tree
    if a == 1:# 注意二叉树的编号是从1开始的，因为若根是0，2*0 = 0
        return
    if tree[father(a)] >tree[a]:
        Swap(father(a),a)
        UP(father(a))

def DOWN(a):
    global tree,nb
    if leftSon(a)>nb:# 注意二叉树的编号是从1开始的，因为若根是0，2*0 = 0
        return
    tar = leftSon(a)
    if rightSon(a)<=nb and tree[tar]>tree[rightSon(a)]:
        tar = rightSon(a)
    if tree[tar] < tree[a]:
        Swap(tar,a)
        DOWN(tar)


    

def INSERT(tar):
    global tree,nb
    tree.append(tar)
    nb+=1
    UP(nb)
def DELETE(x):
    global tree,nb
    Swap(x,nb)
    tree.pop()
    nb-=1
    DOWN(x)

n = int(input())
for _ in range(n):
    a = list(map(int,input().split()))
    if a[0] ==1:
        INSERT(a[1])
    elif a[0] == 2:
        print(tree[1])
    else:
        DELETE(1)
