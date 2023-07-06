
#include <iostream>
#include <iterator>
#include <set>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    auto print = [](const int& n) { std::cout << ' ' << n; };

	set<int, greater<int> > s1;

	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);

	// only one 50 will be added to the set
	s1.insert(50);
	s1.insert(10);

	// printing set s1
	set<int, greater<int> >::iterator itr;
	cout << "\nThe set s1 is : \n";
	for (itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

    for(auto s: s1)
        cout << s << ' ';
    cout << endl;
	// assigning the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end());

	// print all elements of the set s2
	cout << "\nThe set s2 after assign from s1 is : \n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to 30 in s2
	cout << "\ns2 after removal of elements less than 30 "
			":\n";
	s2.erase(s2.begin(), s2.find(30));
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}

	// remove element with value 50 in s2
	int num;
	num = s2.erase(50);
	cout << "\ns2.erase(50) : ";
	cout << num << " removed\n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}

	cout << endl;

    cout << "array for two elements: \n";
    set<array<int, 2>> s3;
    s3.insert({1,2});
    s3.insert({2,3});
    s3.insert({2,4});
    s3.insert({2,1});
    s3.insert({5,6});

    for(auto s: s3)
        cout << s[0] << ' ' << s[1] << endl;
    cout << endl;


    for_each(s1.begin(), s1.end(), print);
    cout << endl;
    for_each(s2.begin(), s2.end(), print);
    cout << endl;


	// lower bound and upper bound for set s1
	cout << "s1.lower_bound(40) : "
		<< *s1.lower_bound(40) << endl;
	cout << "s1.upper_bound(40) : "
		<< *s1.upper_bound(40) << endl;

    cout << "s1.lower_bound(45) : "
		<< *s1.lower_bound(45) << endl;
	cout << "s1.upper_bound(45) : "
		<< *s1.upper_bound(45) << endl;

	// lower bound and upper bound for set s2
	cout << "s2.lower_bound(40) : "
		<< *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40) : "
		<< *s2.upper_bound(40) << endl;

    cout << "s2.lower_bound(45) : "
		<< *s2.lower_bound(45) << endl;
	cout << "s2.upper_bound(45) : "
		<< *s2.upper_bound(45) << endl;

	return 0;
}
