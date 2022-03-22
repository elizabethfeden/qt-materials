#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "abstract_controller.h"
#include "main_window.h"
#include "model.h"

class Controller : public AbstractController {
 public:
  Controller();
  void AddItem() override;
  void RemoveItem() override;

 private:
  void RefreshView();

 private:
  std::unique_ptr<MainWindow> view_;
  std::unique_ptr<Model> model_;
};


#endif // CONTROLLER_H
