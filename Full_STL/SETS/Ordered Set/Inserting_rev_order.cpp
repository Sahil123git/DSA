#include<bits/stdc++.h>
using namespace std;

int main()
{
	// Here if greater<int> is used to make
	// sure that elements are stored in
	// descending order of keys.
	set<int, greater <int>> mymap;

	// Inserting the elements one by one
	mymap.insert(10);
	mymap.insert(20);
	mymap.insert(5);

	// begin() returns to the first value of map.
	set<int> :: iterator it;
	for (it=mymap.begin() ; it!=mymap.end() ; it++)
		cout << "(" << (*it)<<endl;

	return 0;
}