#include "controller.h"

Controller::Controller(std::unique_ptr<AbstractModel> model) : model_(std::move(model)) {}

std::vector<QString> Controller::Analyze(const QString& text, int top) {
  // -- TASK --
  // * Count words in text
  // * Create results containing top words by count. Words should be present
  // in model_'s active dictionaries.

  return your_results;
}

void Controller::SetActiveDictionaries(
    const std::vector<size_t>& active_dictionary_ids) {
  model_->SetActiveDictionaries(active_dictionary_ids);
}

QString Controller::LoadText(const QString& filename) {
  // -- TASK --
  // Load text from file (in UTF-8 encoding)

  return text;
}
