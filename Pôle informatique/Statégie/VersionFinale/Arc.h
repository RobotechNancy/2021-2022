#ifndef ARC_H
#define ARC_H

#include "Transition.h"
class Arc
{
    public:
        Arc();
        Arc(int et, Transition &transition);
        virtual ~Arc();


        int GetnoEtape() { return noEtape; }
        void SetnoEtape(int val) { noEtape = val; }
        Transition* GetnoTransition() { return noTransition; }
        void SetnoTransition(Transition* t) { noTransition = t; }

        void genererArc();
    protected:

    private:
//        Etat* etatSortie;
        int noEtape;
//      int noTransition;
        Transition* noTransition;
};

#endif // ARC_H
