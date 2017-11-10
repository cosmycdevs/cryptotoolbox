#include "bitcointests.h"
#include "ui_bitcointests.h"

BitcoinTests::BitcoinTests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BitcoinTests)
{
    ui->setupUi(this);
    connect( ui->pushButton_PraseToECDSAQt,     SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcSHA256HashQt,   SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalculateWIF,       SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_ToUpper,            SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_toLower,            SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

}

BitcoinTests::~BitcoinTests()
{
    delete ui;
}

void BitcoinTests::init(QString version)
{
    QString initialPhrase = "Hello Bitcoin! Hello Blockchain!";
    ui->lineEdit_Phrase->setText(initialPhrase);
    ui->textEdit_DataSHA256->setText(initialPhrase);
    updatePrivECDSAKey();
    updateWIF();
    setWindowTitle("Bitcoin Tests " + version);
}

void BitcoinTests::updatePrivECDSAKey()
{
    QString phrase = ui->lineEdit_Phrase->text().trimmed();
    QString privECDSAKey = QString(helper::getQtHexHashSha256(phrase));
    ui->lineEdit_PrivECDSAKey->setText(privECDSAKey);
}

void BitcoinTests::updateWIF()
{
    QString privECDSAKey = ui->lineEdit_PrivECDSAKey->text().trimmed();
    QString prependVersion = QString("80" + privECDSAKey);
    ui->lineEdit_PrependVersion->setText(prependVersion);

    QByteArray hexPrependVersion = QByteArray::fromHex(prependVersion.toUtf8().data());
    QByteArray baSHA256HashOf2 = helper::getQtHexHashSha256(hexPrependVersion);
    QString stingSHA256HashOf2 = QString(baSHA256HashOf2);
    ui->lineEdit_SHA256HashOf2->setText(stingSHA256HashOf2);

    QByteArray hexSHA256HashOf2 = QByteArray::fromHex(stingSHA256HashOf2.toUtf8().data());
    QByteArray baSHA256HashOf3 = helper::getQtHexHashSha256(hexSHA256HashOf2);
    QString stingSHA256HashOf3 = QString(baSHA256HashOf3);
    ui->lineEdit_SHA256HashOf3->setText(QString(stingSHA256HashOf3));

    QByteArray first4BitesOf4;
    for (int i = 0; i < 8; i++) {
        first4BitesOf4.append(baSHA256HashOf3.at(i));
    }
    QString stringFirst4BitesOf4 = QString(first4BitesOf4);
    ui->lineEdit_First4BitesOf4->setText(stringFirst4BitesOf4);

    QString beforeBase58 = prependVersion + first4BitesOf4;
    ui->lineEdit_6->setText(beforeBase58);

    QByteArray hexBeforeBase58 = QByteArray::fromHex(beforeBase58.toUtf8().data());
    std::vector<unsigned char> beforeBase58Vector;
    for (int i = 0; i < hexBeforeBase58.size(); i++) {
        beforeBase58Vector.push_back(hexBeforeBase58.at(i));
    }
    std::string afterBase58Std = EncodeBase58(beforeBase58Vector);
//    std::cout << afterBase58Std << std::endl;
    QString afterBase58 = helper::convertStdStringToQString(afterBase58Std);
    ui->lineEdit_AfterBase58->setText(afterBase58);
}

void BitcoinTests::buttonsClicked()
{
    if ( sender()->objectName() == "pushButton_PraseToECDSAQt" ) {
        updatePrivECDSAKey();
        updateWIF();
    }
    else if ( sender()->objectName() == "pushButton_CalculateWIF" ) {
        updateWIF();
    }
    else if ( sender()->objectName() == "pushButton_CalcSHA256HashQt" ) {
        QString dataSHA256 = ui->textEdit_DataSHA256->toPlainText().trimmed();
        QByteArray hexDataSHA256 = QByteArray::fromHex(dataSHA256.toUtf8().data());
        QString hexHashSha256 = QString(helper::getQtHexHashSha256(hexDataSHA256));
        ui->lineEdit_SHA256Hash->setText(hexHashSha256);
    }
    else if ( sender()->objectName() == "pushButton_ToUpper" ) {
        QString dataSHA256 = ui->textEdit_DataSHA256->toPlainText().trimmed();
        ui->textEdit_DataSHA256->setText(dataSHA256.toUpper());
    }
    else if ( sender()->objectName() == "pushButton_toLower" ) {
        QString dataSHA256 = ui->textEdit_DataSHA256->toPlainText().trimmed();
        ui->textEdit_DataSHA256->setText(dataSHA256.toLower());
    }
    else {
        qDebug() << "Core::buttonsClicked(); Unknown sender()->objectName() == " << sender()->objectName();
    }

}
