#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QCoreApplication::setApplicationName("Geobebra");

  MainWindow window;
  window.show();

  return QApplication::exec();
}
