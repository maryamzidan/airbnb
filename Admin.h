#pragma once
#include"Host.h"
#include"Traveller.h"
#include "Place.h"
class Admin
{
public:

	Admin();
	void Dashboard();
	void login();
	int SearchForPlace();
	void ChangeTraveler();
	void ChangePlace();
	void ChangeHost();
	void DisplayAllTravs();
	void DisplayAllHosts();
	void DisplayAllPlaces();
	~Admin();





};