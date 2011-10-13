#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
#define N 1000
#define MAX 47483647
int arr[N][N];
int dist[N];
bool marked[N];
int n;
void init()
{
	for(int i=0;i<n;i++)
	{
		
		dist[i]=MAX;
		marked[i]=0;
	}
}
int getmin()
{
	int ret=-1;
	int min=MAX;
	for(int i=0;i<n;i++)
	{
		if(marked[i])continue;
		if(dist[i]<min)
		{
			min=dist[i];
			ret=i;
		}
	}
	return ret;
}
int djikstra()
{
	int add,extra1,k,mod,calc;
	while(1)
	{
		k=getmin();
		
		if(k==n-1)
		{
			return dist[k];
		}
		
		marked[k]=1;
		for(int i=0;i<n;i++)
		{
			if(marked[i])continue;
			//printf("yahan");
			if(arr[k][i]==0)continue;
			//printf("yahan2");
			extra1=(dist[k]/arr[k][i])%2;
			mod=dist[k]%arr[k][i];
			//printf("%d %d",extra1,mod);
			if(mod)
			{
				if(extra1)
				{
					if(k>i)
						add=2*arr[k][i]-mod;
					else
						add=arr[k][i]-mod;
				}
				else
				{
					if(k<i)
						add=2*arr[k][i]-mod;
					else
						add=arr[k][i]-mod;
				}
			}
			else
			{
				if(extra1)
				{
					if(k>i)add=0;
					else add=arr[k][i];
				}
				else
				{
					if(k<i)add=0;
					else add=arr[k][i];
				}
			}
			calc=arr[i][k]+dist[k]+add;
			if(dist[i]>calc)
				dist[i]=calc;
		}
	}

}
int main()
{
	scanf("%d",&n);
	init();
	int k,s,e;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&s);
		scanf("%d",&e);
		s--;
		e--;
		arr[s][e]=e-s;
		arr[e][s]=e-s;
		//printf("%d %d",arr[s][e],arr[e][s]);
	}
	//printf("here");
	
	dist[0]=0;
	int min=djikstra()*5;
	
	//dist[n-1]*=5;
	printf("%d",min);
	//while(1);
}			


