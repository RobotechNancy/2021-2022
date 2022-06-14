#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
using namespace std;

class Transition
{
    public:
        //CONTRUCTEURS DESTRUCTEUR
        Transition();
        Transition(int idT, string cond);
        virtual ~Transition();

        //GETTERS SETTERS
        int GetidTransition() { return idTransition; }
        void SetidTransition(int val) { idTransition = val; }
        string Getcondition() { return condition; }
        void Setcondition(string val) { condition = val; }

        //Fonction qui génère la transition = affichage if else avec la variable Condition
        void genererTransition();
    protected:

    private:
        int idTransition;
        string condition;
};

#endif // TRANSITION_H
