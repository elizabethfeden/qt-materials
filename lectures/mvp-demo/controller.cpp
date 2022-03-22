#include "controller.h"

Controller::Controller() : view_(std::make_unique<MainWindow>(this)),
                           model_(std::make_unique<Model>()) {
  view_->show();
}

void Controller::AddItem() {
  model_->Push(view_->GetOptions()->currentText());
  RefreshView();
}

void Controller::RemoveItem() {
  model_->Pop();
  RefreshView();
}

void Controller::RefreshView() {
  view_->GetList()->clear();
  for (size_t i = 0; i < model_->Size(); i++) {
    view_->GetList()->addItem(model_->Element(i));
  }
}
