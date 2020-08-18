a=input().split()
n=int(a[0])
k=int(a[1])
count=0
arr=[0]*n
if n<=k:
    print('1')
else:
    for i in range(n):
        if i<k:
            arr[i]=1
            count+=1
        else:
            arr[i]=count
            count=count+arr[i]-arr[i-k]
    print(arr[n-1]%1000000007)