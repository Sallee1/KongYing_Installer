//
// Created by YuSuiXian on 2023/2/9.
//

#ifndef TIANLI_INSTALLER_TIANLI_WIDGET_H
#define TIANLI_INSTALLER_TIANLI_WIDGET_H
#include <pch.h>
#include "installThread.h"
#include "tianli_widget_super.h"
#include "time_line_label.h"

namespace tianli {
    class Install_widget : public tianli::tianli_widget_super {

    protected:
      void init() override;
    };


} // tianli

#endif //TIANLI_INSTALLER_TIANLI_WIDGET_H
