#ifndef VIEWS_H
#define VIEWS_H

#include <string>
#include <QMainWindow>

#include "abstract_view.h"

// -- TASK --
// Implement the views.

class ConsoleView : public AbstractView {
  // Returns false if command is '#exit'.
  bool ParseCommand(const std::string& command);
};

class WindowView : public AbstractView, public QMainWindow {

};


#endif // VIEWS_H
