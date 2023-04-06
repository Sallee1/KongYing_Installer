#pragma once
//
// Created by Sallee on 2023/4/5.
//

#include "uninstall_widget.h"

#pragma once
#include <pch.h>
#include "installThread.h"
#include "tianli_widget_super.h"
#include "time_line_label.h"

namespace tianli {
  class uninstall_widget : public tianli::tianli_widget_super {
    Q_OBJECT
  public:
    explicit uninstall_widget(QWidget* parent = nullptr);
    ~uninstall_widget();
  protected:
    void init() override;
    void connectSignal() override;
    void pushButton_Fast();
    void beginProcess() override;
    

  signals:
    void setUninstallConfig(bool); //初始化卸载线程
  };

} // tianli