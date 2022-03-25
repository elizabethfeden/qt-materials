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
  virtual std::unordered_map<size_t, QString>
      GetAvailableDictionaries() const { return kDictionaryNames_; }
  virtual void SetActiveDictionaries(
      const std::vector<size_t>& active_dictionary_ids) = 0;
  virtual bool FindWordInDictionaries(const QString& word) = 0;

 private:
  const std::unordered_map<size_t, QString> kDictionaryNames_ = {
      {1, "english"},
      {2, "russian"},
      {3, "adjectives"},
      {4, "adverbs"},
      {5, "nouns"},
      {6, "verbs"}
  };
};

#endif // ABSTRACT_MODEL_H
