#include <iostream>

#include <QApplication>
#include <QTranslator>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QTranslator translator;

  // Попытка загрузить необходимый ресурс. Всегда следует проверять,
  // удалась ли загрузка, при необходимости загружая то, что загрузить
  // точно получится, или выбрасывая ошибку. Вы можете забыть подключить файл
  // ресурсов, системная локаль может быть очень странной, в общем, может
  // возникнуть множество различных проблем.
  if (!translator.load(QLocale(), "linguist", "_", ":/translations")) {
    std::clog << QLocale().name().toStdString() << " locale not found"
              << std::endl;
    if (!translator.load(":/translations/linguist_en_US")) {
      std::clog << "Default en_US locale not found, exiting..." << std::endl;
      return 1;
    }
  }

  // Установка текущего ресурса (языка) в качестве языка приложения. Должна
  // производиться до создания каких-либо виджетов.
  QApplication::installTranslator(&translator);
  
  // Перевод дефолтных вещей интерфейса типа кнопок в диалогах
  QTranslator base_translator;
  if (base_translator.load(
      "qtbase_" + language,
      QLibraryInfo::location(QLibraryInfo::TranslationsPath))) {
    QApplication::installTranslator(&base_translator);
  }

  MainWindow w;
  w.show();

  return QApplication::exec();
}
