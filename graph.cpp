#include <iostream>
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int trueset = 0; //for the loop of dij's algorithm
const double MINDOUBLE = 999999999.99;//infinity;

typedef struct Node { //each airport
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

typedef struct Edge {
	Edge() {};
	Node * to;//the airport it is connected to
	double weight;//price
};

Node * nodeList[];

Graph::Graph() {
	int numedge;// number of edge
	int numair;//number of airport
	cin>>numair;
	cin>>numedge;
	string from;//from airport
	string dest;//destination airport
	double weight;//price
	cin>>weight;
	Edge * edgeset[numOfEdge];//new array of edges can be stored in node
	string name[numair];//array of airport name and used to match the index of following array;
	int counter = 0;//to store airport name in name
	int counter1 = 0;//to store node in nodeList
	
	nodeList = new Node[numedge];//node list, to check if the node are repeated.
	
	for(int i = 0; i < numedge;i++){
		scanf("%s%s%d",&from,&dest,weight);// scann two destination and price
		Node * nodeFrom = findNode(from);// see if the from airport is a node
		Node * nodeTo = findNode(dest);// see if the dest airport is a node
		
		if(nodeFrom && nodeTo) {//both exist
			if(!findEdge(nodeFrom, dest)) {
				nodeFrom->addEdgeTo(nodeTo);
				nodeTo->addEdgeTo(nodeFrom);
			}				
		}
		else if(!nodeFrom && !nodeTo){		//both dont exist
			nodeFrom = new Node();
			nodeTo = new Node();
			nodeFrom->value = from;
			name[counter++] = from;
			nodeTo->value = dest;
			name[counter++] = dest;
			nodeTo->edgeList = edgeset;
			nodeFrom->edgeList = edgeset;
			nodeFrom->addEdgeTo(nodeTo);
			nodeTo->addEdgeTo(nodeFrom);
			nodeList[counter1++]=nodeFrom;
			nodeList[counter1++]=nodeTo;
		}
		else if(!nodeFrom && nodeTo){			//from airport does not exist
			*nodeFrom = new Node();
			nodeFrom->value = from;
			name[counter++]=from;
			nodeFrom->edgeList = edgeset;
			nodeFrom->addEdgeTo(nodeTo);
			nodeTo->addEdgeTo(nodeFrom);
			nodeList[counter1++]=nodeFrom;
		}
		else if(ndoeFrom && !nodeTo){ 		//dest airport does not exist
			*nodeTo = new Node();
			nodeTo->value = dest;
			name[counter++]=dest;
			nodeTo->edgeList = edgeset;
			nodeFrom->addEdgeTo(nodeTo);
			nodeTo->addEdgeTo(nodeFrom);
			nodeList[counter1++]=nodeTo;
		}
	
		
	}
}
int * Graph::getindex(string value){			//get the index for following array
	for(int i = 0;i<numair;i++){
		if(name[i].compare(value) == 0){
			return i;
		}
	}
	return -1;
}

Node * Graph::findNode(string value) {			//find the node with its name
	for(Node * node : nodeList) {
		if(!node->value.compare(value)) {
			return node;
		}
	}
	
	return NULL;
}
Node * Graph::findMinNode(Node* ori) {			//find the node which has min edge weight with ori node;
	Node* minNode;
	double min = ori->edgeList[0]->weight;
	for(int i = 1;i<ori->numOfEdge;i++){
		if(ori->edgeList[i]->weight < min){
			min = ori->edgeList[i]->weight;
			minNode = ori->edgeList[i]->to;
		}
		
	}
	
	return minNode;
}
double * Graph::findMinWeight(Node* ori) {		//find the weight of the min edge of ori node;
	Node* minNode;
	double min = ori->edgeList[0]->weight;
	for(int i = 1;i<ori->numOfEdge;i++){
		if(ori->edgeList[i]->weight < min){
			min = ori->edgeList[i]->weight;
			minNode = ori->edgeList[i]->to;
		}
		
	}
	
	return min;
}

Edge * Graph::findEdge(Node * node, string value) {//see if the edge existed
	for(Edge * edge : Node->edgeList) {
		if(edge->to.value.compare(value)) {
			return edge; 
		}
	}
	return NULL;
}
// Code for part 1. Print out the sequence of airports and price
// of the trip.
void Graph::find_ticket(const string &source,const string &destination)
{
	double dis = 0.0; //static double to calculate the distance of current node to start node
	double min_distance[numair];//array to store the distance from start node to each node;
	//Node * prev[numair];
	Node* ori =  (source);//get the first node;
	Node* nextNode;//declare a node which is the minnode of ori
	for(int i = 0;i<numedge;i++){
		min_distance[i] = MINDOUBLE;//initialize the array to store distance
	}
	min_distance[getindex(ori->value)] = 0;// the distance to itself is 0
	for(int j = 0;j <ori->numOfEdge;j++){//store the distance of the node which is directly connected to ori node
		int index = getindex(ori->edgeList[j]->to->value);
		min_distance[index] = ori->edgeList[j]->weight;
	}
	while(trueset<=numair){//end condition all node are visited
		nextNode = findMinNode(ori);//find the min node of the ori node
		dis+= findMinWeight(ori);//store the distance from current node to ori
		ori->visited = true;//set visited
		trueset++;//number to end the loop
		for(int i = 0;i < nextNode->numOfEdge;i++){//expand the current node
			int numindex = getindex(nextNode->edgeList[i]->to->value);//get the index of all the connected node of current node
			if(min_distance[numindex] > dis + nextNode->edgeList[i]->weight){//if using this node is shorter
				min_distance[numindex] = dis + nextNode->edgeList[i]->weight;//change the distance in the distance array
			}
		}
		ori = nextNode;//use current node as ori node for next expand
	}
	
	double finalprice = min_distance[getindex(destination)];//find the final price of the destination
	if(finalprice == MINDOUBLE){
		cout<<"not possible"<<endl;
		return;//check if the destination is unreachable
	}
	cout<<finalprice;//output the price;n 
	
	

}

// Code for part 2. Print out the tour sequence or "not possible"
// if not all cities can be visited.
void Graph::eulerian_tour()
{

}