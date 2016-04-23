#include <iostream>
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

typedef struct node{
	string name = NULL;
	edge* es = (edge*)malloc(sizeof(edge)*2000);
	edge* po = es;
	int nume = 0;
	double distance = -1;
};

typedef struct edge{
	node c1
	node c2
	double price;	
};
typedef struct queuer{
	node city;
	queuer *next;
};
void Enqueue(node x) {
	queuer * temp = (queuer *)malloc(sizeof(queuer));
	temp->city =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}
void Dequeue() {
	queuer* temp = front;
	if(front == NULL) {
		//printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}
int Front() {
	if(front == NULL) {
		//printf("Queue is empty\n");
		return;
	}
	return front->data;
}
/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph. Read in data from the input
// and set up your data structures here.
Graph::Graph()
{	
	int num_city;
	int num_edge;
	queuer front = NULL;
	queuer rear = NULL;
	
	cin>>num_city;
	cin>>num_edge;
	string dest_name;
	string dest_name1;
	double weight;
	node *array;
	edge *array1;
	array = node[num_city];
	array1 = edge[num_edge];
	edge temp;
	int num_node;
	int num_node1;
	int j = 0;
	for(int i = 0;i < num_edge;i++){
		cin>>dest_name;
		cin>>dest_name1;
		cin>>weight;
		temp.price = weight;
		if(checker(dest_name,array,num_city)!= -1){
			if(checker(dest_name1,array,num_city) == -1){
				array[j].name = dest_name1;
				num_node = checker(dest_name,array,num_city);
				temp.c1 = array[num_node];
				temp.c2 = array[j];
				*(array[j].po) = temp;
				array[j].po++;
				array[j].nume++;
				array[num_node].po = temp;
				array[num_node].po++;
				array[num_node].nume++;
				j++;
			}
			else if(checker(dest_name1,array,num_city)!= -1){
				num_node = checker(dest_name,array,num_city);
				temp.c1 = array[num_node];
				num_node1 = checker(dest_name1,array,num_city);
				temp.c2 = array[num_node1];
				array[num_node1].po = temp;
				array[num_node1].po++;
				array[num_node1].nume++;
				array[num_node].po = temp;
				array[num_node].po++;
				array[num_node].nume++;
			}
			
		}
		if(checker(dest_name,array,num_city) == -1){
			if(checker(dest_name1,array,num_city) == -1){

				array[j].name = dest_name;
				array[j+1].name = dest_name1
				temp.c1 = array[j];
				temp.c2 = array[j+1];
				array[j].po = temp;
				array[j+1].po = temp;
				array[j].po++;
				array[j].nume++;
				array[j+1].po++;
				array[j+1].nume++;
				j+=2;
			}
			else if(checker(dest_name1,array,num_city)!=-1){
				array[j].name = dest_name;
				num_node = checker(dest_name1,array,num_city);
				temp.c1 = array[j];
				temp.c2 = array[num_node];
				array[j].po = temp;
				array[j].nume++:
				array[j].po++;
				array[num_node].po = temp;
				array[num_node].po++;
				array[num_node].nume++;
				j++;
			}
		}
	} 
}
int checker(string name,node array[],int length){
	for(int i = 0; i<length;i++){
		if(name == array[i].name){
			return i;
		}
		else{
			return -1;
		}
	}
	return -1;
}

// Code for part 1. Print out the sequence of airports and price
// of the trip.
int Graph::find_ticket(const string &source,const string &destination)
{
  	int num = checker(source,this.array,this.num_city);
 	this.array[num].distance = 0;
 	for(int i = 0;i < this.array[num].nume;i++){
 		if(*(this.array[num].po).c1.name != this.array[num].name{
 			*(this.array[num].po).c2.distance = *(this.array[num].po).price;
 		}
 		else {
 			*(this.array[num].po).c1.distance = *(this.array[num].po).price;
 		}

 	}



}

// Code for part 2. Print out the tour sequence or "not possible"
// if not all cities can be visited.
void Graph::eulerian_tour()
{

}