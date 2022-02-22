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

//récupération de la condition (pas utilisé)
void Transition::genererTransition(){
    cout << "if(" << Getcondition() << "){" << endl;
}
