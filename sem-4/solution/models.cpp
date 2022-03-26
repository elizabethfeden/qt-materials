#include "models.h"
void HashModel::SetActiveDictionaries(const std::vector<size_t>& active_dictionary_ids) {
  dictionaries_ = active_dictionary_ids;
}
bool HashModel::FindWordInDictionaries(const QString& word) {

}
HashModel::HashModel() {
  std::vector<size_t>& active_dicts;
}
void HashModel::GetWords(const QString& name) {
  QSet<QString> current_words;

  words_.push_back(std::move(current_words));
}
