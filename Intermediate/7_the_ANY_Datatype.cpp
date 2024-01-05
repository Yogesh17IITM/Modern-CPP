/*
* TOPIC:
*	- The 'any' datatype (introduced from C++ 17 onwards)
*	- Vector with multiple datatypes
*/

#include<iostream>
#include<vector>
#include<any>
using namespace std;

// Operator "<<" needs to be overloaded inorder to print vector of 'any' datatype
std::ostream& operator<<(std::ostream& out, const any & data) 
{	
	if (data.type() == typeid(char)) out<< any_cast<char>(data);
	if (data.type() == typeid(int)) out << any_cast<int>(data);
	if (data.type() == typeid(double)) out << any_cast<double>(data);
	if (data.type() == typeid(float)) out << any_cast<float>(data);
	if (data.type() == typeid(std::string)) out << any_cast<std::string>(data);
	if (data.type() == typeid(char const *)) out << any_cast<char const *>(data);
	
	// <if any data type to be handled in addition, add here>

	return out;
}

int main()
{
	string str = "Hai";

	// Create a vector of 'any' datatype (mixed datatypes)
	vector<any> vector = { 'a', 1, 2.4f, "Hello", str };

	double a = 5.5;
	vector.push_back(a);
	
	// Print the vector information
	cout << "Size: "<< vector.size() << endl;
	for (auto& currVec : vector)
		cout << currVec << "\t";
	cout << endl;

	return 0;
}