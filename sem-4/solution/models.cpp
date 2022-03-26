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
  for (int i = 1; i <= 6; i++) {
    GetWords(i);
  }
}

void HashModel::GetWords(size_t id) {
  QSet<QString> current_words;
  QString name = ":dictionaries/" + GetAvailableDictionaries()[id] + ".txt";
  QFile file(name);
  file.open(QFile::ReadOnly);
  QString word;
  while (!file.atEnd()) {
    word = QString::fromUtf8(file.readLine());
    current_words.insert(word.toLower());
  }
  words_.push_back(std::move(current_words));
}
