#ifndef LIAISON_H
#define LIAISON_H

#include "Etat.h"

#include <string>

using namespace std;

class Liaison
{
    public:
        Liaison();
        Liaison(Etat &e1, Etat &e2);
        virtual ~Liaison();

        string toString();
    private:
        Etat m_debut;
        Etat m_fin;
};

#endif // LIAISON_H
