#include "Arc.h"
#include "Transition.h"

#include <iostream>

Arc::Arc()
{
}

Arc::Arc(int et, Transition &transition)
{
    noEtape = et;
    noTransition = &transition;
    //FONCTIONNE
}

Arc::~Arc()
{
}

void Arc::genererArc(){
    //NE MARCHE PAS ICI
    cout << noTransition->Getcondition() << endl;
    noTransition->genererTransition();

    cout << "}" << endl;
}
