//
// Created by Sallee on 2023/4/4.
//
#pragma once

#include <pch.h>
#include "installThread.h"
#include "tianli_widget_super.h"

namespace tianli {
    class Install_widget : public tianli::tianli_widget_super {
      Q_OBJECT 
    public:
      explicit Install_widget(QWidget* parent = nullptr);
      ~Install_widget();
    protected:
      void init() override;
      void connectSignal() override;
    };


} // tianli
