# Qt Materials
Materials for my seminars. C++, Qt, fun (a little bit).

## Contents

#### lectures
- `mainwindow-demo`: creating a simple window in Qt
- `widgets-demo`: widget examples, signals/slots and event example
- `layouts-demo`: layout management
- `timers-demo`: different Qt timers
- `painter-demo`: animation, QPainter, QGraphicsScene
- `menu-and-dialogs-demo`: can you guess what's in this demo? :D
- `mvp-demo`: Model-View-Presenter example

#### sem-1
- Writing a simple JSON Parser
- Topics: C++ inheritance (virtual functions, abstract classes, dynamic cast, etc).

#### sem-2
- Small funny Qt tasks like a clicker or a run-away button
- Topics: Qt basics, widgets, signals/slots, event handling

## How to work here?
- On seminar:
  1. Clone the repo.
  2. Solve tasks from `statement` folder in `solution` folder.
  3. Commit task solutions to branch `sem-X-solution`.
  4. After seminar, I'll merge `sem-X-solution` into `main`.
- On your own:
  1. Clone or fork the repo.
  2. Create folder for your solutions, e. g. `my-solution`.
  3. Solve tasks from `statement` folder in `my-solution` folder.
  4. Check `CMakeLists.txt` for instructions on how to build the project with the solution folder changed (usually there will just be an environment variable you need to set, e. g. `SOLUTION_DIR`)
  5. Refer to `solution` folder if you encounter problems when solving the tasks.
  6. Don't push your solution to this repo :)
  7. If you want to contribute (fix the solution or add a missed test case), open a pull request.
