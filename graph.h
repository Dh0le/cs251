#include <iostream>
#include <string>

using namespace std;

class Graph
{
	public:
		// Constructor
		Graph(); 
		
		// Part 1: Find a ticket using Dijkstra
		void find_ticket(const string &source,const string &destination); 
		
		// Part 2: Try to do a tour of all cities
		void eulerian_tour(); 
	
	// Add any needed private methods here
};