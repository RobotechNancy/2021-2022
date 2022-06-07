#ifndef ACCUEILVIEW_HPP
#define ACCUEILVIEW_HPP

#include <gui_generated/accueil_screen/AccueilViewBase.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>

class AccueilView : public AccueilViewBase
{
public:
    AccueilView();
    virtual ~AccueilView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ACCUEILVIEW_HPP
