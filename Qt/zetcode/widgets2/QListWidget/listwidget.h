#pragma once

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QtWidgets/QListWidget>

class ListWidget : public QWidget {
    
  Q_OBJECT

  public:
    ListWidget(QWidget *parent = 0);

  private slots:
    void addItem();
    void renameItem();
    void removeItem();
    void clearItems();

  private:
    QListWidget *lw;
    QPushButton *add;
    QPushButton *rename;
    QPushButton *remove;
    QPushButton *removeAll; 
};