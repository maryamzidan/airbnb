
#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include<string>
using namespace std;
struct date {
	int d;
	int m;
	int y;
};
struct rented {
	int id;
	string type;
	string city;
	string address;
	int price;
	date from;
	date to;
	int days;
	int rooms;
};
struct CurrentUser {
	string name;
	string email;
	string type;
};
class structs
{
};

#endif