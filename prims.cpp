#include <iostream>
#define INF 9999999
using namespace std;

// list node
struct Node {
	int val, cost;
	Node* next;
};

// link/edge in graph 
struct Link
{
	int source, dest, weight;
};

Node* listNode(int value, int weight, Node* adjList) 	
{
	Node* temp = new Node;
	temp->val = value;
	temp->cost = weight;
	temp->next = adjList;   //point to new node in graph
	return temp;
}

Node **adjList;// list
//Graph 
void createGraph(Link links[], int n, int N)  
{
	adjList = new Node*[N]();// create array of nodes
	//init list
	for (int i = 0; i < N; ++i)
		adjList[i] = nullptr;
	// append new link/edge to graph
	for (unsigned i = 0; i < n; i++)  
	{
		int source = links[i].source;
		int dest = links[i].dest;
		int weight = links[i].weight;
		Node* temp = listNode(dest, weight, adjList[source]);// create inner list
		adjList[source] = temp;
     }
}

// print list
void printList(Node* node_ptr, int i)
{
	while (node_ptr != nullptr) {
		cout << "(" << i << ", " << node_ptr->val
			<< ", " << node_ptr->cost << ") ";
		node_ptr = node_ptr->next;
	}
	cout << endl;
}

int isLink(Node* node_ptr, int i,int j)
{
	int edge = 0;
	while (node_ptr != nullptr) 
	{
		if(node_ptr->val == j)
		{
			return 1;
		}
		node_ptr = node_ptr->next;
	}
	return -1;
}
int getCost(Node* node_ptr, int i,int j)
{
	int edge = 0;
	while (node_ptr != nullptr) 
	{
		if(node_ptr->val == j)
		{
			return node_ptr->cost;
		}
		node_ptr = node_ptr->next;
	}
	return -1;
}

void prims(int N)
{
	int visited [N];
	
	for(int i=0;i<N;i++)
	{
		visited[i] = 0;
	}
	visited[0]=1;
	int mst = 0;
	int No_row;
	int No_col;
	int no_edge = 0;
	while (no_edge < N - 1) 
	{
     int min = INF;
     No_row = 0;
     No_col = 0;
	for (int i = 0; i < N; i++) 
	{
      if (visited[i] == 1) 
	  {
        for (int j = 0; j < N ; j++) 
		{
			int yes = isLink(adjList[i],i,j);
          if (visited[j] == 0 && yes == 1 ) 
		  {  // not in selected and there is an edge
				int cost = getCost(adjList[i],i,j); 
            if (min > cost && yes == 1) 
			{
              min = cost;
              No_row = i;
              No_col = j;
            }
          }
        }
      }
    }
	visited[No_col]=1 ;
    mst  += min;
    no_edge++ ;
	}
	printf("mst: %d\n",mst);
	
}

// graph implementation
int main()
{		
	// create graph as list
	Link links[] = {
		//(source, dest, cost)
		{0,1,5},{1,0,5},{0,2,5},{2,0,5},{0,3,5},{3,0,5},{0,4,5},{4,0,5}
	};
	
	int N = 5;

	// number of links/links
	int n = sizeof(links)/sizeof(links[0]);
	createGraph(links,n,N);
	
	
	// display
	cout<<"adjacency list "<<endl<<"(Source, Destination, Cost):"<<endl;
	for (int i = 0; i < N; i++)
	{
		printList(adjList[i], i);
	}
	prims(N);
	
	// add high speed lines
	
	// create graph as list
	Link links1[] = {
		//(source, dest, cost)
		{0,1,5},{1,0,5},{0,2,5},{2,0,5},{0,3,5},{3,0,5},{0,4,5},{4,0,5},{3,4,8},{4,3,8},{4,5,8},{5,4,8},{2,3,2},{3,2,2}
	};
	
	N = 5;

	// number of links/links
	n = sizeof(links1)/sizeof(links1[0]);
	createGraph(links1,n,N);
	// display
	cout<<"adjacency list "<<endl<<"(Source, Destination, Cost):"<<endl;
	for (int i = 0; i < N; i++)
	{
		printList(adjList[i], i);
	}
	prims(N);
	
	
	return 0;
}