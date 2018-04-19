#include<iostream>
#include<math.h>
using namespace std;


void sort(int* a, int*b, int n)
{
	int i,j,temp,k;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{	
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{	
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}

}

int main()
{
	int n,i;
	cout<<"\nNumber of digits"<<endl;
	cin>>n;

	int a[n],b[n],A,B,C;
	cout<<"\nEnter a "<<n<<" digit number to begin with"<<endl;
	cin>>A;
	cout<<endl;

	C=A;
	x:
	for(i=0;i<n;i++)
	{
		a[i]=A%10;
		b[i]=a[i];
		A=A/10;
	}
	
	
	sort(a,b,n);		//Sorts a is ascending and b in descending order
	A=B=0;
	for(i=0;i<n;i++)	//Converting array to number
	{
		A+=pow(10,i)*a[n-i-1];
		B+=pow(10,i)*b[n-i-1];
	}
	cout<<B<<" - "<<A<<" = "<<B-A<<endl;

	if(B-A==C)
	{	cout<<endl<<C<<" is the "<<n<<" digit Kaprekar constant"<<endl<<endl<<endl;
		return 0;
	}
	C=B-A;
	A=C;
	goto x;

}
