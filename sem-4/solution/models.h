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
  void GetWords(size_t id);

  std::vector<size_t> active_dictionaries_;
  std::vector<QSet<QString>> words_;
};

class TrieModel : public AbstractModel {

};

#endif // MODELS_H
