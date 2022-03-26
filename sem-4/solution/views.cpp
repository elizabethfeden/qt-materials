#include "views.h"
#include <iostream>
#include <string>

ConsoleView::ConsoleView(std::unique_ptr<Controller> controller) :
    AbstractView(std::move(controller)) {}

bool ConsoleView::ParseCommand(const std::string& command) {
  if (command == "#text") {
    GetText();
    return true;
  }
  if (command.starts_with("#load_filename")) {
    filename_ = command.substr(15, command.size() - 15).data();
    controller_->LoadText(filename_);
    OnLoadCommand();
    return true;
  }
  if (command.starts_with("#change_dictionaries")) {
    auto it = command.begin() + 20;
    while (it != command.end()) {
      ++it;
      auto space_it = std::find(it, command.end(), ' ');
      std::string number = command.substr(it - command.begin(), space_it - it);
      dictionary_ids_.push_back(std::stoll(number));
      it = space_it;
    }
    OnActiveDictionariesChange();
    return true;
  }
  if (command == "#results") {
    ShowResults(controller_->Analyze(text_));
    return true;
  }
  if (command == "#exit") {
    return false;
  }
  return false;
}

QString ConsoleView::GetFilenameToLoad() {
  return filename_;
}

void ConsoleView::SetText(const QString& text) {
  text_ = text;
}

QString ConsoleView::GetText() {
  return text_;
}

std::vector<size_t> ConsoleView::GetActiveDictionaryIds() {
  return dictionary_ids_;
}

void ConsoleView::ShowResults(const std::vector<QString>& results) {
  for (auto &string : results) {
    std::cout << string.data() << '\n';
  }
}
