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

void TrieModel::LoadDictionary(
    const std::pair<size_t, QString>& dictionary_info) {
  QFile file(":dictionaries/" + dictionary_info.second + ".txt");
  file.open(QFile::ReadOnly);
  while (!file.atEnd()) {
    AddWord(QString::fromUtf8(file.readLine().toLower()),
            dictionary_info.first);
  }
  file.close();
}

void TrieModel::AddWord(const QString& word, size_t dictionary_index) {
  TrieNode* cur_node = root_;
  for (auto character : word) {
    auto& next = cur_node->next;
    auto it = next.find(character);
    if (it != next.end()) {
      cur_node = it->second;
    } else {
      next[character] = new TrieNode(character);
      cur_node = next[character];
    }
  }
  cur_node->dictionaries.push_back(dictionary_index);
}

TrieModel::TrieModel() : root_(new TrieNode()) {
  for (auto& entry : GetAvailableDictionaries()) {
    LoadDictionary(entry);
  }
}
void TrieModel::SetActiveDictionaries(
    const std::vector<size_t>& active_dictionary_ids) {
  active_dictionaries_ = active_dictionary_ids;
}

bool TrieModel::FindWordInDictionaries(const QString& word) {
  TrieNode* cur_node = root_;
  for (auto character : word) {
    auto& next = cur_node->next;
    auto it = next.find(character);
    if (it == next.end()) {
      return false;
    }
    cur_node = it->second;
  }
  auto& cur_dicts = cur_node->dictionaries;
  return std::ranges::any_of(cur_dicts.begin(),
                             cur_dicts.end(),
                             [&](size_t cur_dict_index) {
                               if (std::find(active_dictionaries_.begin(),
                                             active_dictionaries_.end(),
                                             cur_dict_index)
                                   != active_dictionaries_.end()) {
                                 return true;
                               }
                               return false;
                             });
}

TrieModel::TrieNode::TrieNode(QChar value) : value(value) {}
