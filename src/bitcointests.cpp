#include "bitcointests.h"
#include "ui_bitcointests.h"

BitcoinTests::BitcoinTests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BitcoinTests)
{
    ui->setupUi(this);

    QStringList hashTypes;
    hashTypes << "SHA-256 (Bitcoin)";
    hashTypes << "SHA-256 (Qt)";
    hashTypes << "Base58";
    hashTypes << "RIPEMD 160";

    ui->comboBox_HashType->addItems(hashTypes);
//    ui->comboBox_HashType->setCurrentIndex(1);
//    slotHashTypeChange("");
    connect(ui->comboBox_HashType, SIGNAL(currentTextChanged(QString)),    SLOT(slotHashTypeChange(QString)));

    ui->textEdit_DataForHash->setText("00010966776006953D5567439E5E39F86A0D273BEE");
    ui->lineEdit_PrivECDSAKeyTests->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");

    ui->lineEdit_VanityPrivECDSAKey1_S->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");
    ui->lineEdit_VanityPrivECDSAKey2_S->setText("B18427B169E86DE681A1A62588E1D02AE4A7E83C1B413849989A76282A7B562F");
    runCommand("pushButton_CalcSumOfPrivKeys");

    ui->lineEdit_VanityPrivECDSAKey1_M->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");
    ui->lineEdit_VanityPrivECDSAKey2_M->setText("B18427B169E86DE681A1A62588E1D02AE4A7E83C1B413849989A76282A7B562F");
    runCommand("pushButton_CalcMultiplicationOfPrivKeys");

    connect( ui->pushButton_HashToLower,                    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_HashToUpper,                    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_DataForHashToLower,             SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_DataForHashToUpper,             SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcHexHash,                    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcStringHash,                 SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_PublicKeyECDAKeyToLower,        SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_PublicKeyECDAKeyToUpper,        SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_PraseToECDSAQt,                 SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalculateWIF,                   SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcPublicECDSAKeyTests,        SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_CalcSumOfPrivKeys,              SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcSumOfPublicKeys,            SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_CalcMultiplicationOfPrivKeys,   SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

}

BitcoinTests::~BitcoinTests()
{
    delete ui;
}

void BitcoinTests::init(QString version)
{
    QString initialPhrase = "Hello Bitcoin! Hello Blockchain!";
    ui->lineEdit_Phrase->setText(initialPhrase);
    updatePrivECDSAKey();
    updateWIF();
    setWindowTitle("Bitcoin Tests " + version);
}

void BitcoinTests::updatePrivECDSAKey()
{
    QString phrase = ui->lineEdit_Phrase->text().trimmed();
    //getQtHexHashSha256
    QString privECDSAKey = helper::getHexHashSha256FromString(phrase).toUpper();
    ui->lineEdit_PrivECDSAKey->setText(privECDSAKey);
    //ui->lineEdit_PrivECDSAKeyTests->setText(privECDSAKey);
}

void BitcoinTests::updateWIF()
{
    QString privECDSAKey = ui->lineEdit_PrivECDSAKey->text().trimmed();
    QString prependVersion = QString("80" + privECDSAKey);
    ui->lineEdit_PrependVersion->setText(prependVersion);

    //getQtHexHashSha256FromHexString
    QString stingSHA256HashOf2 = helper::getHexHashSha256FromHexString(prependVersion).toUpper();
    ui->lineEdit_SHA256HashOf2->setText(stingSHA256HashOf2);

    QString stingSHA256HashOf3 = helper::getHexHashSha256FromHexString(stingSHA256HashOf2).toUpper();
    ui->lineEdit_SHA256HashOf3->setText(QString(stingSHA256HashOf3));

    QByteArray first4BitesOf4;
    for (int i = 0; i < 8; i++) {
        first4BitesOf4.append(stingSHA256HashOf3.at(i));
    }
    QString stringFirst4BitesOf4 = QString(first4BitesOf4);
    ui->lineEdit_First4BitesOf4->setText(stringFirst4BitesOf4);

    QString beforeBase58 = prependVersion + first4BitesOf4;
    ui->lineEdit_Adding5AtTheEndOf2->setText(beforeBase58);
    ui->lineEdit_AfterBase58->setText(helper::encodeBase58(beforeBase58));
}

void BitcoinTests::slotHashTypeChange(QString)
{
    bool enabled = (ui->comboBox_HashType->currentText() == "Base58") ? false : true;
    ui->pushButton_HashToLower->setEnabled(enabled);
    ui->pushButton_HashToUpper->setEnabled(enabled);
    ui->pushButton_CalcHexHash->setEnabled(enabled);
}

void BitcoinTests::runCommand(QString command)
{
    if ( command == "pushButton_PraseToECDSAQt" ) {
        updatePrivECDSAKey();
        updateWIF();
    }
    else if ( command == "pushButton_CalcPublicECDSAKeyTests" ) {
        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(helper::getPublicECDSAKey(ui->lineEdit_PrivECDSAKeyTests->text()).toUpper());
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(helper::getPublicECDSAKey(ui->lineEdit_PrivECDSAKeyTests->text(), true).toUpper());
    }
    else if ( command == "pushButton_PublicKeyECDAKeyToUpper" ) {
        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(ui->lineEdit_PublicECDSAKeyTestsUncompressed->text().toUpper());
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(ui->lineEdit_PublicECDSAKeyTestsCompressed->text().toUpper());
    }
    else if ( command == "pushButton_PublicKeyECDAKeyToLower" ) {
        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(ui->lineEdit_PublicECDSAKeyTestsUncompressed->text().toLower());
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(ui->lineEdit_PublicECDSAKeyTestsCompressed->text().toLower());
    }
    else if ( command == "pushButton_CalculateWIF" ) {
        updateWIF();
    }
    else if ( command == "pushButton_DataForHashToLower" ) {
        ui->textEdit_DataForHash->setText(ui->textEdit_DataForHash->toPlainText().toLower());
    }
    else if ( command == "pushButton_DataForHashToUpper" ) {
        ui->textEdit_DataForHash->setText(ui->textEdit_DataForHash->toPlainText().toUpper());
    }
    else if ( command == "pushButton_HashToLower" ) {
        ui->lineEdit_HashResult->setText(ui->lineEdit_HashResult->text().toLower());
    }
    else if ( command == "pushButton_HashToUpper" ) {
        ui->lineEdit_HashResult->setText(ui->lineEdit_HashResult->text().toUpper());
    }
    else if ( command == "pushButton_CalcHexHash" || command == "pushButton_CalcStringHash" ) {
        QString hashFunction = ui->comboBox_HashType->currentText();
        QString dataForHash = ui->textEdit_DataForHash->toPlainText();
        QString hashResult = "";
        if ( command == "pushButton_CalcHexHash" ) {
            if (hashFunction == "SHA-256 (Qt)") {
                hashResult = helper::getQtHexHashSha256FromHexString(dataForHash);
            }
            else if (hashFunction == "RIPEMD 160") {
                hashResult = helper::getHexHashRipemd160FromHexString(dataForHash);
            }
            else if (hashFunction == "SHA-256 (Bitcoin)") {
                hashResult = helper::getHexHashSha256FromHexString(dataForHash);
            }
            else {
                qDebug() << "pushButton_CalcHexHash; unknown hashFunction == " << hashFunction;
            }
        }
        else {
            if (hashFunction == "SHA-256 (Qt)") {
                hashResult = helper::getQtHashSha256(dataForHash);
            }
            else if (hashFunction == "RIPEMD 160") {
                hashResult = helper::getHexHashRipemd160FromString(dataForHash);
            }
            else if (hashFunction == "Base58") {
                hashResult = helper::encodeBase58(dataForHash);
            }
            else if (hashFunction == "SHA-256 (Bitcoin)") {
                hashResult = helper::getHexHashSha256FromString(dataForHash);
            }
            else {
                qDebug() << "pushButton_CalcStringHash; unknown hashFunction == " << hashFunction;
            }
        }
        ui->lineEdit_HashResult->setText(hashResult);
    }
    else if ( command == "pushButton_CalcSumOfPrivKeys" ) {
        ui->lineEdit_VanitySumOfPrivKeys->setText(helper::getPrivateKeysSum(ui->lineEdit_VanityPrivECDSAKey1_S->text(), ui->lineEdit_VanityPrivECDSAKey2_S->text()).toUpper());
        ui->lineEdit_VanityPublicECDSAKey1->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityPrivECDSAKey1_S->text()).toUpper());
        ui->lineEdit_VanityPublicECDSAKey2->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityPrivECDSAKey2_S->text()).toUpper());
    }
    else if ( command == "pushButton_CalcSumOfPublicKeys" ) {
        QString res = helper::getPublicKeysSum(ui->lineEdit_VanityPublicECDSAKey1->text().trimmed(), ui->lineEdit_VanityPublicECDSAKey2->text().trimmed());
    }
    else if ( command == "pushButton_CalcMultiplicationOfPrivKeys" ) {
        ui->lineEdit_VanityMultiplicationOfPrivKeys->setText(helper::getPrivateKeysMultiplication(ui->lineEdit_VanityPrivECDSAKey1_M->text().trimmed(), ui->lineEdit_VanityPrivECDSAKey2_M->text().trimmed()).toUpper());
    }
    else {
        qDebug() << "Core::buttonsClicked(); Unknown sender()->objectName() == " << sender()->objectName();
    }

}

void BitcoinTests::buttonsClicked()
{
    runCommand(sender()->objectName());
}
