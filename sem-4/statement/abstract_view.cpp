#include "abstract_view.h"

void AbstractView::OnLoadCommand() {
  SetText(controller_->LoadText(GetFilenameToLoad()));
}

void AbstractView::OnAnalyzeCommand() {
  ShowResults(controller_->Analyze(GetText()));
}

void AbstractView::OnActiveDictionariesChange() {
  controller_->SetActiveDictionaries(GetActiveDictionaryIds());
}

AbstractView::AbstractView(std::unique_ptr<Controller> controller)
    : controller_(std::move(controller)) {}
