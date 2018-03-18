#include <bits/stdc++.h>
#include<random>
using namespace std;
int main(int argc, char const *argv[])
{
	random_device rand_dev;
    mt19937 generator(rand_dev());
    
	int n,p;
	cout<<"Enter number of flights"<<endl;
	cin>>n;
	cout<<"Enter x, if probability of dying on 1 flight is 1/x"<<endl;
	int x;cin>>x;
	uniform_int_distribution<int> distr(1, x);
	p=x/(rand()%3+1);
	cout<<"Wait, going through 10000 iterations of "<<n<<" flights"<<endl;
	int a=0,i=0;
	for(;i<=9999;i++)
	{
		bool flag=true;
		for(int j=0;j<n;j++)
		{
    		int t= distr(generator);
			if(t==p)
			{
				a++;
				flag=false;
				//cout<<i+1<<" "<<"DEAD"<<endl;
				break;
			}
		}
		if(flag)
		{
			//cout<<i+1<<" "<<"ALIVE"<<endl;
		}
	}
	cout<<"Deaths: "<<a<<endl;
	cout<<"Iterations: "<<i<<endl;
	cout<<"The probability of you dying in "<<n<<" flights is "<<float(a)/float(i)*100<<"%"<<endl;
	return 0;
}