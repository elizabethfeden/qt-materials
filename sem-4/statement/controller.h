#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>
#include <unordered_map>

#include <QHash>
#include <QString>

#include "abstract_model.h"

/*
 * Handles the text analisys logic without worrying about
 * the results representation.
 */

class Controller {
 public:
  explicit Controller(std::unique_ptr<AbstractModel> model);
  void SetActiveDictionaries(const std::vector<size_t>& active_dictionary_ids);
  std::vector<QString> Analyze(const QString& text, int top = 10);
  QString LoadText(const QString& filename);

 private:
  std::unique_ptr<AbstractModel> model_;
};


#endif // CONTROLLER_H
