#include "pch.h"
#include "tianli_widget_super.h"


tianli::tianli_widget_super::tianli_widget_super(QWidget* parent) :
  QWidget(parent), ui(new Ui::tianli_widget) {
  //准备工作
  ui->setupUi(this);

  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground, true);

  //特效
  mainShadow = new QGraphicsDropShadowEffect();
  mainShadow->setOffset(0, 0);
  mainShadow->setColor(QColor(255, 255, 255));
  mainShadow->setBlurRadius(16);
  ui->label_MainShadow->setGraphicsEffect(mainShadow);

  mainShadowAnimation = new QPropertyAnimation(mainShadow, "color");
  mainShadowAnimation->setDuration(500);
  mainShadowAnimation->setEasingCurve(QEasingCurve::OutExpo);

  mainShadow_A = new QGraphicsDropShadowEffect();
  mainShadow_A->setOffset(0, 0);
  mainShadow_A->setColor(QColor(255, 255, 255));
  mainShadow_A->setBlurRadius(16);
  ui->label_MainShadow_A->setGraphicsEffect(mainShadow_A);

  mainShadow_B = new QGraphicsDropShadowEffect();
  mainShadow_B->setOffset(0, 0);
  mainShadow_B->setColor(QColor(255, 0, 0));
  mainShadow_B->setBlurRadius(14);
  ui->label_MainShadow_B->setGraphicsEffect(mainShadow_B);

  //初始化
  initRefQObejct();
  initTimeLine();

  //加载标题字体
  tianliWidgetUtils::setFont(":/font/Resource/fonts/SOURCEHANSERIFSC-HEAVY.ttf", ui->label_Title, true);   //标题 思源宋体
}

tianli::tianli_widget_super::~tianli_widget_super()
{
  delete ui;
}

inline void tianli::tianli_widget_super::connectSignal()
{
  //公用信号
  connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Close);
  connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Mini);

  //指针引用信号
  connect(this->fastButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Fast);
  connect(this->customButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Customize);
  connect(this->previewButton , &QPushButton::clicked, this, &tianli_widget_super::pushButton_preview);
  connect(this->cancelButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Cancel);
  connect(this->startProgramButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Finished_Run);
  connect(this->finishExitButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Finished_Exit);
  connect(this->errorExitButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Error_exit);
}

void tianli::tianli_widget_super::initTimeLine()
{
  int y = 51;

  time_line_label* timeLineLabel_1 = new time_line_label();
  timeLineLabel_1->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("复制文件"));
  timeLineLabel_1->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
  timeLineLabel_1->setParent(activedWidget->widget(1));
  timeLineLabel_1->setGeometry(102, y, 15, 124);
  timeLineLabel_1->setAction(false);
  timeLineLabel_1->setBegin(true);

  time_line_label* timeLineLabel_2 = new time_line_label();
  timeLineLabel_2->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("写入注册表"));
  timeLineLabel_2->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
  timeLineLabel_2->setParent(activedWidget->widget(1));
  timeLineLabel_2->setGeometry(102, y + 31 * 1, 15, 124);
  timeLineLabel_2->setAction(false);


  time_line_label* timeLineLabel_3 = new time_line_label();
  timeLineLabel_3->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("创建快捷方式"));
  timeLineLabel_3->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
  timeLineLabel_3->setParent(activedWidget->widget(1));
  timeLineLabel_3->setGeometry(102, y + 31 * 2, 15, 124);
  timeLineLabel_3->setAction(false);

  time_line_label* timeLineLabel_4 = new time_line_label();
  timeLineLabel_4->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("清理安装缓存"));
  timeLineLabel_4->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
  timeLineLabel_4->setParent(activedWidget->widget(1));
  timeLineLabel_4->setGeometry(102, y + 31 * 3, 15, 124);
  timeLineLabel_4->setAction(false);

  this->timeLineLabelList.emplace_back(timeLineLabel_1);
  this->timeLineLabelList.emplace_back(timeLineLabel_2);
  this->timeLineLabelList.emplace_back(timeLineLabel_3);
  this->timeLineLabelList.emplace_back(timeLineLabel_4);
}

void tianli::tianli_widget_super::setTimeLine(int step)
{
  for (int i = 0; i < step; i++)
  {
    this->timeLineLabelList[i]->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    this->timeLineLabelList[i]->setAction(true);
    this->timeLineLabelList[i]->setChecked(false);
  }
  this->timeLineLabelList[step]->findChild<QLabel*>("label_Title")->setStyleSheet("color:#000000");
  this->timeLineLabelList[step]->setAction(true);
  this->timeLineLabelList[step]->setChecked(true);
  this->activedTimeLabelIdx = step;
}

