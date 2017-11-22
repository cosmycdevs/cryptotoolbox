#ifndef BITCOINTESTS_H
#define BITCOINTESTS_H

#include <QMainWindow>
#include <QDebug>
#include <QCryptographicHash>
#include <QMessageBox>
#include "helper.h"

#define ADDRESS_TEST_ECDSA_PRIVATE_KEY  "18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725"
#define ADDRESS_TEST_ECDSA_PUBLIC_KEY   "0450863AD64A87AE8A2FE83C1AF1A8403CB53F53E486D8511DAD8A04887E5B23522CD470243453A299FA9E77237716103ABC11A1DF38855ED6F2EE187E9C582BA6"

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

    void updateAddressTest(bool GenerateNewKeys = false);
    void calcAddressTestFast();

    void randAllVanityTest();
    void updateAllVanityTest();

private slots:
    void buttonsClicked();
    void slotHashTypeChange(QString);

};

#endif // BITCOINTESTS_H
