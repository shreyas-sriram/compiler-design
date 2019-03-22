#include<stdio.h>
int nblock=0,edg=0,G[100][100],visited[1000],gen[100][100],kill[100][100],nstat=-1,in[100][100],out[100][100],flagout[100],temp[100][100],l;
struct dir
{
	char val[100];
	int no;
}di;
struct block
{
	int nos;
	struct dir di[100];
}b[100];
void DFS(int i,char ch,int p)
{
    int j,k;
    if(i!=p)
    {
    	for(k=0;k<b[i].nos;k++)
    	{
    		if(b[i].di[k].val[0]==ch)
    		{
    			kill[p][b[i].di[k].no-1]=1;
    		}
    	}
    }		
    visited[i]=1;
	
    for(j=0;j<nblock;j++)
      	if(!visited[j]&&G[i][j]==1)
        	DFS(j,ch,p);
}
int main()
{
	int i,j,a,c,k;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			gen[i][j]=0;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			kill[i][j]=0;
	printf("\nEnter number of blocks:");
	scanf("%d",&nblock);
	for(i=0;i<nblock;i++)
	{
		printf("\nEnter the number of statements for the block %d:",i+1);
		scanf("%d",&b[i].nos);
		printf("\nEnter the statements one by one:\n");
		for(j=0;j<b[i].nos;j++)
		{
			printf("\nEnter the directive number:");
			scanf("%d",&b[i].di[j].no);
			if(b[i].di[j].no>nstat)
				nstat=b[i].di[j].no;
			gen[i][b[i].di[j].no-1]=1;
			printf("\nEnter the directive:");
			scanf("%s",&b[i].di[j].val);
		}
	}
	for(i=0;i<nblock;i++)
	{
		for(j=0;j<nstat;j++)
		{
			printf("%d\t",gen[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter number of edges:");
	scanf("%d",&edg);
	for(i=0;i<nblock;i++)
		for(j=0;j<nblock;j++)
			G[i][j]=0;
	for(i=0;i<nblock;i++)
        	visited[i]=0;
	for(i=0;i<edg;i++)
	{
		printf("\nEnter the block numbers having an edge:");
		scanf("%d%d",&a,&c);
		G[a-1][c-1]=1;
	}
	//KILL
	for(i=0;i<nblock;i++)
	{
		for(j=0;j<b[i].nos;j++)
		{
			for(k=0;k<nblock;k++)
        		visited[k]=0;
			DFS(i,b[i].di[j].val[0],i);
		}
	}
	for(i=0;i<nblock;i++)
	{
		for(j=0;j<nstat;j++)
		{
			printf("%d\t",kill[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//PassIN-OUT
	for(i=0;i<nblock;i++)
	{
		flagout[i]=0;
		for(j=0;j<nstat;j++)
		{
			in[i][j]=0;
			out[i][j]=0;
			temp[i][j]=0;
		}
	}
	for(i=1;;i++)
	{
		if(i==1)
		{
			printf("\nINITIAL:\n");
			printf("\nIN\n");
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					printf("%d\t",in[j][k]);
				}
				printf("\n");
			}
			//OUT
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					out[j][k]=((in[j][k]&(1-kill[j][k]))|gen[j][k]);
				}
			}
			printf("\nOUT\n");
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					printf("%d\t",out[j][k]);
					temp[j][k]=out[j][k];
				}
				printf("\n");
			}
		}
		else
		{
			//IN
			printf("\nPASS %d\n",i-1);
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					for(l=0;l<nblock;l++)
					{
						if(G[l][j]==1)
						{
							in[j][k]=out[l][k]|in[j][k];
						}
					}
					out[j][k]=((in[j][k]&(1-kill[j][k]))|gen[j][k]);
				}
			}
			printf("\nIN\n");
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					printf("%d\t",in[j][k]);
				}
				printf("\n");
			}
			printf("\nOUT\n");
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					printf("%d\t",out[j][k]);
				}
				printf("\n");
			}
			int ff=0;
			for(j=0;j<nblock;j++)
			{
				for(k=0;k<nstat;k++)
				{
					if(temp[j][k]!=out[j][k])
					{
						ff=1;
						break;
					}
				}
			}
			if(ff!=1)
			{
				break;
			}
			else
			{
				for(j=0;j<nblock;j++)
				{
					for(k=0;k<nstat;k++)
					{
						temp[j][k]=out[j][k];
					}
				}
			}
		}
	}
}