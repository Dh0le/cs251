#include <iostream>
#include <string>

using namespace std;
struct Node { //each airport
	Node(){};
	Edge * edgeList[];//edges
	string value;//name
	int numOfEdge = 0;//default no edge
	bool visited = false;//default not visited
	
	void addEdgeTo(Node * node) {// add an edge to input node
		Edge * edge = new Edge();
		edge->to = node;
		edgeList[numOfEdge++] = edge;
	}
	
};

struct Edge {
	Edge() {};
	Node * to;//the airport it is connected to
	double weight;//price
};
class Graph
{
	public:
		// Constructor
		Graph(); 
		//get the index of input string of airport name
		int * getindex(string value);
		//check if the node exist
		Node * findNode(string value);
		//find the connected node with min edge;
		Node * findMinNode(Node * ori);
		//find the weight value of the minedge
		double * findMinWeight(Node * ori);
		//find if the edge existed
		Edge * findEdge(Node * node, string value);
		// Part 1: Find a ticket using Dijkstra
		void find_ticket(const string &source,const string &destination); 
		
		// Part 2: Try to do a tour of all cities
		void eulerian_tour(); 
	
	// Add any needed private methods here
};