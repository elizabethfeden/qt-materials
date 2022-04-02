#include <iostream>

#include <QApplication>

#include "controller.h"
#include "models.h"
#include "views.h"

enum class ModelOption {
  kHash,
  kTrie,
};

std::unique_ptr<AbstractModel> GetModel(const ModelOption& option) {
  if (option == ModelOption::kHash) {
    return std::make_unique<HashModel>();
  } else {
  //  return std::make_unique<TrieModel>();
  }
}

int RunWindow(const ModelOption& option, int argc, char* argv[]) {
  QApplication app(argc, argv);
  WindowView view(std::make_unique<Controller>(GetModel(option)));
  view.show();
  return QApplication::exec();
}

int RunConsole(const ModelOption& option) {
  ConsoleView view(std::make_unique<Controller>(GetModel(option)));
  std::string command;
  do {
    std::cin >> command;
  } while (view.ParseCommand(command));
  return 0;
}

int main(int argc, char* argv[]) {
  return RunWindow(ModelOption::kHash, argc, argv);
//  return RunWindow(ModelOption::kTrie, argc, argv);
//  return RunConsole(ModelOption::kHash);
//  return RunConsole(ModelOption::kTrie);
}
