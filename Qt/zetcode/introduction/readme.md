### installation

```
sudo apt-get update
sudo apt-get install qt5-default
```

### run
to run an app there are 2 options:
- write the makefile with linkind and including Qt dependencies
- use qmake in 3 steps:
  - Step 1: create the project
  ```
  qmake -project
  ```
  - Step 2: configure the project
  - Step 3: crate the Makefile
  ```
  qmake
  ```

Sourcs: http://zetcode.com/gui/qt5/introduction/
