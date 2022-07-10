#include "main_window.h"

#include <random>

std::vector<QString> MainWindow::difficult_words_ = {
    "procrastination",
    "wednesday",
    "cheque",
    "architecture",
    "thistle",
    "geography",
    "illegitimate",
    "invulnerability",
    "performance",
    "exaggerate",
    "accommodation",
    "millennium",
    "breakthrough",
    "ticketinspector",
    "quicksand",
    "dragonfly"
};

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    word_("!"),
    human_widget_(new PaintHuman(this)),
    word_widget_(new PaintWord(this, word_)),
    letter_(new QLineEdit(this)),
    used_letters_(new QLabel("Used letters:\n", this)),
    left_attempts_(new QLabel(this)),
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)),
    try_again_(new QPushButton("Play again!", this)) {
  std::shuffle(difficult_words_.begin(), difficult_words_.end(), std::mt19937(std::random_device()()));
  word_ = difficult_words_[current_word_ % difficult_words_.size()];
  word_widget_->SetWord(word_);

  setMinimumSize(700, 550);
  word_widget_->setGeometry(10, 30, 300, 70);
  letter_->setGeometry(320, 10, 200, 20);
  human_widget_->setGeometry(10, 180, 300, 300);
  used_letters_->setGeometry(320, 50, 200, 50);
  left_attempts_->setGeometry(350, 130, 200, 50);
  left_attempts_->setText("Wrong attempts left: " + QString::number(attempts_));
  try_again_->setGeometry(600, 500, 100, 50);
  view_->setVisible(false);

  letter_->setMaxLength(1);

  ConnectWidgets();
}

void MainWindow::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  human_widget_->Paint(&painter, attempts_);
  bool is_winner = word_widget_->Paint(&painter, entered_letters_);
  if (is_winner) {
    SetupSceneWinner();
  }
}

void MainWindow::ConnectWidgets() {
  connect(letter_, &QLineEdit::returnPressed, this, [&] {
    if (letter_->text() == "") return;
    if (std::find(entered_letters_.begin(),
                  entered_letters_.end(),
                  letter_->text()[0]) != entered_letters_.end()) {
      letter_->clear();
      return;
    }
    entered_letters_.push_back(letter_->text()[0]);
    auto it = std::find(word_.begin(), word_.end(), letter_->text());
    if (it == word_.end()) {
      --attempts_;
      if (attempts_ == -1) {
        SetupSceneLooser();
      }
      left_attempts_->setText("Wrong attempts left: " + QString::number(attempts_));
    }
    repaint();
    used_letters_->setText(
        used_letters_->text() + "  " + entered_letters_.back());
    letter_->clear();
  });

  connect(try_again_, &QPushButton::clicked, this, [&]{
    ++current_word_;
    word_ = difficult_words_[current_word_ % difficult_words_.size()];
    word_widget_->SetWord(word_);
    Reset();
  });
}

void MainWindow::SetupSceneWinner() {
  scene_->addPixmap(QPixmap(":winner.jpg"));
  view_->setScene(scene_);
  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->resize(700, 550);
  view_->setVisible(true);
  try_again_->setGeometry(600, 500, 100, 50);
}

void MainWindow::SetupSceneLooser() {
  scene_->addPixmap(QPixmap(":looser.jpg"));
  view_->setScene(scene_);
  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->resize(700, 550);
  view_->setVisible(true);
  try_again_->setGeometry(600, 500, 100, 50);
}

void MainWindow::Reset() {
  entered_letters_ = {' '};
  used_letters_->setText("Used letters:\n");
  attempts_ = 5;
  left_attempts_->setText("Wrong attempts left: " + QString::number(attempts_));
  scene_->clear();
  view_->setVisible(false);
  repaint();
}
