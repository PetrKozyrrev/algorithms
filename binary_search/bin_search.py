n = int(input())
v = []

for i in range(n):
    a = int(input())
    v.append(a)

key = int(input())

l, r = 0, n
while r - l > 1:
    mid = (l + r) // 2
    if key >= v[mid]:
        l = mid
    else:
        r = mid

if key == v[l]:
    print("Yes")
else:
    print("No")