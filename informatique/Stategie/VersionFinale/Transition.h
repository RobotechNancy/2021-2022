#ifndef TRANSITION_H
#define TRANSITION_H

#define CodeEgal 11
#define CodeSup 12
#define CodeSupEgal 13
#define CodeInf 14
#define CodeInfEgal 15
#define CodeDiff 16

#include <string>
using namespace std;

class Transition
{
    public:
        //CONTRUCTEURS DESTRUCTEUR
        Transition();
        Transition(int idT, int t);
        Transition(int idT, int t, string cond);
        Transition(int idT, int t, string cond, string variable, string egalite);
        virtual ~Transition();

        //GETTERS SETTERS
        unsigned int GetidTransition() { return idTransition; }
        void SetidTransition(int val) { idTransition = val; }
        int Gettype() { return type; }
        void Settype(int val) { type = val; }
        string Getcondition() { return condition; }
        void Setcondition(string val) { condition = val; }
        string GetFonctVar() { return fonct_variable; }
        void SetFonctVar(string val) { fonct_variable = val; }
        int Getoperateur() { return operateur; }
        void Setoperateur(int val) { operateur = val; }

        //INUTILE
        void genererTransition();
    protected:

    private:
        //Ce qui permet de définir une transition
        unsigned int idTransition;
        unsigned int type;
        string condition;
        string fonct_variable;
        int operateur; //Voir les codes définis en #define plus haut
};

#endif // TRANSITION_H
