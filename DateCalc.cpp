#include"structs.h"
#include "DateCalc.h"
#include<math.h>
DateCalc::DateCalc(void) {}
int DateCalc::diff(date d1, date d2)
{
	int x = (d1.y * 365) + (d1.m * 30) + d1.d;
	int y = (d2.y * 365) + (d2.m * 30) + d2.d;
	return abs(x - y);
}
bool DateCalc::CheckForAvability(date place_start, date place_end, date trav_start, date trav_end) {

	if (trav_start.y > place_start.y && trav_end.y < place_end.y) {
		return true;
	}
	if (trav_start.y == place_start.y && trav_end.y < place_end.y) {
		if (trav_start.m > place_start.m) {
			return true;
		}
	}
	if (trav_start.y == place_start.y && trav_end.y < place_end.y) {
		if (trav_start.m == place_start.m) {
			if (trav_start.d >= place_start.d) {
				return true;
			}
		}
	}


	if (trav_start.y > place_start.y && trav_end.y == place_end.y) {
		if (trav_end.m < place_end.m) {
			return true;
		}
	}

	if (trav_start.y > place_start.y && trav_end.y == place_end.y) {
		if (trav_end.m == place_end.m) {
			if (trav_end.d <= place_end.d) {
				return true;
			}
		}
	}
	///
	if (trav_start.y == place_start.y && trav_end.y == place_end.y) {
		if ((trav_start.m > place_start.m) &&
			(trav_end.m < place_end.m)) {
			return true;
		}
	}
	if (trav_start.y == place_start.y && trav_end.y == place_end.y) {
		if ((trav_start.m == place_start.m) && (trav_end.m < place_end.m)) {
			if (trav_start.d >= place_start.d) {
				return true;
			}
		}
	}
	if (trav_start.y == place_start.y && trav_end.y == place_end.y) {
		if ((trav_start.m > place_start.m) &&
			(trav_end.m == place_end.m)) {
			if (trav_end.d <= place_end.d) {
				return true;
			}
		}
	}
	if (trav_start.y == place_start.y && trav_end.y == place_end.y) {
		if (trav_start.m == place_start.m && trav_end.m == place_end.m) {
			if (trav_start.d >= place_start.d && trav_end.d <= place_end.d) {
				return true;
			}
		}
	}
	else {
		return false;
	}

}
DateCalc::~DateCalc(void) {}
/*if ((trav_start.y >= place_start.y && trav_start.y <= place_end.y) &&
	(trav_end.y >= place_start.y && trav_end.y <= place_end.y)) {
	if ((trav_start.m >= place_start.m && trav_start.m <= place_end.m)&&
		(trav_end.m >= place_start.m && trav_end.m <= place_end.m)           ) {
		return true;
	}
	if ((trav_start.d >= place_start.d && trav_start.d <= place_end.d) &&
			(trav_end.d >= place_start.d && trav_end.d <= place_end.d))
}*/


