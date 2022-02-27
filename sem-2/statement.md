# Seminar 2 task

In pairs, choose one of simple applications to implement from below:

### 1. Running button

- Add QPushButton
- On hover of cursor, button should run away
- On click (i. e. you caught the button), it should change color
- The button shouldn't run behind the window borders

### 2. Clicking disaster

- On click, create a QLabel with a text "click" in the place of click
- On space key press, change all the labels text to "oops!" 

### 3. Visual controls

- Add five QCheckBoxes and five QPushButtons
- On a checkbox check, one associated button becomes invisible. On uncheck, it becomes visible, again
- Use a layout to position the buttons

### 4. Spawning widgets

- Add a QComboBox containing some widget names, e. g. "pushbutton" and "text edit"
- Add a QSpinBox with possible values from 0 to 5
- Add a QPushButton "Spawn!". On press, the widgets chosen in combobox should appear, in quantity chosen on QSpinBox 
- [Bonus] Use a layout

### 5. A clicker we deserve

- Add a QSpinBox with possible values from 0 to 100
- Add a QPushButton
- Add a QPogressBar
- On each button click, progress the bar. Total amount of clicks to 100% the bar should be equal to the value on QSpinBox
- One shouldn't be able to change QSpinBox value after first click on the button
- [Bonus] Use a layout

### 6. Careful positioning

- Add a vertical QSlider and a QPushButton next to it 
- When moving the slider, the button should also move in the same direction
- Add a horizontal QSlider and create the same effect. Now button should be moving in 2d.