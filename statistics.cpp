#include "statistics.h"
#include <iostream>
#include <string>
#include "Main_Menu.h"

using namespace std;

double statistics::PriceMode() {
	double count = 1, max = 0, mode = Main_Menu::places[0].price;
	for (int i = 0; i < Main_Menu::places.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::places.size(); j++) {
			if (Main_Menu::places[i].price == Main_Menu::places[j].price) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::places[i].price;
				}

			}
		}count = 1;
	}
	return mode;
}
double statistics::PriceMean() {
	double sum = 0;
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		sum += Main_Menu::places[i].price;
	}
	if (Main_Menu::places.size() != 0)
		return sum / Main_Menu::places.size();
	else {
		return 0;
	}
}
double statistics::PriceMedian() {
	if (Main_Menu::places.size() % 2 != 0) {
		if (Main_Menu::places.size() > 1)
			return  Main_Menu::places[ceil(Main_Menu::places.size() / 2) - 1].price;
		else {
			return  Main_Menu::places[0].price;
		}
	}
	else {
		double calcmed1 = Main_Menu::places.size() / 2 - 1, calcmed2 = (Main_Menu::places.size() / 2);
		double result = (Main_Menu::places[calcmed1].price + Main_Menu::places[calcmed2].price) / 2;
		return result;
	}
}double statistics::GuestsMode() {
	double count = 1, max = 0, mode = Main_Menu::places[0].guests;
	for (int i = 0; i < Main_Menu::places.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::places.size(); j++) {
			if (Main_Menu::places[i].guests == Main_Menu::places[j].guests) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::places[i].guests;
				}

			}
		}count = 1;
	}
	return mode;
}
double statistics::GuestsMean() {
	double sum = 0;
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		sum += Main_Menu::places[i].guests;
	}
	return sum / Main_Menu::places.size();
}
double statistics::GuestsMedian() {
	if (Main_Menu::places.size() % 2 != 0) {
		if (Main_Menu::Host_Users.size() > 1)
			return  Main_Menu::places[ceil(Main_Menu::places.size() / 2) - 1].guests;
		else {
			return  Main_Menu::places[0].guests;
		}
	}
	else {
		double calcmed1 = Main_Menu::places.size() / 2 - 1, calcmed2 = (Main_Menu::places.size() / 2);
		double result = (Main_Menu::places[calcmed1].guests + Main_Menu::places[calcmed2].guests) / 2;
		return result;
	}
}
double statistics::RoomMode() {
	double count = 1, max = 0, mode = Main_Menu::places[0].NumOfRooms;
	for (int i = 0; i < Main_Menu::places.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::places.size(); j++) {
			if (Main_Menu::places[i].NumOfRooms == Main_Menu::places[j].NumOfRooms) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::places[i].NumOfRooms;
				}

			}
		}count = 1;
	}
	return mode;
}
double statistics::RoomMean() {
	double sum = 0;
	for (int i = 0; i < Main_Menu::places.size(); i++) {
		sum += Main_Menu::places[i].NumOfRooms;
	}
	return sum / Main_Menu::places.size();
}
double statistics::RoomMedian() {
	if (Main_Menu::places.size() % 2 != 0) {
		if (Main_Menu::Host_Users.size() > 1)
			return  Main_Menu::places[ceil(Main_Menu::places.size() / 2) - 1].NumOfRooms;
		else {
			return  Main_Menu::places[0].NumOfRooms;
		}
	}
	else {
		double calcmed1 = Main_Menu::places.size() / 2 - 1, calcmed2 = (Main_Menu::places.size() / 2);
		double result = (Main_Menu::places[calcmed1].NumOfRooms + Main_Menu::places[calcmed2].NumOfRooms) / 2;
		return result;
	}
}
double statistics::AgeTMode() {
	double count = 1, max = -9, mode = Main_Menu::Trav_Users[0].age;
	for (int i = 0; i < Main_Menu::Trav_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Trav_Users.size(); j++) {
			if (Main_Menu::Trav_Users[i].age == Main_Menu::Trav_Users[j].age) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Trav_Users[i].age;
				}

			}
		}count = 1;
	}
	return mode;
}
double statistics::AgeTMean() {
	double sum = 0;
	for (int i = 0; i < Main_Menu::Trav_Users.size(); i++) {
		sum += Main_Menu::Trav_Users[i].age;
	}
	return sum / Main_Menu::Trav_Users.size();
}
double statistics::AgeTMedian() {
	if (Main_Menu::Trav_Users.size() % 2 != 0) {
		if (Main_Menu::Trav_Users.size() > 1)
			return  Main_Menu::Trav_Users[ceil(Main_Menu::Trav_Users.size() / 2) - 1].age;
		else {
			return  Main_Menu::Trav_Users[0].age;
		}
	}
	else {
		double calcmed1 = Main_Menu::Trav_Users.size() / 2 - 1, calcmed2 = (Main_Menu::Trav_Users.size() / 2);
		double result = (Main_Menu::Trav_Users[calcmed1].age + Main_Menu::Trav_Users[calcmed2].age) / 2;
		return result;

	}
}
double statistics::AgeHMode() {
	double count = 1, max = 0, mode = Main_Menu::Host_Users[0].age;
	for (int i = 0; i < Main_Menu::Host_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Host_Users.size(); j++) {
			if (Main_Menu::Host_Users[i].age == Main_Menu::Host_Users[j].age) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Host_Users[i].age;
				}

			}
		}count = 1;
	}
	return mode;
}
double statistics::AgeHMean() {
	double sum = 0;
	for (int i = 0; i < Main_Menu::Host_Users.size(); i++) {
		sum += Main_Menu::Host_Users[i].age;
	}
	return sum / Main_Menu::Host_Users.size();
}
double statistics::AgeHMedian() {
	if (Main_Menu::Host_Users.size() % 2 != 0) {
		if (Main_Menu::Host_Users.size() > 1)
			return  Main_Menu::Host_Users[ceil(Main_Menu::Trav_Users.size() / 2) - 1].age;
		else {
			return  Main_Menu::Host_Users[0].age;
		}
	}
	else {
		double calcmed1 = Main_Menu::Host_Users.size() / 2 - 1, calcmed2 = (Main_Menu::Host_Users.size() / 2);
		double result = (Main_Menu::Host_Users[calcmed1].age + Main_Menu::Host_Users[calcmed2].age) / 2;
		return result;
	}
}
string statistics::CityMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::places[0].city;
	for (int i = 0; i < Main_Menu::places.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::places.size(); j++) {
			if (Main_Menu::places[i].city == Main_Menu::places[j].city) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::places[i].city;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::NationalityTMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::Trav_Users[0].nationality;
	for (int i = 0; i < Main_Menu::Trav_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Trav_Users.size(); j++) {
			if (Main_Menu::Trav_Users[i].nationality == Main_Menu::Trav_Users[j].nationality) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Trav_Users[i].nationality;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::NationalityHMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::Host_Users[0].nationality;
	for (int i = 0; i < Main_Menu::Host_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Host_Users.size(); j++) {
			if (Main_Menu::Host_Users[i].nationality == Main_Menu::Host_Users[j].nationality) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Host_Users[i].nationality;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::NameTMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::Trav_Users[0].name;
	for (int i = 0; i < Main_Menu::Trav_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Trav_Users.size(); j++) {
			if (Main_Menu::Trav_Users[i].name == Main_Menu::Trav_Users[j].name) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Trav_Users[i].name;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::NameHMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::Host_Users[0].name;
	for (int i = 0; i < Main_Menu::Host_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Host_Users.size(); j++) {
			if (Main_Menu::Host_Users[i].name == Main_Menu::Host_Users[j].name) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Host_Users[i].name;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::TypeMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::places[0].typeOfPlace;
	for (int i = 0; i < Main_Menu::places.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::places.size(); j++) {
			if (Main_Menu::places[i].typeOfPlace == Main_Menu::places[j].typeOfPlace) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::places[i].typeOfPlace;
				}

			}
		}count = 1;
	}
	return mode;
}
string statistics::GenderTMode() {
	double count = 0, max = 0;
	string mode = Main_Menu::Trav_Users[0].gender;
	for (int i = 0; i < Main_Menu::Trav_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Trav_Users.size(); j++) {
			if (Main_Menu::Trav_Users[i].gender == Main_Menu::Trav_Users[j].gender) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Trav_Users[i].gender;
				}


			}
		}
		count = 0;
	}
	return mode;
}
string statistics::GenderHMode() {
	double count = 1, max = 0;
	string mode = Main_Menu::Host_Users[0].gender;
	for (int i = 0; i < Main_Menu::Host_Users.size() - 1; i++) {
		for (int j = i + 1; j < Main_Menu::Host_Users.size(); j++) {
			if (Main_Menu::Host_Users[i].gender == Main_Menu::Host_Users[j].gender) {
				count++;
				if (count > max) {
					max = count;
					mode = Main_Menu::Host_Users[i].gender;
				}

			}
		}count = 1;
	}
	return mode;
}
