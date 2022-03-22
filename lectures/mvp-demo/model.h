#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <QString>

class Model {
 public:
  const QString& Element(size_t i) const { return queue_[i]; }
  const size_t Size() const { return queue_.size(); }
  
  void Pop() {
    if (!queue_.empty()) {
      queue_.erase(queue_.begin());
    }
  }
  void Push(const QString& item) { queue_.push_back(item); }
 private:
  std::vector<QString> queue_;
};

#endif // MODEL_H
