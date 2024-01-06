/*
* TOPIC:
*	-	Map
*/

#include<iostream>
#include<map>
using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& out, pair<const T1, T2>& mKeyVal)
{
	out << mKeyVal.first << "\t" << mKeyVal.second;
	return out;
}

int main()
{
	map<string, int> mKeyVal = {
		{"A", 1}, {"B",1}
	};
	
	// C++ 14
	for (auto& curKeyVal : mKeyVal)
		cout <<"C++-14 " << curKeyVal << endl;

	// C++ 17
	for (auto& [key, value] : mKeyVal)
		cout << "C++-17 " << key << "\t" << value << endl;

	auto result = mKeyVal.insert({ "C", 3 });	// returns {iterator, bool}
	if (result.second)
		cout << "Key: " << result.first->first << " Val: " << result.first->second << endl;

	return 0;
}