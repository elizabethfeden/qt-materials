#include "views.h"
#include <iostream>
#include <string>
#include <QHBoxLayout>
#include <QFileDialog>

ConsoleView::ConsoleView(std::unique_ptr<Controller> controller) :
    AbstractView(std::move(controller)) {}

bool ConsoleView::ParseCommand(const std::string& command) {
  // TODO: Understand what to do here :)
  if (command == "#text") {
    GetText();
  }
  if (command == "#load") {
    OnLoadCommand();
  }
  if (command == "#analyse") {
    OnAnalyzeCommand();
  }
  if (command == "#change_ids") {
    OnActiveDictionariesChange();
  }
  if (command == "#exit") {
    return false;
  }
  return true;
}

QString ConsoleView::GetFilenameToLoad() {
  // TODO: Ask user what filename they need
  std::cout << "enter filename\n";
  std::string filename;
  std::cin >> filename;
  return QString::fromStdString(filename);
}

void ConsoleView::SetText(const QString& text) {
  text_ = text;
  // TODO: Show new text to user
  std::cout << text.toStdString();
}

QString ConsoleView::GetText() {
  return text_;
}

std::vector<size_t> ConsoleView::GetActiveDictionaryIds() {
  // TODO: Ask user what ids they want changed
  std::cout << "enter ids from: ";
  for (auto& id : controller_->GetAvailableDictionaries()) {
    std::cout << "(" << id.first << ", " << id.second.toStdString() << ")\n";
  }
  std::vector<size_t> result;
  size_t current_id;
  while (std::cin >> current_id) {
    result.push_back(current_id);
  }
  return result;
}

void ConsoleView::ShowResults(const std::vector<QString>& results) {
  for (auto &string : results) {
    std::cout << string.toStdString() << '\n';
  }
}

QString WindowView::GetFilenameToLoad() {
  auto name = QFileDialog::getOpenFileName(this, "choose file", "", "*.txt");
  return name;
}

void WindowView::SetText(const QString& text) {
  text_->setText(text);
}

QString WindowView::GetText() {
  return text_->toPlainText();
}

std::vector<size_t> WindowView::GetActiveDictionaryIds() {
  return std::vector<size_t>();
}

void WindowView::ShowResults(const std::vector<QString>& results) {
  QString result;
  for (auto& string : results) {
    result += string + '\n';
  }
  results_->setText(result);
}

WindowView::WindowView(std::unique_ptr<Controller> controller)
    : AbstractView(std::move(controller)),
    central_widget_(new QWidget(this)),
    load_(new QPushButton("Load", central_widget_)),
    analyze_(new QPushButton("Analyze", central_widget_)),
    text_(new QTextEdit(central_widget_)),
    results_(new QLabel(central_widget_)) {
  QHBoxLayout* layout = new QHBoxLayout();
  central_widget_->setLayout(layout);
  setCentralWidget(central_widget_);
  layout->addWidget(load_);
  layout->addWidget(analyze_);
  layout->addWidget(text_);
  layout->addWidget(results_);

  connect(load_, &QPushButton::pressed, this, &WindowView::OnLoadCommand);
  connect(analyze_, &QPushButton::pressed, this, &WindowView::OnAnalyzeCommand);
}
