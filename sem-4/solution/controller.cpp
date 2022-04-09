#include <QFile>
#include "controller.h"
#include <QRegularExpression>
#include <queue>

Controller::Controller(std::unique_ptr<AbstractModel> model) : model_(std::move(model)) {}

std::vector<QString> Controller::Analyze(const QString& text, int top) {
  static const QRegularExpression word("[^a-zа-я']+");
  QHash<QString, int> dict;
  for (const auto& string : text.toLower().split(word)) {
    if (dict.contains(string) ||
        model_->FindWordInDictionaries(string)) {
      dict[string]++;
    }
  }
  std::vector<std::pair<int, QString>> pairs;
  for (auto it = dict.begin(); it != dict.end(); ++it) {
    pairs.emplace_back(it.value(), it.key());
  }
  std::priority_queue<std::pair<int, QString>>
      heap(pairs.begin(), pairs.end());
  std::vector<QString> result;
  result.reserve(top);
  for (int i = 0; i < std::min(static_cast<size_t>(top), pairs.size()); ++i) {
    result.push_back(heap.top().second);
    heap.pop();
  }
  return result;
}

void Controller::SetActiveDictionaries(
    const std::vector<size_t>& active_dictionary_ids) {
  model_->SetActiveDictionaries(active_dictionary_ids);
}

QString Controller::LoadText(const QString& filename) {
  QFile input(filename);
  input.open(QFile::ReadOnly);
  QString text = QString::fromUtf8(input.readAll());
  input.close();
  return text;
}

std::unordered_map<size_t, QString>
Controller::GetAvailableDictionaries() const {
  return model_->GetAvailableDictionaries();
}
