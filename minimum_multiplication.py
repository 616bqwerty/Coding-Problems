#compute m^x in minimum multiplications
def square(x):
    return x*x

def multiply(a,x):
    if x==0:
        return 1
    elif x%2==0:
        return square(multiply(a,x/2))
    else:
        return a*multiply(a,x-1)
a=int(input("Enter base "))
x=int(input("Enter power "))
y=multiply(a,x)
print(y)