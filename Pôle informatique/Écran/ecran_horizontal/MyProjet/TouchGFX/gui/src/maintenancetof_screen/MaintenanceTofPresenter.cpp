#include <gui/maintenancetof_screen/MaintenanceTofView.hpp>
#include <gui/maintenancetof_screen/MaintenanceTofPresenter.hpp>

MaintenanceTofPresenter::MaintenanceTofPresenter(MaintenanceTofView& v)
    : view(v)
{

}

void MaintenanceTofPresenter::activate()
{

}

void MaintenanceTofPresenter::deactivate()
{

}

void MaintenanceTofPresenter::uartMsgRdy(){
	view.uartMsgRdy();
}
