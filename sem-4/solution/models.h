#ifndef MODELS_H
#define MODELS_H

#include "abstract_model.h"
#include <vector>
#include <QString>
#include <QSet>

// -- TASK --
// Implement the models. HashModel should store words entries in an
// unordered set or map. TrieModel should implement search of words entries
// with the Trie data structure.

class HashModel : public AbstractModel {
 public:
  HashModel();
  void SetActiveDictionaries(
      const std::vector<size_t>& active_dictionary_ids) override;
  bool FindWordInDictionaries(const QString& word) override;

 private:
  void LoadDictionary(const QString& dictionary_name);

  std::vector<size_t> active_dictionaries_;
  std::vector<QSet<QString>> words_;
};

class TrieModel : public AbstractModel {
 public:
  TrieModel();
  void SetActiveDictionaries(
      const std::vector<size_t>& active_dictionary_ids) override;
  bool FindWordInDictionaries(const QString& word) override;

 private:
  void LoadDictionary(const std::pair<size_t, QString>& dictionary_info);
  void AddWord(const QString& word, size_t dictionary_index);
  std::vector<size_t> active_dictionaries_;

  struct TrieNode {
    TrieNode() = default;
    explicit TrieNode(QChar value);

    std::map<QChar, TrieNode*> next;
    QChar value;
    std::vector<size_t> dictionaries;
  };

  TrieNode* root_;
};

#endif // MODELS_H
