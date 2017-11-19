/********************************************************************************
** Form generated from reading UI file 'bitcointests.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BITCOINTESTS_H
#define UI_BITCOINTESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BitcoinTests
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_Main;
    QWidget *tab_BitcoinAddressTests;
    QWidget *tab_PrivateKeyTests;
    QTabWidget *tabWidget_PrivateKeyTests;
    QWidget *tab_WIFToPrivKey;
    QWidget *tab_PrivKeyToWIF;
    QLineEdit *lineEdit_PrependVersion;
    QLineEdit *lineEdit_6;
    QLabel *label_First4BitesOf4;
    QPushButton *pushButton_CalculateWIF;
    QPushButton *pushButton_PraseToECDSAQt;
    QLineEdit *lineEdit_AfterBase58;
    QLabel *label_SHA256HashOf2;
    QLabel *label_PrivECDSAKey;
    QLineEdit *lineEdit_SHA256HashOf3;
    QLabel *label_Phrase;
    QLineEdit *lineEdit_SHA256HashOf2;
    QLabel *label_6;
    QLineEdit *lineEdit_PrivECDSAKey;
    QLabel *label_PrependVersion;
    QLineEdit *lineEdit_Phrase;
    QLineEdit *lineEdit_First4BitesOf4;
    QLabel *label_SHA256HashOf3;
    QLabel *label_7;
    QWidget *tab_WIFChecksumChecking;
    QWidget *tab_VanityTests;
    QTabWidget *tabWidget_VanityAddressTests;
    QWidget *tab_VanityAddresses;
    QWidget *tab_AllVanityAddressTests;
    QWidget *tab_VanitySumAddressTests;
    QLineEdit *lineEdit_VanitySumOfPrivKeys;
    QLabel *label_VanitySumOfPrivKeys;
    QLabel *label_VanityPrivECDSAKeys_S;
    QPushButton *pushButton_CalcSumOfPrivKeys;
    QLineEdit *lineEdit_VanityPrivECDSAKey2_S;
    QLineEdit *lineEdit_VanityPrivECDSAKey1_S;
    QLabel *label_VanityPublicECDSAKeys;
    QPushButton *pushButton_CalcSumOfPublicKeys;
    QLineEdit *lineEdit_VanityPublicECDSAKey2;
    QLineEdit *lineEdit_VanityPublicECDSAKey1;
    QWidget *tab_VanityMultiplyAddressTests;
    QLineEdit *lineEdit_VanityMultiplicationOfPrivKeys;
    QLabel *label_VanityPrivECDSAKeys_M;
    QPushButton *pushButton_CalcMultiplicationOfPrivKeys;
    QLabel *label_VanityMultiplicationOfPrivKeys;
    QLineEdit *lineEdit_VanityPrivECDSAKey2_M;
    QLineEdit *lineEdit_VanityPrivECDSAKey1_M;
    QWidget *tab_Brainwallet;
    QWidget *tab_ProfOfBurn;
    QWidget *tab_SHA256;
    QTabWidget *tabWidget_LibsTests;
    QWidget *tab_HashCalculator;
    QPushButton *pushButton_CalcStringHash;
    QTextEdit *textEdit_DataForHash;
    QLineEdit *lineEdit_HashResult;
    QPushButton *pushButton_DataForHashToLower;
    QPushButton *pushButton_DataForHashToUpper;
    QLabel *label_DataForHash;
    QLabel *label_HashResult;
    QComboBox *comboBox_HashType;
    QLabel *label_HashFunction;
    QPushButton *pushButton_HashToLower;
    QPushButton *pushButton_HashToUpper;
    QPushButton *pushButton_CalcHexHash;
    QWidget *tab_PublicECDSAKey;
    QLineEdit *lineEdit_PrivECDSAKeyTests;
    QLabel *label_PrivECDSAKeyTests;
    QPushButton *pushButton_CalcPublicECDSAKeyTests;
    QLabel *label_PublicECDSAKeyTestsUncompressed;
    QLineEdit *lineEdit_PublicECDSAKeyTestsUncompressed;
    QLineEdit *lineEdit_PublicECDSAKeyTestsCompressed;
    QLabel *label_PublicECDSAKeyTestsCompressed;
    QPushButton *pushButton_PublicKeyECDAKeyToUpper;
    QPushButton *pushButton_PublicKeyECDAKeyToLower;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BitcoinTests)
    {
        if (BitcoinTests->objectName().isEmpty())
            BitcoinTests->setObjectName(QStringLiteral("BitcoinTests"));
        BitcoinTests->resize(948, 417);
        centralWidget = new QWidget(BitcoinTests);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget_Main = new QTabWidget(centralWidget);
        tabWidget_Main->setObjectName(QStringLiteral("tabWidget_Main"));
        tabWidget_Main->setGeometry(QRect(10, 0, 931, 361));
        tab_BitcoinAddressTests = new QWidget();
        tab_BitcoinAddressTests->setObjectName(QStringLiteral("tab_BitcoinAddressTests"));
        tabWidget_Main->addTab(tab_BitcoinAddressTests, QString());
        tab_PrivateKeyTests = new QWidget();
        tab_PrivateKeyTests->setObjectName(QStringLiteral("tab_PrivateKeyTests"));
        tabWidget_PrivateKeyTests = new QTabWidget(tab_PrivateKeyTests);
        tabWidget_PrivateKeyTests->setObjectName(QStringLiteral("tabWidget_PrivateKeyTests"));
        tabWidget_PrivateKeyTests->setGeometry(QRect(10, 10, 911, 311));
        tab_WIFToPrivKey = new QWidget();
        tab_WIFToPrivKey->setObjectName(QStringLiteral("tab_WIFToPrivKey"));
        tabWidget_PrivateKeyTests->addTab(tab_WIFToPrivKey, QString());
        tab_PrivKeyToWIF = new QWidget();
        tab_PrivKeyToWIF->setObjectName(QStringLiteral("tab_PrivKeyToWIF"));
        lineEdit_PrependVersion = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_PrependVersion->setObjectName(QStringLiteral("lineEdit_PrependVersion"));
        lineEdit_PrependVersion->setGeometry(QRect(180, 100, 711, 20));
        lineEdit_6 = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(180, 220, 711, 20));
        label_First4BitesOf4 = new QLabel(tab_PrivKeyToWIF);
        label_First4BitesOf4->setObjectName(QStringLiteral("label_First4BitesOf4"));
        label_First4BitesOf4->setGeometry(QRect(10, 190, 161, 21));
        pushButton_CalculateWIF = new QPushButton(tab_PrivKeyToWIF);
        pushButton_CalculateWIF->setObjectName(QStringLiteral("pushButton_CalculateWIF"));
        pushButton_CalculateWIF->setGeometry(QRect(820, 70, 75, 23));
        pushButton_PraseToECDSAQt = new QPushButton(tab_PrivKeyToWIF);
        pushButton_PraseToECDSAQt->setObjectName(QStringLiteral("pushButton_PraseToECDSAQt"));
        pushButton_PraseToECDSAQt->setGeometry(QRect(730, 10, 161, 23));
        lineEdit_AfterBase58 = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_AfterBase58->setObjectName(QStringLiteral("lineEdit_AfterBase58"));
        lineEdit_AfterBase58->setGeometry(QRect(180, 250, 711, 20));
        label_SHA256HashOf2 = new QLabel(tab_PrivKeyToWIF);
        label_SHA256HashOf2->setObjectName(QStringLiteral("label_SHA256HashOf2"));
        label_SHA256HashOf2->setGeometry(QRect(10, 130, 161, 21));
        label_PrivECDSAKey = new QLabel(tab_PrivKeyToWIF);
        label_PrivECDSAKey->setObjectName(QStringLiteral("label_PrivECDSAKey"));
        label_PrivECDSAKey->setGeometry(QRect(10, 40, 151, 20));
        lineEdit_SHA256HashOf3 = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_SHA256HashOf3->setObjectName(QStringLiteral("lineEdit_SHA256HashOf3"));
        lineEdit_SHA256HashOf3->setGeometry(QRect(180, 160, 711, 20));
        label_Phrase = new QLabel(tab_PrivKeyToWIF);
        label_Phrase->setObjectName(QStringLiteral("label_Phrase"));
        label_Phrase->setGeometry(QRect(10, 10, 37, 20));
        lineEdit_SHA256HashOf2 = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_SHA256HashOf2->setObjectName(QStringLiteral("lineEdit_SHA256HashOf2"));
        lineEdit_SHA256HashOf2->setGeometry(QRect(180, 130, 711, 20));
        label_6 = new QLabel(tab_PrivKeyToWIF);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 220, 161, 21));
        lineEdit_PrivECDSAKey = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_PrivECDSAKey->setObjectName(QStringLiteral("lineEdit_PrivECDSAKey"));
        lineEdit_PrivECDSAKey->setGeometry(QRect(180, 40, 711, 20));
        label_PrependVersion = new QLabel(tab_PrivKeyToWIF);
        label_PrependVersion->setObjectName(QStringLiteral("label_PrependVersion"));
        label_PrependVersion->setGeometry(QRect(10, 100, 161, 21));
        lineEdit_Phrase = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_Phrase->setObjectName(QStringLiteral("lineEdit_Phrase"));
        lineEdit_Phrase->setGeometry(QRect(180, 10, 541, 20));
        lineEdit_First4BitesOf4 = new QLineEdit(tab_PrivKeyToWIF);
        lineEdit_First4BitesOf4->setObjectName(QStringLiteral("lineEdit_First4BitesOf4"));
        lineEdit_First4BitesOf4->setGeometry(QRect(180, 190, 141, 20));
        label_SHA256HashOf3 = new QLabel(tab_PrivKeyToWIF);
        label_SHA256HashOf3->setObjectName(QStringLiteral("label_SHA256HashOf3"));
        label_SHA256HashOf3->setGeometry(QRect(10, 160, 161, 21));
        label_7 = new QLabel(tab_PrivKeyToWIF);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 250, 161, 21));
        tabWidget_PrivateKeyTests->addTab(tab_PrivKeyToWIF, QString());
        tab_WIFChecksumChecking = new QWidget();
        tab_WIFChecksumChecking->setObjectName(QStringLiteral("tab_WIFChecksumChecking"));
        tabWidget_PrivateKeyTests->addTab(tab_WIFChecksumChecking, QString());
        tabWidget_Main->addTab(tab_PrivateKeyTests, QString());
        tab_VanityTests = new QWidget();
        tab_VanityTests->setObjectName(QStringLiteral("tab_VanityTests"));
        tabWidget_VanityAddressTests = new QTabWidget(tab_VanityTests);
        tabWidget_VanityAddressTests->setObjectName(QStringLiteral("tabWidget_VanityAddressTests"));
        tabWidget_VanityAddressTests->setGeometry(QRect(10, 10, 911, 321));
        tab_VanityAddresses = new QWidget();
        tab_VanityAddresses->setObjectName(QStringLiteral("tab_VanityAddresses"));
        tabWidget_VanityAddressTests->addTab(tab_VanityAddresses, QString());
        tab_AllVanityAddressTests = new QWidget();
        tab_AllVanityAddressTests->setObjectName(QStringLiteral("tab_AllVanityAddressTests"));
        tabWidget_VanityAddressTests->addTab(tab_AllVanityAddressTests, QString());
        tab_VanitySumAddressTests = new QWidget();
        tab_VanitySumAddressTests->setObjectName(QStringLiteral("tab_VanitySumAddressTests"));
        lineEdit_VanitySumOfPrivKeys = new QLineEdit(tab_VanitySumAddressTests);
        lineEdit_VanitySumOfPrivKeys->setObjectName(QStringLiteral("lineEdit_VanitySumOfPrivKeys"));
        lineEdit_VanitySumOfPrivKeys->setGeometry(QRect(10, 210, 881, 20));
        label_VanitySumOfPrivKeys = new QLabel(tab_VanitySumAddressTests);
        label_VanitySumOfPrivKeys->setObjectName(QStringLiteral("label_VanitySumOfPrivKeys"));
        label_VanitySumOfPrivKeys->setGeometry(QRect(10, 190, 111, 20));
        label_VanityPrivECDSAKeys_S = new QLabel(tab_VanitySumAddressTests);
        label_VanityPrivECDSAKeys_S->setObjectName(QStringLiteral("label_VanityPrivECDSAKeys_S"));
        label_VanityPrivECDSAKeys_S->setGeometry(QRect(10, 10, 111, 20));
        pushButton_CalcSumOfPrivKeys = new QPushButton(tab_VanitySumAddressTests);
        pushButton_CalcSumOfPrivKeys->setObjectName(QStringLiteral("pushButton_CalcSumOfPrivKeys"));
        pushButton_CalcSumOfPrivKeys->setGeometry(QRect(810, 90, 81, 23));
        lineEdit_VanityPrivECDSAKey2_S = new QLineEdit(tab_VanitySumAddressTests);
        lineEdit_VanityPrivECDSAKey2_S->setObjectName(QStringLiteral("lineEdit_VanityPrivECDSAKey2_S"));
        lineEdit_VanityPrivECDSAKey2_S->setGeometry(QRect(10, 60, 881, 20));
        lineEdit_VanityPrivECDSAKey1_S = new QLineEdit(tab_VanitySumAddressTests);
        lineEdit_VanityPrivECDSAKey1_S->setObjectName(QStringLiteral("lineEdit_VanityPrivECDSAKey1_S"));
        lineEdit_VanityPrivECDSAKey1_S->setGeometry(QRect(10, 30, 881, 20));
        label_VanityPublicECDSAKeys = new QLabel(tab_VanitySumAddressTests);
        label_VanityPublicECDSAKeys->setObjectName(QStringLiteral("label_VanityPublicECDSAKeys"));
        label_VanityPublicECDSAKeys->setGeometry(QRect(10, 100, 111, 20));
        pushButton_CalcSumOfPublicKeys = new QPushButton(tab_VanitySumAddressTests);
        pushButton_CalcSumOfPublicKeys->setObjectName(QStringLiteral("pushButton_CalcSumOfPublicKeys"));
        pushButton_CalcSumOfPublicKeys->setGeometry(QRect(810, 180, 81, 23));
        lineEdit_VanityPublicECDSAKey2 = new QLineEdit(tab_VanitySumAddressTests);
        lineEdit_VanityPublicECDSAKey2->setObjectName(QStringLiteral("lineEdit_VanityPublicECDSAKey2"));
        lineEdit_VanityPublicECDSAKey2->setGeometry(QRect(10, 150, 881, 20));
        lineEdit_VanityPublicECDSAKey1 = new QLineEdit(tab_VanitySumAddressTests);
        lineEdit_VanityPublicECDSAKey1->setObjectName(QStringLiteral("lineEdit_VanityPublicECDSAKey1"));
        lineEdit_VanityPublicECDSAKey1->setGeometry(QRect(10, 120, 881, 20));
        tabWidget_VanityAddressTests->addTab(tab_VanitySumAddressTests, QString());
        tab_VanityMultiplyAddressTests = new QWidget();
        tab_VanityMultiplyAddressTests->setObjectName(QStringLiteral("tab_VanityMultiplyAddressTests"));
        lineEdit_VanityMultiplicationOfPrivKeys = new QLineEdit(tab_VanityMultiplyAddressTests);
        lineEdit_VanityMultiplicationOfPrivKeys->setObjectName(QStringLiteral("lineEdit_VanityMultiplicationOfPrivKeys"));
        lineEdit_VanityMultiplicationOfPrivKeys->setGeometry(QRect(10, 210, 881, 20));
        label_VanityPrivECDSAKeys_M = new QLabel(tab_VanityMultiplyAddressTests);
        label_VanityPrivECDSAKeys_M->setObjectName(QStringLiteral("label_VanityPrivECDSAKeys_M"));
        label_VanityPrivECDSAKeys_M->setGeometry(QRect(10, 10, 111, 20));
        pushButton_CalcMultiplicationOfPrivKeys = new QPushButton(tab_VanityMultiplyAddressTests);
        pushButton_CalcMultiplicationOfPrivKeys->setObjectName(QStringLiteral("pushButton_CalcMultiplicationOfPrivKeys"));
        pushButton_CalcMultiplicationOfPrivKeys->setGeometry(QRect(810, 90, 81, 23));
        label_VanityMultiplicationOfPrivKeys = new QLabel(tab_VanityMultiplyAddressTests);
        label_VanityMultiplicationOfPrivKeys->setObjectName(QStringLiteral("label_VanityMultiplicationOfPrivKeys"));
        label_VanityMultiplicationOfPrivKeys->setGeometry(QRect(10, 190, 141, 20));
        lineEdit_VanityPrivECDSAKey2_M = new QLineEdit(tab_VanityMultiplyAddressTests);
        lineEdit_VanityPrivECDSAKey2_M->setObjectName(QStringLiteral("lineEdit_VanityPrivECDSAKey2_M"));
        lineEdit_VanityPrivECDSAKey2_M->setGeometry(QRect(10, 60, 881, 20));
        lineEdit_VanityPrivECDSAKey1_M = new QLineEdit(tab_VanityMultiplyAddressTests);
        lineEdit_VanityPrivECDSAKey1_M->setObjectName(QStringLiteral("lineEdit_VanityPrivECDSAKey1_M"));
        lineEdit_VanityPrivECDSAKey1_M->setGeometry(QRect(10, 30, 881, 20));
        tabWidget_VanityAddressTests->addTab(tab_VanityMultiplyAddressTests, QString());
        tabWidget_Main->addTab(tab_VanityTests, QString());
        tab_Brainwallet = new QWidget();
        tab_Brainwallet->setObjectName(QStringLiteral("tab_Brainwallet"));
        tabWidget_Main->addTab(tab_Brainwallet, QString());
        tab_ProfOfBurn = new QWidget();
        tab_ProfOfBurn->setObjectName(QStringLiteral("tab_ProfOfBurn"));
        tabWidget_Main->addTab(tab_ProfOfBurn, QString());
        tab_SHA256 = new QWidget();
        tab_SHA256->setObjectName(QStringLiteral("tab_SHA256"));
        tabWidget_LibsTests = new QTabWidget(tab_SHA256);
        tabWidget_LibsTests->setObjectName(QStringLiteral("tabWidget_LibsTests"));
        tabWidget_LibsTests->setGeometry(QRect(10, 10, 911, 311));
        tab_HashCalculator = new QWidget();
        tab_HashCalculator->setObjectName(QStringLiteral("tab_HashCalculator"));
        pushButton_CalcStringHash = new QPushButton(tab_HashCalculator);
        pushButton_CalcStringHash->setObjectName(QStringLiteral("pushButton_CalcStringHash"));
        pushButton_CalcStringHash->setGeometry(QRect(770, 250, 121, 23));
        textEdit_DataForHash = new QTextEdit(tab_HashCalculator);
        textEdit_DataForHash->setObjectName(QStringLiteral("textEdit_DataForHash"));
        textEdit_DataForHash->setGeometry(QRect(10, 40, 881, 151));
        lineEdit_HashResult = new QLineEdit(tab_HashCalculator);
        lineEdit_HashResult->setObjectName(QStringLiteral("lineEdit_HashResult"));
        lineEdit_HashResult->setGeometry(QRect(10, 220, 881, 20));
        pushButton_DataForHashToLower = new QPushButton(tab_HashCalculator);
        pushButton_DataForHashToLower->setObjectName(QStringLiteral("pushButton_DataForHashToLower"));
        pushButton_DataForHashToLower->setGeometry(QRect(810, 10, 75, 23));
        pushButton_DataForHashToUpper = new QPushButton(tab_HashCalculator);
        pushButton_DataForHashToUpper->setObjectName(QStringLiteral("pushButton_DataForHashToUpper"));
        pushButton_DataForHashToUpper->setGeometry(QRect(730, 10, 75, 23));
        label_DataForHash = new QLabel(tab_HashCalculator);
        label_DataForHash->setObjectName(QStringLiteral("label_DataForHash"));
        label_DataForHash->setGeometry(QRect(10, 11, 121, 20));
        label_HashResult = new QLabel(tab_HashCalculator);
        label_HashResult->setObjectName(QStringLiteral("label_HashResult"));
        label_HashResult->setGeometry(QRect(10, 200, 71, 16));
        comboBox_HashType = new QComboBox(tab_HashCalculator);
        comboBox_HashType->setObjectName(QStringLiteral("comboBox_HashType"));
        comboBox_HashType->setGeometry(QRect(230, 250, 121, 22));
        label_HashFunction = new QLabel(tab_HashCalculator);
        label_HashFunction->setObjectName(QStringLiteral("label_HashFunction"));
        label_HashFunction->setGeometry(QRect(180, 250, 51, 21));
        pushButton_HashToLower = new QPushButton(tab_HashCalculator);
        pushButton_HashToLower->setObjectName(QStringLiteral("pushButton_HashToLower"));
        pushButton_HashToLower->setGeometry(QRect(90, 250, 75, 23));
        pushButton_HashToUpper = new QPushButton(tab_HashCalculator);
        pushButton_HashToUpper->setObjectName(QStringLiteral("pushButton_HashToUpper"));
        pushButton_HashToUpper->setGeometry(QRect(10, 250, 75, 23));
        pushButton_CalcHexHash = new QPushButton(tab_HashCalculator);
        pushButton_CalcHexHash->setObjectName(QStringLiteral("pushButton_CalcHexHash"));
        pushButton_CalcHexHash->setGeometry(QRect(660, 250, 101, 23));
        tabWidget_LibsTests->addTab(tab_HashCalculator, QString());
        tab_PublicECDSAKey = new QWidget();
        tab_PublicECDSAKey->setObjectName(QStringLiteral("tab_PublicECDSAKey"));
        lineEdit_PrivECDSAKeyTests = new QLineEdit(tab_PublicECDSAKey);
        lineEdit_PrivECDSAKeyTests->setObjectName(QStringLiteral("lineEdit_PrivECDSAKeyTests"));
        lineEdit_PrivECDSAKeyTests->setGeometry(QRect(120, 10, 771, 20));
        label_PrivECDSAKeyTests = new QLabel(tab_PublicECDSAKey);
        label_PrivECDSAKeyTests->setObjectName(QStringLiteral("label_PrivECDSAKeyTests"));
        label_PrivECDSAKeyTests->setGeometry(QRect(10, 10, 101, 20));
        pushButton_CalcPublicECDSAKeyTests = new QPushButton(tab_PublicECDSAKey);
        pushButton_CalcPublicECDSAKeyTests->setObjectName(QStringLiteral("pushButton_CalcPublicECDSAKeyTests"));
        pushButton_CalcPublicECDSAKeyTests->setGeometry(QRect(810, 40, 81, 23));
        label_PublicECDSAKeyTestsUncompressed = new QLabel(tab_PublicECDSAKey);
        label_PublicECDSAKeyTestsUncompressed->setObjectName(QStringLiteral("label_PublicECDSAKeyTestsUncompressed"));
        label_PublicECDSAKeyTestsUncompressed->setGeometry(QRect(10, 70, 181, 20));
        lineEdit_PublicECDSAKeyTestsUncompressed = new QLineEdit(tab_PublicECDSAKey);
        lineEdit_PublicECDSAKeyTestsUncompressed->setObjectName(QStringLiteral("lineEdit_PublicECDSAKeyTestsUncompressed"));
        lineEdit_PublicECDSAKeyTestsUncompressed->setGeometry(QRect(10, 90, 881, 20));
        lineEdit_PublicECDSAKeyTestsCompressed = new QLineEdit(tab_PublicECDSAKey);
        lineEdit_PublicECDSAKeyTestsCompressed->setObjectName(QStringLiteral("lineEdit_PublicECDSAKeyTestsCompressed"));
        lineEdit_PublicECDSAKeyTestsCompressed->setGeometry(QRect(10, 130, 881, 20));
        label_PublicECDSAKeyTestsCompressed = new QLabel(tab_PublicECDSAKey);
        label_PublicECDSAKeyTestsCompressed->setObjectName(QStringLiteral("label_PublicECDSAKeyTestsCompressed"));
        label_PublicECDSAKeyTestsCompressed->setGeometry(QRect(10, 110, 181, 20));
        pushButton_PublicKeyECDAKeyToUpper = new QPushButton(tab_PublicECDSAKey);
        pushButton_PublicKeyECDAKeyToUpper->setObjectName(QStringLiteral("pushButton_PublicKeyECDAKeyToUpper"));
        pushButton_PublicKeyECDAKeyToUpper->setGeometry(QRect(730, 160, 75, 23));
        pushButton_PublicKeyECDAKeyToLower = new QPushButton(tab_PublicECDSAKey);
        pushButton_PublicKeyECDAKeyToLower->setObjectName(QStringLiteral("pushButton_PublicKeyECDAKeyToLower"));
        pushButton_PublicKeyECDAKeyToLower->setGeometry(QRect(810, 160, 75, 23));
        tabWidget_LibsTests->addTab(tab_PublicECDSAKey, QString());
        tabWidget_Main->addTab(tab_SHA256, QString());
        BitcoinTests->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BitcoinTests);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 948, 21));
        BitcoinTests->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BitcoinTests);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BitcoinTests->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BitcoinTests);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BitcoinTests->setStatusBar(statusBar);

        retranslateUi(BitcoinTests);

        tabWidget_Main->setCurrentIndex(5);
        tabWidget_PrivateKeyTests->setCurrentIndex(1);
        tabWidget_VanityAddressTests->setCurrentIndex(2);
        tabWidget_LibsTests->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BitcoinTests);
    } // setupUi

    void retranslateUi(QMainWindow *BitcoinTests)
    {
        BitcoinTests->setWindowTitle(QApplication::translate("BitcoinTests", "Bitcoin Tests", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_BitcoinAddressTests), QApplication::translate("BitcoinTests", "Bitcoin Address Tests", Q_NULLPTR));
        tabWidget_PrivateKeyTests->setTabText(tabWidget_PrivateKeyTests->indexOf(tab_WIFToPrivKey), QApplication::translate("BitcoinTests", "Wallet import format to private key", Q_NULLPTR));
        label_First4BitesOf4->setText(QApplication::translate("BitcoinTests", "5. First 4 bytes of 4:", Q_NULLPTR));
        pushButton_CalculateWIF->setText(QApplication::translate("BitcoinTests", "Send", Q_NULLPTR));
        pushButton_PraseToECDSAQt->setText(QApplication::translate("BitcoinTests", "Prase => Priv ECDSA (Bitcoin)", Q_NULLPTR));
        label_SHA256HashOf2->setText(QApplication::translate("BitcoinTests", "3. SHA-256 hash of 2:", Q_NULLPTR));
        label_PrivECDSAKey->setText(QApplication::translate("BitcoinTests", "1. Private ECDSA Key:", Q_NULLPTR));
        label_Phrase->setText(QApplication::translate("BitcoinTests", "Phrase:", Q_NULLPTR));
        label_6->setText(QApplication::translate("BitcoinTests", "6. Adding 5 at the end of 2:", Q_NULLPTR));
        label_PrependVersion->setText(QApplication::translate("BitcoinTests", "2. Prepend version (add 0x80):", Q_NULLPTR));
        lineEdit_Phrase->setText(QString());
        label_SHA256HashOf3->setText(QApplication::translate("BitcoinTests", "4. SHA-256 hash of 3:", Q_NULLPTR));
        label_7->setText(QApplication::translate("BitcoinTests", "7. Base58 encoding of 6:", Q_NULLPTR));
        tabWidget_PrivateKeyTests->setTabText(tabWidget_PrivateKeyTests->indexOf(tab_PrivKeyToWIF), QApplication::translate("BitcoinTests", "Private key to wallet import format", Q_NULLPTR));
        tabWidget_PrivateKeyTests->setTabText(tabWidget_PrivateKeyTests->indexOf(tab_WIFChecksumChecking), QApplication::translate("BitcoinTests", "WIF checksum checking", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_PrivateKeyTests), QApplication::translate("BitcoinTests", "Private Key Tests", Q_NULLPTR));
        tabWidget_VanityAddressTests->setTabText(tabWidget_VanityAddressTests->indexOf(tab_VanityAddresses), QApplication::translate("BitcoinTests", "Vanity Addresses", Q_NULLPTR));
        tabWidget_VanityAddressTests->setTabText(tabWidget_VanityAddressTests->indexOf(tab_AllVanityAddressTests), QApplication::translate("BitcoinTests", "All Vanity Address Tests", Q_NULLPTR));
        label_VanitySumOfPrivKeys->setText(QApplication::translate("BitcoinTests", "Sum of Private Keys:", Q_NULLPTR));
        label_VanityPrivECDSAKeys_S->setText(QApplication::translate("BitcoinTests", " Private ECDSA Keys:", Q_NULLPTR));
        pushButton_CalcSumOfPrivKeys->setText(QApplication::translate("BitcoinTests", "Send", Q_NULLPTR));
        label_VanityPublicECDSAKeys->setText(QApplication::translate("BitcoinTests", "Public ECDSA Keys:", Q_NULLPTR));
        pushButton_CalcSumOfPublicKeys->setText(QApplication::translate("BitcoinTests", "Send", Q_NULLPTR));
        tabWidget_VanityAddressTests->setTabText(tabWidget_VanityAddressTests->indexOf(tab_VanitySumAddressTests), QApplication::translate("BitcoinTests", "Vanity Sum Address Tests", Q_NULLPTR));
        label_VanityPrivECDSAKeys_M->setText(QApplication::translate("BitcoinTests", " Private ECDSA Keys:", Q_NULLPTR));
        pushButton_CalcMultiplicationOfPrivKeys->setText(QApplication::translate("BitcoinTests", "Send", Q_NULLPTR));
        label_VanityMultiplicationOfPrivKeys->setText(QApplication::translate("BitcoinTests", "Multiplication of Private Keys:", Q_NULLPTR));
        tabWidget_VanityAddressTests->setTabText(tabWidget_VanityAddressTests->indexOf(tab_VanityMultiplyAddressTests), QApplication::translate("BitcoinTests", "Vanity Multiply Address Tests", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_VanityTests), QApplication::translate("BitcoinTests", "Vanity Tests", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_Brainwallet), QApplication::translate("BitcoinTests", "Brainwallet", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_ProfOfBurn), QApplication::translate("BitcoinTests", "Proof of Burn", Q_NULLPTR));
        pushButton_CalcStringHash->setText(QApplication::translate("BitcoinTests", "Calculate String Hash", Q_NULLPTR));
        pushButton_DataForHashToLower->setText(QApplication::translate("BitcoinTests", "to Lower", Q_NULLPTR));
        pushButton_DataForHashToUpper->setText(QApplication::translate("BitcoinTests", "to Upper", Q_NULLPTR));
        label_DataForHash->setText(QApplication::translate("BitcoinTests", "Data:", Q_NULLPTR));
        label_HashResult->setText(QApplication::translate("BitcoinTests", "Hash:", Q_NULLPTR));
        label_HashFunction->setText(QApplication::translate("BitcoinTests", "Function:", Q_NULLPTR));
        pushButton_HashToLower->setText(QApplication::translate("BitcoinTests", "to Lower", Q_NULLPTR));
        pushButton_HashToUpper->setText(QApplication::translate("BitcoinTests", "to Upper", Q_NULLPTR));
        pushButton_CalcHexHash->setText(QApplication::translate("BitcoinTests", "Calculate Hex Hash", Q_NULLPTR));
        tabWidget_LibsTests->setTabText(tabWidget_LibsTests->indexOf(tab_HashCalculator), QApplication::translate("BitcoinTests", "Hash Encode Calculator", Q_NULLPTR));
        label_PrivECDSAKeyTests->setText(QApplication::translate("BitcoinTests", " Private ECDSA Key:", Q_NULLPTR));
        pushButton_CalcPublicECDSAKeyTests->setText(QApplication::translate("BitcoinTests", "Send", Q_NULLPTR));
        label_PublicECDSAKeyTestsUncompressed->setText(QApplication::translate("BitcoinTests", "Public ECDSA Key (uncompressed):", Q_NULLPTR));
        label_PublicECDSAKeyTestsCompressed->setText(QApplication::translate("BitcoinTests", "Public ECDSA Key (compressed):", Q_NULLPTR));
        pushButton_PublicKeyECDAKeyToUpper->setText(QApplication::translate("BitcoinTests", "to Upper", Q_NULLPTR));
        pushButton_PublicKeyECDAKeyToLower->setText(QApplication::translate("BitcoinTests", "to Lower", Q_NULLPTR));
        tabWidget_LibsTests->setTabText(tabWidget_LibsTests->indexOf(tab_PublicECDSAKey), QApplication::translate("BitcoinTests", "Public ECDSA Key", Q_NULLPTR));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_SHA256), QApplication::translate("BitcoinTests", "Libs Tests", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BitcoinTests: public Ui_BitcoinTests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITCOINTESTS_H
