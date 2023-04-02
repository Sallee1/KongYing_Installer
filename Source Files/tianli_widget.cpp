//
// Created by YuSuiXian on 2023/2/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_tianli_widget.h" resolved

#include "pch.h"
#include "tianli_widget.h"
#include "ui_tianli_widget.h"
#include "tianli_widget_utils.h"
#include "time_line_label.h"
#include "config.h"

namespace tianli {
  tianli_widget::tianli_widget(QWidget* parent) :
    QWidget(parent), ui(new Ui::tianli_widget) {
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);


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
    initTimeLine();

    //connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget::close);
    //connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget::showMinimized);

    connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget::pushButton_UI_Close);
    connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget::pushButton_UI_Mini);
    connect(ui->pushButton_FastInstall, &QPushButton::clicked, this, &tianli_widget::pushButton_FastInstall);
    connect(ui->pushButton_CustomizeInstall, &QPushButton::clicked, this, &tianli_widget::pushButton_CustomizeInstall);
    connect(ui->pushButton_Finishing_Cancel, &QPushButton::clicked, this, &tianli_widget::pushButton_Finishing_Cancel);
    connect(ui->pushButton_Finished_Run, &QPushButton::clicked, this, &tianli_widget::pushButton_Finished_Run);
    connect(ui->pushButton_Finished_Exit, &QPushButton::clicked, this, &tianli_widget::pushButton_Finished_Exit);
    connect(ui->pushButton_preview, &QPushButton::clicked, this, &tianli_widget::pushButton_preview);
    //���ر�������
    tianliWidgetUtils::setFont(":/font/Resource/fonts/SOURCEHANSERIFSC-HEAVY.ttf",ui->label_Title,true);   //���� ˼Դ����
    auto buttonList = ui->stackedWidget->findChildren<QPushButton*>();

    //��װ�߳���ص��źŲ�
    connect(installThread, &InstallThread::processChange, this, &tianli_widget::changeInstallState);
    connect(this, &tianli_widget::setInstallConfig, installThread, &InstallThread::setInstallConfig);
    connect(installThread, &InstallThread::processPercent, this, &tianli_widget::setProgress);
    connect(installThread, &InstallThread::installFinish, this, &tianli_widget::endInstall);
    ui->stackedWidget->setCurrentIndex(0);
    ui->widget_CustomOption->setHidden(true);   //Ĭ�������Զ���ѡ��
    ui->label_Readme->setOpenExternalLinks(true);   //���������
    //�������õ����Զ���ѡ��
    ui->lineEdit_installPath->setText(QString::fromStdWString(config::installInfo.defaultInstallPath));
    ui->checkBox_desktopShortcut->setChecked(config::installInfo.desktopShortcut);
    ui->checkBox_startMenuShortCut->setChecked(config::installInfo.startmenuShortcut);
    //����Ƿ�װ������װ�����Զ�����
    setupInstallOrUpdate();
  }

  tianli_widget::~tianli_widget() {
    delete ui;
  }

  void tianli_widget::initTimeLine()
  {

    int y = 51;

    time_line_label* timeLineLabel_1 = new time_line_label();
    timeLineLabel_1->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("�����ļ�"));
    timeLineLabel_1->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_1->setParent(ui->stackedWidget->widget(1));
    timeLineLabel_1->setGeometry(102, y, 15, 124);
    timeLineLabel_1->setAction(false);
    timeLineLabel_1->setBegin(true);

    time_line_label* timeLineLabel_2 = new time_line_label();
    timeLineLabel_2->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("д��ע���"));
    timeLineLabel_2->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_2->setParent(ui->stackedWidget->widget(1));
    timeLineLabel_2->setGeometry(102, y + 31 * 1, 15, 124);
    timeLineLabel_2->setAction(false);


    time_line_label* timeLineLabel_3 = new time_line_label();
    timeLineLabel_3->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("������ݷ�ʽ"));
    timeLineLabel_3->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_3->setParent(ui->stackedWidget->widget(1));
    timeLineLabel_3->setGeometry(102, y + 31 * 2, 15, 124);
    timeLineLabel_3->setAction(false);

    time_line_label* timeLineLabel_4 = new time_line_label();
    timeLineLabel_4->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("����װ����"));
    timeLineLabel_4->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_4->setParent(ui->stackedWidget->widget(1));
    timeLineLabel_4->setGeometry(102, y + 31 * 3, 15, 124);
    timeLineLabel_4->setAction(false);

    this->timeLineLabelList.emplace_back(timeLineLabel_1);
    this->timeLineLabelList.emplace_back(timeLineLabel_2);
    this->timeLineLabelList.emplace_back(timeLineLabel_3);
    this->timeLineLabelList.emplace_back(timeLineLabel_4);
  }

  void tianli_widget::setTimeLine(int step)
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

  void tianli_widget::setupInstallOrUpdate()
  {
    //��ȡע����Ϣ������Ѿ���װ���Զ�����λ�ã����޸�����Ϊ����������·��ѡ��
    HKEY hKey;
    std::wstring regPath = std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName);
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, regPath.c_str(), 0, KEY_READ, &hKey);
    if (lResult == ERROR_SUCCESS) {
      wchar_t szBuffer[4096];
      DWORD dwType;
      DWORD dwSize = sizeof(szBuffer);
      lResult = RegGetValue(hKey, NULL, L"InstallLocation", RRF_RT_REG_SZ, &dwType, szBuffer, &dwSize);
      if (lResult == ERROR_SUCCESS) {
        //�Ѿ���װ��������·��ѡ��
        ui->lineEdit_installPath->setText(QString::fromWCharArray(szBuffer));
        ui->lineEdit_installPath->setHidden(true);
        ui->pushButton_preview->setHidden(true);
        ui->label_FastInstall->setText(QString::fromLocal8Bit("����"));
        //����ݷ�ʽ�Ƿ���ڣ���������ȡ����ѡ
        if (!fs::exists(std::format(L"{0}\\{1}", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation).toStdWString(), config::installInfo.desktopShortcut_name)))
          ui->checkBox_desktopShortcut->setChecked(false);
        else
          ui->checkBox_desktopShortcut->setChecked(true);
        if (!fs::exists(std::format(L"{0}\\{1}\\{2}", QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation).toStdWString(), config::installInfo.startmenuShortcut_foldname,config::installInfo.startmenuShortcut_progarmName)))
          ui->checkBox_startMenuShortCut->setChecked(false);
        else
          ui->checkBox_startMenuShortCut->setChecked(false);
      }
    }
  }

  void tianli_widget::mousePressEvent(QMouseEvent* event)
  {
    if (event->button() == Qt::LeftButton &&
      ui->label_MainShadow->frameRect().contains(event->globalPos() - this->frameGeometry().topLeft())) {
      m_Press = event->globalPos();
      leftBtnClk = true;
    }
    event->ignore();
  }

  void tianli_widget::mouseReleaseEvent(QMouseEvent* event)
  {
    if (event->button() == Qt::LeftButton) {
      leftBtnClk = false;
    }
    event->ignore();
  }
  void tianli_widget::mouseMoveEvent(QMouseEvent* event)
  {
    if (leftBtnClk) {
      m_Move = event->globalPos();
      this->move(this->pos() + m_Move - m_Press);
      m_Press = m_Move;
    }
    event->ignore();
  }
  bool tianli_widget::eventFilter(QObject* object, QEvent* event)
  {
    if (event->type() == QEvent::ActivationChange)
    {
      if (QApplication::activeWindow() != this)
      {
        // ����ת��
        mainShadow_B->setEnabled(false);
      }
      else
      {
        //����ת��
        mainShadow_B->setEnabled(true);
      }
    }
    if (event->type() == QEvent::Enter)
    {
      mainShadowAnimation->stop();
      mainShadowAnimation->setEndValue("#FF1C1C");
      mainShadowAnimation->start();
    }
    if (event->type() == QEvent::Leave)
    {
      mainShadowAnimation->stop();
      mainShadowAnimation->setEndValue("#DDDDDD");
      mainShadowAnimation->start();
    }
    return QWidget::eventFilter(object, event);
  }

  void tianli_widget::closeEvent(QCloseEvent* event)
  {
    if(ui->stackedWidget->currentIndex() == 3)  //��װʧ�ܣ��ر�ʱ����ע�����ֹ�����޷�ж��
    {
      HKEY hKey;
      RegOpenKeyEx(HKEY_CURRENT_USER, std::format(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{0}", config::reginfo.displayName).c_str(), 0, KEY_ALL_ACCESS, &hKey);
      RegDeleteTree(hKey, NULL);
      RegCloseKey(hKey);
    }
    event->accept();
  }

  void tianli_widget::pushButton_UI_Close()
  {
    ui->stackedWidget->setCurrentIndex(3);

    //ui.label_MainShadow->hide();

    ui->label_MainShadow_A->hide();
    ui->label_MainShadow_B->hide();
    ui->pushButton_UI_Close->hide();
    ui->pushButton_UI_Mini->hide();

    // ������С
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
    // ��������
    exitAnimation_hide = new QPropertyAnimation(ui->label_MainShadow, "windowOpacity");

    update();

    //this->close();

  }

  void tianli_widget::pushButton_UI_Mini()
  {
    this->showMinimized();
  }

  void tianli_widget::pushButton_FastInstall()
  {
    //��װʱ��������Ա���Ĭ��·�����������
    QString folderPathStr = ui->lineEdit_installPath->text();
    QString outPathStr = "";
    if (!tianliWidgetUtils::checkPathIsAvilable(folderPathStr, outPathStr))
    {
      QMessageBox::warning(this, QString::fromLocal8Bit("·����Ч"), QString::fromLocal8Bit("��ѡ��հ��ļ��л��߾ɰ桰��ӫ�ƹ�ԭ���ͼ����װ·��"));
      return;
    }
    ui->stackedWidget->setCurrentIndex(1);
    this->beginInstall();
  }

  void tianli_widget::pushButton_CustomizeInstall()
  {
    ui->widget_CustomOption->setHidden(false);
    ui->widget_CustomButtom->setHidden(true);
  }

  void tianli_widget::pushButton_preview()
  {
    QString folderPathStr = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("��ѡ����Ҫ��װ���ļ���"), ui->lineEdit_installPath->text());
    if (folderPathStr == "")
      return;
    
    QString outPathStr = "";
    if (!tianliWidgetUtils::checkPathIsAvilable(folderPathStr, outPathStr))
    {
      QMessageBox::warning(this, QString::fromLocal8Bit("·����Ч"), QString::fromLocal8Bit("��ѡ��հ��ļ��л��߾ɰ桰��ӫ�ƹ�ԭ���ͼ����װ·��"));
      return;
    }
    ui->lineEdit_installPath->setText(outPathStr);
  }


  void tianli_widget::setProgress(int percent)
  {
    QLabel* progressBar = this->timeLineLabelList[this->activedTimeLabelIdx]->findChild<QLabel*>("label_ProgressBar");
    QRect progressGeometry = progressBar->geometry();
    progressGeometry.setWidth((percent / 100.0) * 261);
    progressBar->setGeometry(progressGeometry);
  }


  void tianli_widget::beginInstall()
  {
    ui->pushButton_UI_Close->setHidden(true);
    QString installPath = ui->lineEdit_installPath->text();
    bool desktopShortcut = ui->checkBox_desktopShortcut->isChecked();
    bool startMenuShortcut = ui->checkBox_desktopShortcut->isChecked();

    emit this->setInstallConfig(installPath,desktopShortcut,startMenuShortcut);
    installThread->start();
  }

  void tianli_widget::endInstall()
  {
    ui->pushButton_UI_Close->setHidden(false);
    ui->stackedWidget->setCurrentIndex(2);
  }

  void tianli_widget::changeInstallState(int state)
  {
    setTimeLine(state);
  }

  void tianli_widget::onInstallError(std::invalid_argument e)
  {
    
  }

  void tianli_widget::pushButton_Finishing_Cancel()
  {
    installThread->terminate(); //ǿ��ֹͣ�߳�
    ui->stackedWidget->setCurrentIndex(3);
    ui->pushButton_UI_Close->setHidden(false);
    ui->label_err_info->setText("�û���ֹ�˰�װ����");
  }

  void tianli_widget::pushButton_Finished_Run()
  {
    QProcess process;
    process.startDetached(QString::fromStdWString(L"\""+(ui->lineEdit_installPath->text() + "\\map.exe").toStdWString() + L"\""));
    this->close();
  }

  void tianli_widget::pushButton_Finished_Exit()
  {
    this->close();
  }

} // tianli
