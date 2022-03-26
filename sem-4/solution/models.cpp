#include <fstream>
#include <QFile>
#include "models.h"

void HashModel::SetActiveDictionaries(
    const std::vector<size_t>& active_dictionary_ids) {
  active_dictionaries_ = active_dictionary_ids;
}

bool HashModel::FindWordInDictionaries(const QString& word) {
  for (size_t id : active_dictionaries_) {
    if (words_[id].contains(word)) {
      return true;
    }
  }
  return false;
}

HashModel::HashModel() {
  for (auto& entry : GetAvailableDictionaries()) {
    LoadDictionary(entry.second);
  }
}

void HashModel::LoadDictionary(const QString& dictionary_name) {
  QFile file(":dictionaries/" + dictionary_name + ".txt");
  file.open(QFile::ReadOnly);
  QSet<QString> current_words;
  while (!file.atEnd()) {
    current_words.insert(QString::fromUtf8(file.readLine().toLower()));
  }
  file.close();
  words_.push_back(std::move(current_words));
}
