#ifndef ABSTRACT_MODEL_H
#define ABSTRACT_MODEL_H

/*
 * Model's available dictionaries list is constant. The dictionaries are stored
 * in app's resources. Every dictionary has id and name; every dictionary file
 * has list of words in it, separated by newline.
 * User may choose to make certain dictionaries inactive. The FindWord method
 * should only check if a word is present in active dictionaries.
 */

class AbstractModel {
 public:
  std::unordered_map<size_t, QString>
      GetAvailableDictionaries() const { return kDictionaryNames_; }
  virtual void SetActiveDictionaries(
      const std::vector<size_t>& active_dictionary_ids) = 0;
  virtual bool FindWordInDictionaries(const QString& word) = 0;

 private:
  const std::unordered_map<size_t, QString> kDictionaryNames_ = {
      {0, "english"},
      {1, "russian"},
      {2, "adjectives"},
      {3, "adverbs"},
      {4, "nouns"},
      {5, "verbs"}
  };
};

#endif  // ABSTRACT_MODEL_H
