#include "Road.h"
#include "Area.h"
#include "Harbour.h"
#include "Runway.h"


int main()
{
    Area *area1;
    Area *area2;
    Area *area3;

    Runway *runway = new Runway(area1, "runway1");
    Harbour *harbour = new Harbour(area2, "harbour1");
    Road *road = new Road(area3, "road1");
    
    return 0;
}