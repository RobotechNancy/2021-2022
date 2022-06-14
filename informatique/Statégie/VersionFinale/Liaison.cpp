#include "Liaison.h"
#include "Etat.h"
#include <string>

using namespace std;

Liaison::Liaison(Etat &e1, Etat &e2)
{
    m_debut = e1;
    m_fin = e2;
}

Liaison::Liaison()
{
}

Liaison::~Liaison()
{
}

string Liaison::toString(){
    return m_debut.getNom() + " -- " + m_fin.getNom();
}
