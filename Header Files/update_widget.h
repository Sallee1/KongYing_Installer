//
// Created by Sallee on 2023/4/5.
//
#pragma once
#include <pch.h>
#include "installThread.h"
#include "tianli_widget_super.h"
#include "time_line_label.h"

namespace tianli {
  class update_widget : public tianli::tianli_widget_super {
    Q_OBJECT
  public:
    explicit update_widget(QWidget* parent = nullptr);
    ~update_widget();
  protected:
    void init() override;
    void connectSignal() override;
    void pushButton_Fast();
    void afterClose() override;
  };


} // tianli
