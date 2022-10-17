

#include "Place.h"
#include "Traveller.h"
#include "Main_Menu.h"
#include "DateCalc.h"
#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Main_Menu m;
	Place p1("Villa", "cairo", "ELREHAB", { 1 , 1 , 2022 }, { 1 , 7 , 2022 }, 5000, 6, 9);
	Place p2("Villa", "cairo", "MASR EL GDEDA", { 15 , 2 , 2022 }, { 15 , 9 , 2022 }, 3500, 6, 9);
	m.places.push_back(p1);
	m.places.push_back(p2);


	rented r1 = { 0,"Villa", "cairo", "ELREHAB",5000,{15,5,2022 },{20,5,2022 }, 6,9 };
	rented r2 = { 1,"Villa", "cairo", "MASR EL GDEDA",3500,{15,5,2022 },{20,5,2022 }, 6,9 };
	p1.reserved = true;
	p2.reserved = true;
	Traveller t1("mostafa", "t@g.com", "123456", 20, "Egypt", "Male", "red");
	Traveller t2("mostafa", "tt@g.com", "123456", 20, "Egypt", "Male", "blue");
	Traveller t3("maryam", "m@g.com", "123456", 20, "Egypt", "Female", "red");
	Traveller t4("ahmed", "a@g.com", "123456", 20, "Egypt", "Male", "yellow");
	Traveller t5("nourhan", "n@g.com", "123456", 20, "Egypt", "Female", "orange");
	Traveller t6("eman", "e@g.com", "123456", 20, "Egypt", "Female", "white");
	Traveller t7("mahmoud", "mm@g.com", "123456", 20, "Egypt", "Male", "red");

	t1.AddRent(r1);
	t1.AddRent(r2);

	Host h1("mostafa", "h@g.com", "123456", 20, "Egypt", "Male", "red");
	Host h2("nourhan", "n@g.com", "123456", 20, "Egypt", "Female", "orange");


	m.Trav_Users.push_back(t1);
	m.Trav_Enter.insert(pair<string, string>("t@g.com", "123456"));
	m.Trav_Users.push_back(t2);
	m.Trav_Enter.insert(pair<string, string>("tt@g.com", "123456"));
	m.Trav_Users.push_back(t3);
	m.Trav_Enter.insert(pair<string, string>("m@g.com", "123456"));
	m.Trav_Users.push_back(t4);
	m.Trav_Enter.insert(pair<string, string>("a@g.com", "123456"));
	m.Trav_Users.push_back(t5);
	m.Trav_Enter.insert(pair<string, string>("n@g.com", "123456"));
	m.Trav_Users.push_back(t6);
	m.Trav_Enter.insert(pair<string, string>("e@g.com", "123456"));
	m.Trav_Users.push_back(t7);
	m.Trav_Enter.insert(pair<string, string>("mm@g.com", "123456"));
	m.Host_Users.push_back(h1);
	m.Host_Enter.insert(pair<string, string>("h@g.com", "123456"));
	m.Host_Users.push_back(h2);
	m.Host_Enter.insert(pair<string, string>("n@g.com", "123456"));



	m.WelcomeScreen();
	m.menu();

}

