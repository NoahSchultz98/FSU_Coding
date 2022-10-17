#include<iostream>
#include<fstream>
using namespace std;

#define NUMBER_OF_NODES 6
#define INF 99999


struct Node
{
	int arrow[NUMBER_OF_NODES];
};

void initialize(int start, int* distance, int* predecessor, int* allowed, struct Node *node);
void one_round(int next, int* distance, int* predecessor, int* allowed, struct Node *node);
void graph_read(ifstream &instream, struct Node *node);
void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node);
int find_next(int* distance, int* allowed);
void print_arrays(int* distance, int* predecessor, int* allowed);

//void shortest_path(int start, int destination, int* predecessor);

int main()
{
	ifstream instream;
	
	Node node[NUMBER_OF_NODES];

	int i, j;
	int distance[NUMBER_OF_NODES];
	int allowed[NUMBER_OF_NODES];
	int predecessor[NUMBER_OF_NODES];
   int NUMBER_OF_ALLOWED_NODES = 1;
	int start, destination;
	int next;

	cout << "Please enter the start node" << endl; // take inputs
	cin >> start;
	cout << "start is " << start << endl;
   
	cout << "Please enter the destination node" << endl;
	cin >> destination;

	initialize(start, distance, predecessor, allowed, node); // set up our arrays
	print_arrays(distance, predecessor, allowed);
	instream.open("input.txt");
	graph_read(instream, node);   // read matrix from input.txt
	next = start;                 // set the start node
      
   while (NUMBER_OF_ALLOWED_NODES < NUMBER_OF_NODES) // for each node
	{

		one_round(next, distance, predecessor, allowed, node); // find the next round from the node
      
		next = find_next(distance, allowed);   // if the node is allowed and the distance is smaller than we use that distance 
      
      NUMBER_OF_ALLOWED_NODES++;       // increment to next node
      
      
      // noah's sanity code
      cout << endl << "Round Number:   " << NUMBER_OF_ALLOWED_NODES -1 << endl;
      print_arrays(distance, predecessor, allowed);
	}

   cout << endl << "Final Round" << endl;
	print_arrays(distance, predecessor, allowed); // print final round

	return 0;
}

void initialize(int start, int* distance, int* predecessor, int* allowed, struct Node *node)
{
	int i;
	for (i = 0; i < NUMBER_OF_NODES; i++)
// for each node
	{

		if (i == start) // if the current node is the starting node
		{
			distance[i] = 0; // Then the distance of starting node to itself is 0
			predecessor[i] = start; // the predecessor to the starting node is itself
			allowed[i] = 1;   // the path back to itself is allowed
		}

		else
		{
			distance[i] = INF; // the nodes that are not the start have not had their distance evaluated so they are infinite
			predecessor[i] = -1; // their is no predacessor to this node since there have not been any moves yet 
			allowed[i] = 0; // the path is not allowed since we have not evaluated it yet
		}
	}
}

void graph_read(ifstream  &instream, struct Node *node)
{
	int i, j;

   // read the square matrix from the file
	for (j = 0; j < NUMBER_OF_NODES; j++)
		for (i = 0; i < NUMBER_OF_NODES; i++)
			instream >> node[j].arrow[i];
         // two dimensional array where node[j] is the x and arrow[i] is the y

}

void print_arrays(int* distance, int* predecessor, int* allowed)
{

	int i;
	cout << "Printing distance, allowed and predecessor arrays" << endl;
	cout << "The distance array  is" << endl;

	for(i = 0; i < NUMBER_OF_NODES; i++)
		cout << distance[i]<<"  ";
	cout << endl;

	cout << "The predecessor array  is" << endl;

	for (i = 0; i < NUMBER_OF_NODES; i++)
		cout << predecessor[i] << "  ";
	cout << endl;

	cout << "The allowed array  is" << endl;

	for (i = 0; i < NUMBER_OF_NODES; i++)
		cout << allowed[i] << "  ";
	cout << endl;
}

void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node)
{

	int new_distance;

   // this next line is where I had the most trouble with my homework assignment 
   // new_distance is equal to the distance from the last predecessor PLUS the distance to the next node
   //    - also j basically is just an iterator of the array filtered for all nodes connected to the current node
	new_distance = distance[predecessor[j]] + node[next].arrow[j]; 
   // I think this is right, but I have been wrong before
                 
	if (new_distance < distance[j])  // this cannot be called if node[next].arrow[j] is -1 so we can ignore that case
	{
		distance[j] = new_distance;   // replace the distance with the new distance and change the predecessor to the last node
		predecessor[j] = next;
	}
}

	
void one_round(int next, int* distance, int* predecessor, int* allowed, struct Node *node)
{

	int j;
	//allowed[next] = 1;
	for (j = 0; j < NUMBER_OF_NODES; j++) // for each node
		if (allowed[j] == 0 && node[next].arrow[j] != -1) // if this node is not allowed and there is a path from one node to another, we travel
			travel(next, j, distance, predecessor, allowed, node); // basically if we haven't already traveled there and we can, then we do. 
}

int find_next(int* distance, int* allowed)
	{
		int min_distance, i, next;

		min_distance = INF;

		for (i = 0; i < NUMBER_OF_NODES; i++) // for each node
			if (allowed[i] == 0 && distance[i] <= min_distance) // if the node has not been visited
			{                                                   // and the distance to that node is less that the smallest distance 
				min_distance = distance[i]; // edited line          then we make that distance the new distance
				next = i;                   // edited line          the next node is equal to the current node 
			}

		allowed[next] = 1; // if the node is allowed we say we have traveled to it by giving it the number 1
		return next;       // return this node

}