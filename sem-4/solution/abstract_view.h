#ifndef ABSTRACT_VIEW_H
#define ABSTRACT_VIEW_H

#include <vector>
#include <unordered_map>

#include <QString>

#include "controller.h"

/*
 * Enables user to give the following commands: load text, analyze text,
 * change active dictionaries. Shows the information about user's actions
 * and their results, e.g. the text they loaded.
 */

class AbstractView {
 public:
  explicit AbstractView(std::unique_ptr<Controller> controller);

  void OnLoadCommand();
  void OnAnalyzeCommand();
  void OnActiveDictionariesChange();

  virtual QString GetFilenameToLoad() = 0;
  virtual void SetText(const QString& text) = 0;
  virtual QString GetText() = 0;
  virtual std::vector<size_t> GetActiveDictionaryIds() = 0;
  virtual void ShowResults(const std::vector<QString>& results) = 0;

 protected:
  std::unique_ptr<Controller> controller_;
};


#endif  // ABSTRACT_VIEW_H
