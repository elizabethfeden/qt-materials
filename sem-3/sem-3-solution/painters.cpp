#include "painters.h"

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent) {}

PaintHuman::PaintHuman(QWidget* parent) : PaintWidget(parent) {}

void PaintHuman::Paint(QPainter* painter, int detail) {
  painter->save();

  QBrush brush(Qt::black);
  painter->setBrush(brush);
  switch (detail) {
    case 0:
      painter->drawLine(160, 180, 160, 250);
    case 1:
      painter->drawLine(310, 180, 310, 530);
    case 2:
      painter->drawLine(10, 180, 310, 180);
    case 3:
      painter->drawLine(10, 530, 10, 180);
    case 4:
      painter->drawEllipse(130, 250, 60, 60);
      painter->drawLine(160, 310, 160, 350);
      painter->drawLine(160, 350, 160, 430);
      painter->drawLine(160, 350, 120, 390);
      painter->drawLine(160, 350, 200, 390);
      painter->drawLine(160, 430, 120, 470);
      painter->drawLine(160, 430, 200, 470);
  }

  painter->restore();
}

PaintWord::PaintWord(QWidget* parent, const QString& word) :
    PaintWidget(parent),
    word_(word) {}

bool PaintWord::Paint(QPainter* painter, const std::vector<QChar>& letters) {
  QPen pen(Qt::black);
  painter->setPen(pen);
  QFont font = painter->font();
  font.setPixelSize(16);
  painter->setFont(font);
  bool are_all_letters_used = true;
  for (int i = 0; i < word_.size(); ++i) {
    painter->drawLine(20 * i + 15, 80, 20 * i + 30, 80);
    if (std::find(letters.begin(), letters.end(), word_[i]) == letters.end()) {
      are_all_letters_used = false;
      continue;
    }
    painter->drawText(20 * i + 17, 70, QString(word_[i]));
  }
  return are_all_letters_used;
}

void PaintWord::SetWord(const QString& word) {
  word_ = word;
}
