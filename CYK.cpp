#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,A,B,C,t,r;
	char a;
	int G[10][3];
	int T[10][2];
	char s[100];
	
	cout<<"Enter no.of non-terminls in grammar\n";
	cin>>r;
	cout<<"Enter no.of rules of form A1=>A2A3\n";
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cout<<"Enter Rule"<<i<<endl;
		//cin>>a;
		cin>>G[i][0];
		cin>>G[i][1]>>G[i][2];
		
	}
	cout<<"Enter no.of rules of form A1=>a\n";
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Enter Rule"<<i<<endl;
		cin>>T[i][0];
		cin>>a;
		T[i][1]=int(a)-'a'+1;
	}
	
	
	cout<<"Enter the  string:\n";
	cin>>s;
	int n=strlen(s);
	
	bool P[10][10][10];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=r;k++)
			{
				P[i][j][k]=false;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=t;j++)
		{
			//cout<<j<<" "<<T[j][1]<<" "<<int(s[i])-'a'+1<<" "<<T[j][0]<<endl;
			if(T[j][1]==int(s[i-1])-'a'+1)
			{
				P[1][i][T[j][0]]=true;
				cout<<1<<i<<T[j][0]<<endl;
			}
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			for(int k=1;k<=i-1;k++)
			{
				for(int p=1;p<=m;p++)
				{
					A=G[p][0];
					B=G[p][1];
					C=G[p][2];
					
					if(P[k][j][B]&&P[i-k][j+k][C])
					{
						 P[i][j][A]=true;
					}
				}	
				
			}
		}
	}
	
	if(P[n][1][1])
	{
		cout<<"given string can be generated by grammar G\n";
	}
	else
	{
		cout<<"given string cannot be generated by grammar G\n";
	}
	
}