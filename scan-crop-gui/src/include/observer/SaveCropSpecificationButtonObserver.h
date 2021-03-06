#ifndef __SAVE_CROP_SPECIFICATION_BUTTON_OBSERVER_H__
#define __SAVE_CROP_SPECIFICATION_BUTTON_OBSERVER_H__

#include <gtkmm/toolbutton.h>

#include "action/ShowSaveCropSpecificationDialog.h"
#include "singleton/GuiDescription.h"

/** Class that watches the state of the openImageStackButton */
class SaveCropSpecificationButtonObserver {
  public:

    /*-----------------------------------------------------------------------*/

    SaveCropSpecificationButtonObserver() {
      // get builder from gui description
      Glib::RefPtr<Gtk::Builder> builder =
        GuiDescription::get_instance()->get_builder();

      // get button to watch
      Gtk::ToolButton* button;
      builder->get_widget("saveCropSpecificationButton", button);

      // connect handler to clicked signal
      this->clickHandler = button->signal_clicked().connect(
          sigc::mem_fun(*this, &SaveCropSpecificationButtonObserver::clicked)
          );
    }


    /*-----------------------------------------------------------------------*/

    ~SaveCropSpecificationButtonObserver() {
      this->clickHandler.disconnect();
    }

    /*-----------------------------------------------------------------------*/

    void clicked() {
      // open the dialog
      ShowSaveCropSpecificationDialog action;
      action.execute();
    }

    /*-----------------------------------------------------------------------*/

  private:
    sigc::connection clickHandler;
};

#endif
