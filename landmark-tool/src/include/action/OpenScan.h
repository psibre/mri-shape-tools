#ifndef __OPEN_SCAN_H__
#define __OPEN_SCAN_H__

#include "action/Action.h"
#include "singleton/Data.h"
#include "core/ImageStackBuilder.h"

#include "image/Image.h"

class OpenScan : public Action {

 public:

  OpenScan(const std::string& path) {

    this->image.read().from(path);

  }

  /*----------------------------------------------------------------------*/

  virtual void execute() {

    ImageStackBuilder builder;
    Data::get_instance()->set_image_stack(builder.build_from(this->image));

    Data::get_instance()->set_original_image(this->image);
    Data::get_instance()->set_current_image(this->image);

  }

  /*----------------------------------------------------------------------*/

 private:

  Image image;

};
#endif
