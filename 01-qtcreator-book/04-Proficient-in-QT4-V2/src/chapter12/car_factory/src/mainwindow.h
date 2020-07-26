
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDomDocument>
#include <QMainWindow>
#include <QModelIndex>

class QComboBox;
class QFile;
class QGroupBox;
class QLabel;
class QListWidget;
class QSqlRelationalTableModel;
class QSqlTableModel;
class QTableView;
class QListView;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &factoryTable, const QString &carTable,
               QFile *carDetails, QWidget *parent = 0);

private slots:
    void addCar();
    void changeFactory(QModelIndex index);
    void delCar();
    void showCarDetails(QModelIndex index);
    void showFactorytProfile(QModelIndex index);

private:
    QGroupBox *createCarGroupBox();
    QGroupBox *createFactoryGroupBox();
    QGroupBox *createDetailsGroupBox();
    void createMenuBar();
    void decreaseCarCount(QModelIndex index);
    void getAttribList(QDomNode car);
    QModelIndex indexOfFactory(const QString &factory);
    void readCarData();
    void removeCarFromDatabase(QModelIndex index);
    void removeCarFromFile(int id);

    QTableView *carView;
    QTableView *factoryView;
     
    QListWidget *attribList;

    QLabel *profileLabel;
    QLabel *titleLabel;

    QDomDocument carData;
    QFile *file;
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;
};

#endif
