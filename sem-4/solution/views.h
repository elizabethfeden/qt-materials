#ifndef VIEWS_H
#define VIEWS_H

#include <string>
#include <QMainWindow>

#include "abstract_view.h"

// -- TASK --
// Implement the views.

class ConsoleView : public AbstractView {
 public:
  explicit ConsoleView(std::unique_ptr<Controller> controller);

  // Returns false if command is '#exit'.
  bool ParseCommand(const std::string& command);

  QString GetFilenameToLoad() override;
  void SetText(const QString& text) override;
  QString GetText() override;
  std::vector<size_t> GetActiveDictionaryIds() override;
  void ShowResults(const std::vector<QString>& results) override;

 private:
  QString text_;
  QString filename_;
  std::vector<size_t> dictionary_ids_;
};

class WindowView : public AbstractView, public QMainWindow {

};


#endif // VIEWS_H
