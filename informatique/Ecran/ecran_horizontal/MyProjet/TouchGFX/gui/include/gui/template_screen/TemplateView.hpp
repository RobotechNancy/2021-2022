#ifndef TEMPLATEVIEW_HPP
#define TEMPLATEVIEW_HPP

#include <gui_generated/template_screen/TemplateViewBase.hpp>
#include <gui/template_screen/TemplatePresenter.hpp>

class TemplateView : public TemplateViewBase
{
public:
    TemplateView();
    virtual ~TemplateView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TEMPLATEVIEW_HPP
