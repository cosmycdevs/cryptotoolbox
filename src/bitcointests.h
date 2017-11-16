#ifndef BITCOINTESTS_H
#define BITCOINTESTS_H

#include <QMainWindow>
#include <QDebug>
#include <QCryptographicHash>
#include <QMessageBox>
#include "helper.h"

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
    void runCommand(QString);
    void updatePoB();
    void updatePrivChkSum();
    void updateWIF2PrivateKey();
    void updateBrainwallet();

private slots:
    void buttonsClicked();
    void slotHashTypeChange(QString);

};

#endif // BITCOINTESTS_H
