#ifndef INFORMATIONSTOFVIEW_HPP
#define INFORMATIONSTOFVIEW_HPP

#include <gui_generated/informationstof_screen/InformationsTofViewBase.hpp>
#include <gui/informationstof_screen/InformationsTofPresenter.hpp>

class InformationsTofView : public InformationsTofViewBase
{
public:
    InformationsTofView();
    virtual ~InformationsTofView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INFORMATIONSTOFVIEW_HPP
