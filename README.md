# link\_state
implementation of link state routing algorithm(Dijkstra)
### Description
In this project, you will implement the Link State Routing Protocol, as discussed in class and in Slide 85 of Network Layer presentation. Read the links and their costs from a text file (networkGraph.txt) as follows: a) First line of the file indicates number of nodes in the network, b) next p lines denote p links with cost associated with it in the format n1, n2, c. Your program should then compute the distance vector iteratively and in each step, should print out the modified distance. After all the distances are finalized, your program should print out the distances from node 1 to all other nodes in the network. 
### Sample input text file (networkGraph.txt )
	6
	1,2,5
	1,3,3
	1,4,7
	2,3,4
	2,5,7
	2,6,9
	3,4,3
	3,5,8
	4,5,4
	5,6,2
	
### Sample output
	Next node = 3
	Updating distance vector of Node 4, New = 6, Old = 7
	Updating distance vector of Node 5, New = 11, Old = infinity
	Next node = 2
	Updating distance vector of Node 5, New = 12, Old = 11
	Updating distance vector of Node 6, New = 14, Old = infinity
	Next node = 4
	Updating distance vector of Node 5, New = 10, Old = 11
	Next node = 5
	Updating distance vector of Node 6, New = 12, Old = 14
	Next node = 6
	The final distances are:
	1->1 = 0
	1->2 = 5
	1->3 = 3
	1->4 = 6
	1->5 = 10
	1->6 = 12
