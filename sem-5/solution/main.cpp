#include <QApplication>
#include <QLibraryInfo>
#include <QTranslator>
#include <iostream>
#include <QSettings>

#include "main_window.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  auto* settings_ = new QSettings("ACorparation", "sem8");
  if (!settings_->contains("language")) {
    settings_->setValue("language", "en");
  }

  QTranslator translator;
  if (!translator.load(QLocale(settings_->value("language").toString()), "", "", ":/translations")) {
    std::clog << QLocale().name().toStdString() << " locale not found"
              << std::endl;
    if (!translator.load(":/translations/en")) {
      std::clog << "Default en_US locale not found, exiting..." << std::endl;
      return 1;
    }
  }
  QApplication::installTranslator(&translator);

  QTranslator base_translator;
  if (base_translator.load(
      "qtbase_" + settings_->value("language").toString(),
      QLibraryInfo::location(QLibraryInfo::TranslationsPath))) {
    QApplication::installTranslator(&base_translator);
  }

  MainWindow window(settings_);
  return QApplication::exec();
}
