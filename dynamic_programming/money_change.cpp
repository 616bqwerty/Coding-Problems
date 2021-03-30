//The minimum number of coins with denominations 1, 3, 4 that changes money.
#include <iostream>
using namespace std;

int main() {
    int n,low,x,y,z;
    cin>>n;
    x=0;
    low=n;
    while(x<=n)
    {
        y=0;
        while(y<=n)
        {
            z=0;
            while(z<=n)
            {
                if(3*x+4*y+z==n)
                {
                    if(x+y+z<low)
                        low=x+y+z;
                }
                z++;
            }
            y++;
        }
        x++;
    }
    cout<<low;
	return 0;
}
