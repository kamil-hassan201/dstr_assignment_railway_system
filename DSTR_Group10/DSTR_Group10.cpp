#include <iostream>
#include "StationList.h"
#include "StationNode.h"
#include "utils.h"

int main()
{
    StationList* sList = makeStationList();

    //sList->displayList();

    cout << "Distance: " << sList->calculateTime(8, 1) << endl;
    return 0;
}

