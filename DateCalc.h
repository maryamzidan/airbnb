#pragma once
#include"Main_Menu.h"
#include"structs.h"
class Main_Menu;
class DateCalc
{
public:
    DateCalc(void);

    static int diff(date d1, date d2);
    static bool CheckForAvability(date place_s, date place_e, date trav_s, date trav_e);


    ~DateCalc(void);

};




