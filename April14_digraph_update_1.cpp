#include <string>
#include <iostream>
using namespace std;


int number_nodes = 42; //42 nodes or intersections in the graph
int number_edges;		//number of roads or directed edges of graph (not yet calculated)

						//intersect_num corresponds to a unique intersection
class node {
public:
	int intersect_num; // I want to turn these variables into private variables
	node* nxt;			//I also wanted to turn 'int intersect_num' into 'string intersect_name'
};						//but not sure what to change in the rest of the code


class directed_edge {

public:
	int begin_Road;
	int end_Road;	//I want to turn these variables into private variables
};					// and create a class like the one below, but not sure how. 



					/*
					class directed_edge {
					public:
					//setter
					void set_src(int x) {
					src = x;
					}
					//setter
					void set_dest(int x) {
					dest = x;
					}
					//getter
					int get_src() {
					return src;
					}
					//getter
					int get_dest()
					{
					return dest;
					}
					private:
					int src, dest;
					};
					*/


					// print the nodes
void print_node_list(node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " >>> " << ptr->intersect_num << "  ";
		ptr = ptr->nxt;
	}
	cout << endl;
}


class directed_graph
{
public:

	node * *head;

	directed_graph(int number_nodes, int number_edges, directed_edge array_of_roads[])
	{
		head = new node*[number_nodes]();
		this->number_nodes = number_nodes;

		for (int count = 0; count < number_nodes; count++)
			head[count] = nullptr;

		// add edge
		for (int count = 0; count < number_edges; count++)
		{
			int begin_Road = array_of_roads[count].begin_Road;
			int end_Road = array_of_roads[count].end_Road;

			node* newNode = adjacency_list(head[begin_Road], end_Road);

			head[begin_Road] = newNode;
		}
	}

	~directed_graph()
	{
		for (int count = 0; count < number_nodes; count++)
			delete[] head[count];

		delete[] head;
	}

private:
	int number_nodes;

	node * adjacency_list(node* head, int begin_road)
	{
		node* new_node = new node;

		new_node->nxt = head;
		new_node->intersect_num = begin_road;

		return new_node;
	}
};

int main()
{

	//array of objects
	/*
	directed_edge array_of_links[] =
	{
	{0,2},{1,3},{2,1},{2,4},{3,7},{4,3},{4,8},
	{5,10},{6,5},{6,14},{7,6},{8,7},{9,12},{10,9},{10,13},
	{11,15},{12,11},{13,16},{14,13},{15,16},{16,NULL}//16 points to nowhere
	};
	*/

	directed_edge array_of_roads[] = {
		{ 0,1 },{ 1,2 },{ 1,5 },{ 2,3 },{ 2,6 },{ 3,4 },{ 3,7 },
	{ 4,8 },{ 5,6 },{ 5,12 } ,{ 6,7 } ,{ 7,8 } ,{ 7,9 },{ 8,10 },{ 9,10 },{ 9,14 },{ 10,11 },{ 10,15 },{ 11,16 },{ 12,13 } ,{ 12,17 } ,{ 13,14 } ,{ 13,18 },{ 14,15 } ,{ 14,19 },
	{ 15,16 } ,{ 15,20 } ,{ 16,21 },{ 17,18 },{ 17,22 },{ 18,19 } ,{ 18,23 },{ 19,20 },{ 19,24 },{ 20,21 },{ 20,25 },{ 21,26 },{ 22,23 },{ 22,27 },{ 23,24 },{ 23,28 },{ 24,25 },{ 24,29 },
	{ 25,26 },{ 25,30 } ,{ 26,31 } ,{ 27,28 } ,{ 27,33 } ,{ 28,29 } ,{ 28,34 },{ 29,30 },{ 29,35 },{ 30,31 },{ 30,36 } ,{ 31,32 },{ 31,37 } ,{ 32,38 },{ 33,34 },{ 34,35 },{ 35,36 },{ 36,37 },
	{ 37,40 },{ 38,37 } ,{ 38,39 },{ 39,41 },{ 40,40 } ,{ 41,40 } };	//NOTE: {40,40} is end of route!

	number_edges = sizeof(array_of_roads) / sizeof(array_of_roads[0]); //gives you number of elements in the array, in this case: number of edges


	directed_graph graph_1(number_nodes, number_edges, array_of_roads); //graph needs number of edges, nodes, and adjacency list above

																		//print the adjacency list 
	for (int count = 0; count < number_nodes; count++)
	{
		cout << count;
		print_node_list(graph_1.head[count]);
	}

	int testing;
	cin >> testing;
	return 0;
}