void tianli::tianli_widget_super::pushButton_UI_Close()
{
  //ui->stackedWidget->setCurrentIndex(3);

  //ui.label_MainShadow->hide();

  ui->label_MainShadow_A->hide();
  ui->label_MainShadow_B->hide();
  ui->pushButton_UI_Close->hide();
  ui->pushButton_UI_Mini->hide();

  // 渐渐缩小
  exitAnimation = new QPropertyAnimation(ui->label_MainShadow, "geometry");
  exitAnimation->setDuration(200);
  exitAnimation->setEndValue(QRect(10 + 50, 20 + 50, 720 - 100, 384 - 100));
  connect(exitAnimation, &QPropertyAnimation::valueChanged, [=]() {
    this->update();
    });
  connect(exitAnimation, &QPropertyAnimation::finished, [=]() {
    this->close();
    });
  exitAnimation->start();
  // 渐渐隐藏
  exitAnimation_hide = new QPropertyAnimation(ui->label_MainShadow, "windowOpacity");

  update();

  //this->close();
}

void tianli::tianli_widget_super::closeEvent(QCloseEvent* event)
{
  if (activedWidget->currentIndex() == 3)  //安装失败，关闭时清理注册表，防止出现无法卸载
  {
    tianliWidgetUtils::cleanUninstallReg();
  }
  event->accept();
}

void tianli::tianli_widget_super::pushButton_UI_Mini()
{
  this->showMinimized();
}

void tianli::tianli_widget_super::pushButton_Fast()
{
  //安装时再做检测以避免默认路径有其他软件
  QString folderPathStr = pathLineEdit->text();
  QString outPathStr = "";
  if (tianliWidgetUtils::checkPathIsAvilable(folderPathStr, outPathStr))
  {
    if (outPathStr != folderPathStr)
    {
      QMessageBox::warning(this, QString::fromLocal8Bit("路径无效"), QString::fromLocal8Bit("请选择空白文件夹或者旧版“空荧酒馆原神地图”安装路径"));
      return;
    }
    this->activedWidget->setCurrentIndex(1);
    this->beginProcess();
  }
  else
  {
    QMessageBox::warning(this, QString::fromLocal8Bit("路径无效"), QString::fromLocal8Bit("请选择空白文件夹或者旧版“空荧酒馆原神地图”安装路径"));
    return;
  }
}

void tianli::tianli_widget_super::pushButton_Customize()
{
  qobject_cast<QStackedWidget*>(this->customButton->parentWidget())->setCurrentIndex(1);
}

void tianli::tianli_widget_super::pushButton_preview()
{
  QString folderPathStr = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("请选择需要安装的文件夹"), pathLineEdit->text());
  if (folderPathStr == "")
    return;

  QString outPathStr = "";
  if (!tianliWidgetUtils::checkPathIsAvilable(folderPathStr, outPathStr))
  {
    QMessageBox::warning(this, QString::fromLocal8Bit("路径无效"), QString::fromLocal8Bit("请选择空白文件夹或者旧版“空荧酒馆原神地图”安装路径"));
    return;
  }
  pathLineEdit->setText(outPathStr);
}

void tianli::tianli_widget_super::pushButton_Cancel()
{
  //installThread->terminate(); //强行停止线程
  activedWidget->setCurrentIndex(3);
  ui->pushButton_UI_Close->setHidden(false);
  errorInfoLabel->setText(QString::fromLocal8Bit("用户终止了安装操作"));
}

void tianli::tianli_widget_super::pushButton_Finished_Run()
{
  QProcess process;
  process.startDetached(QString::fromStdWString(L"\"" + (ui->lineEdit_installPath->text() + "\\map.exe").toStdWString() + L"\""));
  this->close();
}

void tianli::tianli_widget_super::pushButton_Finished_Exit()
{
  this->close();
}

void tianli::tianli_widget_super::pushButton_Error_exit()
{
  this->close();
}

void tianli::tianli_widget_super::setThreadPrecent(int percent)
{
  QLabel* progressBar = this->timeLineLabelList[this->activedTimeLabelIdx]->findChild<QLabel*>("label_ProgressBar");
  QRect progressGeometry = progressBar->geometry();
  progressGeometry.setWidth((percent / 100.0) * 261);
  progressBar->setGeometry(progressGeometry);
}

void tianli::tianli_widget_super::changeThreadState(int state)
{
  setTimeLine(state);
}

void tianli::tianli_widget_super::onThreadFinish()
{
  ui->pushButton_UI_Close->setHidden(false);
  activedWidget->setCurrentIndex(2);
}

void tianli::tianli_widget_super::onThreadThrowError(QString error)
{
  this->activedWidget->setCurrentIndex(3);
  ui->pushButton_UI_Close->setHidden(false);
  this->errorInfoLabel->setText(error);
}

void tianli::tianli_widget_super::beginProcess()
{
  ui->pushButton_UI_Close->setHidden(true);
  QString installPath = this->pathLineEdit->text();
  bool desktopShortcut = this->desktopCheckBox->isChecked();
  bool startMenuShortcut = this->startmenuCheckBox->isChecked();

  emit this->setInstallConfig(installPath, desktopShortcut, startMenuShortcut);
  //installThread->start();
}