#include "Transition.h"
#include <iostream>
#include <string>
Transition::Transition()
{
    //ctor
}

Transition::Transition(int idT, string cond)
{
    idTransition = idT;
    condition = cond;
}

Transition::~Transition()
{
    //dtor
}

//r�cup�ration de la condition (pas utilis�)
void Transition::genererTransition(){
    cout << "if(" << Getcondition() << "){" << endl;
}
