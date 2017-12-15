/*
 * implement link state algorithom using given file as inout
 * and print the process as well as output
 *
 * Jingyuan Yi
 */

#include <stdio.h>
#define MAX         100                 // the max size of matrix
#define INF         9999        // infinity

typedef struct _gragh
{
	int vexnum; // number of nodes
	int matrix[MAX][MAX];
}Graph;


void dijkstra(Graph G,int start, int prev[],int dist[])
{
	int i,j,k;
	int min;
	int tmp;
	int flag[MAX]; //flag[i] = 1 represents I have get the shortest path from source to point i



	for(i=0;i<G.vexnum;i++){
		flag[i]=0;
		prev[i]=0;
		dist[i] = G.matrix[start][i];
		//printf("1 -> %d is %d\n",i+1,dist[i]);
	}

	//initialize source point
	flag[start] = 1;
	dist[start] = 0;


	for (i = 1; i < G.vexnum; i++)
	{

		
			min = INF;
			for (j = 0; j < G.vexnum; j++)
			{
					if (flag[j]==0 && dist[j]<min)
					{
							min = dist[j];
							k = j;
					}
			}
		
			flag[k] = 1;
			printf("Next node = %d\n",k+1);

			
			for (j = 0; j < G.vexnum; j++)
			{
					tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j])); 
					if (flag[j] == 0 && (tmp  < dist[j]) )
					{
							printf("Updating distance vector of node %d, New %d, Old %d\n",j+1,tmp,dist[j]);
							dist[j] = tmp;
							prev[j] = k;

					}
			}
			printf("\n");
	}
	printf("The final distances are:\n");
	for (i = 0; i < G.vexnum; i++)
					printf("1->%d = %d\n", i+1, dist[i]);

}




int main()
{
	//int nodes_num = 0; //number of nodes
	FILE *fp=NULL;
	Graph G;
	int i,j,c;
	int prev[MAX] = {0};
	int dist[MAX] = {0};

	//Graph initialization
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++){
			G.matrix[i][j]=INF;
			if(i==j){
			G.matrix[i][j]=0;
			}
		}
	}

	//reading network from files
	if((fp=fopen("networkGraph.txt","r"))==NULL)
	{
		printf("file open erro!");
		return -1;
	}

	fscanf(fp,"%d",&(G.vexnum));
	printf("number of node is %d\n",G.vexnum);
	while(!feof(fp))
	{
		fscanf(fp,"%d,%d,%d",&i,&j,&c);
		G.matrix[i-1][j-1]=c;
		G.matrix[j-1][i-1]=c;
		//printf("%d to %d is %d\n", i,j,c);
	}

	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++){
			if(i!=j && G.matrix[i][j]==0)
			G.matrix[i][j]=INF;

		}
		printf("\n");
	}

	//apply dijkstra method
	dijkstra(G,0,prev,dist);


	fclose(fp);
}
