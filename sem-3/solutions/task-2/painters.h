#ifndef PAINTERS_H
#define PAINTERS_H

#include <QPainter>
#include <QLineEdit>
#include <QWidget>

class PaintWidget : public QWidget {
  Q_OBJECT
 public:
  PaintWidget(QWidget* parent);
};

class PaintHuman : public PaintWidget {
 public:
  PaintHuman(QWidget* parent);
  void Paint(QPainter* painter, int detail);
};

class PaintWord : public PaintWidget {
 public:
  PaintWord(QWidget* parent, const QString& word);
  bool Paint(QPainter* painter, const std::vector<QChar>& letters);
  void SetWord(const QString& word);

 private:
  QString word_;
};

#endif //PAINTERS_H
