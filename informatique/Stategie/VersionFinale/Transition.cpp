#include "Transition.h"
#include <iostream>
#include <string>
Transition::Transition()
{
    //ctor
}

Transition::Transition(int idT, int t, string cond, string variable, string egalite)
{
    idTransition = idT;
    type = t;
    condition = cond;
    fonct_variable = variable;
    if(egalite == "==")
        operateur = CodeEgal;
    else if(egalite == ">")
        operateur = CodeSup;
    else if(egalite == ">=")
        operateur = CodeSupEgal;
    else if(egalite == "<")
        operateur = CodeInf;
    else if(egalite == "<=")
        operateur = CodeInfEgal;
    else if(egalite == "!=")
        operateur = CodeDiff;
}

Transition::Transition(int idT, int t, string cond)
{
    idTransition = idT;
    type = t;
    condition = cond;
}
Transition::Transition(int idT, int t)
{
    idTransition = idT;
    type = t;
}
Transition::~Transition()
{
    //dtor
}

//récupération de la condition (pas utilisé)
void Transition::genererTransition(){
    cout << "if(" << Getcondition() << "){" << endl;
}
