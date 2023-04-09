#include "pch.h"
#include "tianli_widget_super.h"

namespace tianli {

  tianli_widget_super::tianli_widget_super(QWidget* parent) :
    QWidget(parent), ui(new Ui::tianli_widget) {
    //׼������
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    //��Ч
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
    //��������
    ui->label_Readme->setOpenExternalLinks(true);
    ui->label_Readme_Update->setOpenExternalLinks(true);
    //���ر�������
    tianliUtils::setFont(":/font/Resource/fonts/SOURCEHANSERIFSC-HEAVY.ttf", ui->label_Title, true);   //���� ˼Դ����
  }

  tianli_widget_super::~tianli_widget_super()
  {
    delete ui;
  }

  inline void tianli_widget_super::afterInit() {
    connectSignal();
    initTimeLine();
    //����Ĭ������
    this->pathLineEdit->setText(QString::fromLocal8Bit(tianli::config::installInfo.defaultInstallPath.c_str()));
    this->desktopCheckBox->setChecked(tianli::config::installInfo.desktopShortcut);
    this->startmenuCheckBox->setChecked(tianli::config::installInfo.startmenuShortcut);

  }

  void tianli_widget_super::connectSignal()
  {
    //�����ź�
    connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Close);
    connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget_super::pushButton_UI_Mini);

    //ָ�������ź�
    connect(this->fastButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Fast);
    connect(this->customButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Customize);
    connect(this->previewButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_preview);
    connect(this->cancelButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Cancel);
    connect(this->startProgramButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Finished_Run);
    connect(this->finishExitButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Finished_Exit);
    connect(this->errorExitButton, &QPushButton::clicked, this, &tianli_widget_super::pushButton_Error_exit);

    //�߳��ź�
    connect(this, &tianli_widget_super::setInstallConfig, this->thread, &Thread_super::setInstallConfig);
    connect(this->thread, &Thread_super::processChange, this, &tianli_widget_super::processChange);
    connect(this->thread, &Thread_super::processPercent, this, &tianli_widget_super::processPercent);
    connect(this->thread, &Thread_super::processFinish, this, &tianli_widget_super::onThreadFinish);
    connect(this->thread, &Thread_super::throwError, this, &tianli_widget_super::onThreadThrowError);
  }


  inline void tianli_widget_super::afterClose() 
  {
    if (activedWidget->currentIndex() == 3)  //��װʧ��
    {
      tianliUtils::cleanUninstallReg();
    }
    else if(activedWidget->currentIndex() == 2)   //��װ�ɹ�
    {
      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << "cloneInstaller.bat");
    }
    //ֻ�а�װ����TempĿ¼������������ɾ�����Ա�����ɾ
    fs::path pt1 = fs::absolute(fs::path(".."));
    fs::path pt2 = tianliUtils::envPath2AbsolutePath("%TEMP%");
    if (fs::equivalent(fs::path("..\\"), tianliUtils::envPath2AbsolutePath("%TEMP%")))
    {
      QFile removeSelfBat("removeSelf.bat");
      removeSelfBat.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
      {
        QTextStream qOut(&removeSelfBat);
        qOut << QString::fromLocal8Bit(bat::removeSelf.c_str());
      }
      removeSelfBat.close();

      QProcess process;
      process.startDetached("cmd.exe", QStringList() << "/c" << "removeSelf.bat");
      return;
    }
  }

  void tianli_widget_super::initTimeLine()
  {
    int y = 51;

    time_line_label* timeLineLabel_1 = new time_line_label();
    timeLineLabel_1->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("�����ļ�"));
    timeLineLabel_1->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_1->setParent(activedWidget->widget(1));
    timeLineLabel_1->setGeometry(102, y, 15, 124);
    timeLineLabel_1->setAction(false);
    timeLineLabel_1->setBegin(true);

    time_line_label* timeLineLabel_2 = new time_line_label();
    timeLineLabel_2->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("д��ע���"));
    timeLineLabel_2->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_2->setParent(activedWidget->widget(1));
    timeLineLabel_2->setGeometry(102, y + 31 * 1, 15, 124);
    timeLineLabel_2->setAction(false);


    time_line_label* timeLineLabel_3 = new time_line_label();
    timeLineLabel_3->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("������ݷ�ʽ"));
    timeLineLabel_3->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_3->setParent(activedWidget->widget(1));
    timeLineLabel_3->setGeometry(102, y + 31 * 2, 15, 124);
    timeLineLabel_3->setAction(false);

    time_line_label* timeLineLabel_4 = new time_line_label();
    timeLineLabel_4->findChild<QLabel*>("label_Title")->setText(QString::fromLocal8Bit("����װ����"));
    timeLineLabel_4->findChild<QLabel*>("label_Title")->setStyleSheet("color:#999999");
    timeLineLabel_4->setParent(activedWidget->widget(1));
    timeLineLabel_4->setGeometry(102, y + 31 * 3, 15, 124);
    timeLineLabel_4->setAction(false);

    this->timeLineLabelList.emplace_back(timeLineLabel_1);
    this->timeLineLabelList.emplace_back(timeLineLabel_2);
    this->timeLineLabelList.emplace_back(timeLineLabel_3);
    this->timeLineLabelList.emplace_back(timeLineLabel_4);
  }

  void tianli_widget_super::setTimeLine(int step)
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

  void tianli_widget_super::pushButton_UI_Close()
  {
    //ui->stackedWidget->setCurrentIndex(3);

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

  void tianli_widget_super::mousePressEvent(QMouseEvent* event)
  {
    if (event->button() == Qt::LeftButton &&
      ui->label_MainShadow->frameRect().contains(event->globalPos() - this->frameGeometry().topLeft())) {
      m_Press = event->globalPos();
      leftBtnClk = true;
    }
    event->ignore();
  }

  void tianli_widget_super::mouseReleaseEvent(QMouseEvent* event)
  {
    if (event->button() == Qt::LeftButton) {
      leftBtnClk = false;
    }
    event->ignore();
  }

  void tianli_widget_super::mouseMoveEvent(QMouseEvent* event)
  {
    if (leftBtnClk) {
      m_Move = event->globalPos();
      this->move(this->pos() + m_Move - m_Press);
      m_Press = m_Move;
    }
    event->ignore();
  }

  void tianli_widget_super::closeEvent(QCloseEvent* event)
  {
    if (activedWidget->currentIndex() == 3)  //��װʧ�ܣ��ر�ʱ����ע�����ֹ�����޷�ж��
    {
      tianliUtils::cleanUninstallReg();
    }
    afterClose();
    event->accept();
  }

  bool tianli_widget_super::eventFilter(QObject* object, QEvent* event)
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

  void tianli_widget_super::pushButton_UI_Mini()
  {
    this->showMinimized();
  }

  void tianli_widget_super::pushButton_Fast()
  {
    //��װʱ��������Ա���Ĭ��·�����������
    QString folderPathStr = pathLineEdit->text();
    QString outPathStr = "";
    if (tianliUtils::checkPathIsAvilable(folderPathStr, outPathStr))
    {
      if (outPathStr != folderPathStr)
      {
        QMessageBox::warning(this, QString::fromLocal8Bit("·����Ч"), QString::fromLocal8Bit("��ѡ��հ��ļ��л��߾ɰ桰��ӫ�ƹ�ԭ���ͼ����װ·��"));
        return;
      }
      this->activedWidget->setCurrentIndex(1);
      this->beginProcess();
    }
    else
    {
      QMessageBox::warning(this, QString::fromLocal8Bit("·����Ч"), QString::fromLocal8Bit("��ѡ��հ��ļ��л��߾ɰ桰��ӫ�ƹ�ԭ���ͼ����װ·��"));
      return;
    }
  }

  void tianli_widget_super::pushButton_Customize()
  {
    customStackedWidget->setCurrentIndex(1);
  }

  void tianli_widget_super::pushButton_preview()
  {
    QString folderPathStr = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("��ѡ����Ҫ��װ���ļ���"), pathLineEdit->text());
    if (folderPathStr == "")
      return;
    folderPathStr = QDir::toNativeSeparators(folderPathStr);  //ת��Ϊwindows��б��

    QString outPathStr = "";
    if (!tianliUtils::checkPathIsAvilable(folderPathStr, outPathStr))
    {
      QMessageBox::warning(this, QString::fromLocal8Bit("·����Ч"), QString::fromLocal8Bit("��ѡ��հ��ļ��л��߾ɰ桰��ӫ�ƹ�ԭ���ͼ����װ·��"));
      return;
    }
    pathLineEdit->setText(outPathStr);
  }

  void tianli_widget_super::pushButton_Cancel()
  {
    thread->terminate(); //ǿ��ֹͣ�߳�
    activedWidget->setCurrentIndex(3);
    ui->pushButton_UI_Close->setHidden(false);
    errorInfoLabel->setText(QString::fromLocal8Bit("�û���ֹ�˰�װ����"));
  }

  void tianli_widget_super::pushButton_Finished_Run()
  {
    QProcess process;
    std::string processPath = std::format("\"{0}\\{1}\"", std::string(ui->lineEdit_installPath->text().toLocal8Bit()), config::installInfo.exePath);
    process.startDetached(QString::fromLocal8Bit(processPath.c_str()));
    this->close();
  }

  void tianli_widget_super::pushButton_Finished_Exit()
  {
    this->close();
  }

  void tianli_widget_super::pushButton_Error_exit()
  {
    this->close();
  }

  void tianli_widget_super::processPercent(int percent)
  {
    QLabel* progressBar = this->timeLineLabelList[this->activedTimeLabelIdx]->findChild<QLabel*>("label_ProgressBar");
    QRect progressGeometry = progressBar->geometry();
    progressGeometry.setWidth((percent / 100.0) * 261);
    progressBar->setGeometry(progressGeometry);
  }

  void tianli_widget_super::processChange(int state)
  {
    setTimeLine(state);
  }

  void tianli_widget_super::onThreadFinish()
  {
    ui->pushButton_UI_Close->setHidden(false);
    activedWidget->setCurrentIndex(2);
  }

  void tianli_widget_super::onThreadThrowError(QString error)
  {
    this->activedWidget->setCurrentIndex(3);
    ui->pushButton_UI_Close->setHidden(false);
    this->errorInfoLabel->setText(error);
  }

  void tianli_widget_super::beginProcess()
  {
    ui->pushButton_UI_Close->setHidden(true);
    QString installPath = this->pathLineEdit->text();
    bool desktopShortcut = this->desktopCheckBox->isChecked();
    bool startMenuShortcut = this->startmenuCheckBox->isChecked();

    emit this->setInstallConfig(installPath, desktopShortcut, startMenuShortcut);
    thread->start();
  }
}