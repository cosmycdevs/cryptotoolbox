#ifndef BITCOINTESTS_H
#define BITCOINTESTS_H

#include <QMainWindow>
#include <QDebug>
#include <QCryptographicHash>
#include <QMessageBox>
#include "helper.h"
#include "base58.h"
#include <iostream>

namespace Ui {
class BitcoinTests;
}

class BitcoinTests : public QMainWindow
{
    Q_OBJECT

public:
    explicit BitcoinTests(QWidget *parent = 0);
    ~BitcoinTests();

    void init(QString version);

private:
    Ui::BitcoinTests *ui;

    void updatePrivECDSAKey();
    void updateWIF();

private slots:
    void buttonsClicked();

};

#endif // BITCOINTESTS_H
