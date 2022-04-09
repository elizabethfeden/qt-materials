#include "main_window.h"

MainWindow::MainWindow(QSettings* settings)
    : settings_(settings) {
  setFixedSize(700, 300);
  setCentralWidget(main_widget_ = new QWidget);
  main_widget_->setLayout(layout_ = new QVBoxLayout);
  layout_->addWidget(text_ = new QLabel(QLabel::tr("Cake is a lie")));
  layout_->addWidget(text2_ = new QLabel(QLabel::tr("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.")));
  text2_->setWordWrap(true);
  layout_->addWidget(button_ = new QPushButton(QPushButton::tr("Press me")));
  layout_->addWidget(button2_ = new QPushButton(QPushButton::tr("Do not press me...")));
  setMenuBar(menu_bar_ = new QMenuBar);
  auto lang_menu = new QMenu("Language");
  menu_bar_->addMenu(lang_menu);
  lang_menu->addAction(deutsch_lang_ = new QAction("Deutsch"));
  lang_menu->addAction(belarusian_lang_ = new QAction("Belarusian"));
  lang_menu->addAction(english_lang_ = new QAction("English"));
  settings_ = new QSettings("ACorparation", "sem8");

  connect(deutsch_lang_, &QAction::triggered, this, [&] {
    settings_->setValue("language", "de");
  });
  connect(belarusian_lang_, &QAction::triggered, this, [&] {
    settings_->setValue("language", "by");
  });
  connect(english_lang_, &QAction::triggered, this, [&] {
    settings_->setValue("language", "en");
  });

  show();
}
