a = []
a = int(input())
x = int(input())
k = int(input())
#print(a,x,k)
maxn = 0
midx = 0
for i in range(k):
    for j in range(len(a)):
        if a[j]>maxn:
            maxn = a[j]
            midx = j
    a[midx] -= x
for j in range(len(a)):
    if a[j]>maxn:
        maxn = a[j]
print(maxn)