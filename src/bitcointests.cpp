#include "bitcointests.h"
#include "ui_bitcointests.h"
#include "digest.h"
#include "vanity.h"

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
    connect(ui->comboBox_HashType, SIGNAL(currentTextChanged(QString)),    SLOT(slotHashTypeChange(QString)));

    ui->textEdit_DataForHash->setText("00010966776006953D5567439E5E39F86A0D273BEE");
    ui->lineEdit_PrivECDSAKeyTests->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");

    ui->lineEdit_VanityPrivECDSAKey1_S->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");
    ui->lineEdit_VanityPrivECDSAKey2_S->setText("B18427B169E86DE681A1A62588E1D02AE4A7E83C1B413849989A76282A7B562F");
    runCommand("pushButton_CalcSumOfPrivKeys");

    ui->lineEdit_VanityPrivECDSAKey1_M->setText("E80F4E9BDA5459EDA5FD088D85C9F77FB7E047A1F3E057FEF1D1573CD5DE3915");
    ui->lineEdit_VanityPrivECDSAKey2_M->setText("A846985F3F170D4028A7DC301F6D1DFD8466168B7142D40E040D5BED8683B35E");

    runCommand("pushButton_CalcMultiplicationOfPrivKeys");

    // Init task "Proof of Burn"
    ui->lineEdit_PoB_AddrRoot->setText("1Test");
    ui->lineEdit_PoB_AddrFiller->setText("x");
    runCommand("pushButton_PoB");

    // Init task "Wallet import format to private key"
    ui->lineEdit_Priv1_WIF->setText("5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ");
    runCommand("pushButton_Priv1_WIF");

    // Init task "WIF checksum checking"
    ui->lineEdit_PrivChkSum_WIF->setText("5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ");
    runCommand("pushButton_PrivChkSum_WIF");

    // Init task "Brainwallet"
    ui->lineEdit_BWt_SecPass->setText("correct horse battery staple");
    runCommand("pushButton_BWt_SecPass");

    // Init Vanity Addresses
    ui->lineEdit_Pattern->setText("1Address");
    ui->lineEdit_Bountry->setText("1");
    runCommand("pushButton_CalculatePattern");

    // All vanity test
    ui->lineEdit_VA_priv1->setText("18E14A7B6A307F426A94F8114701E7C8E774E7F9A47E2C2035DB29A206321725");
    ui->lineEdit_VA_priv2->setText("B18427B169E86DE681A1A62588E1D02AE4A7E83C1B413849989A76282A7B562F");
    ui->lineEdit_VA_N1->setText("0");
    ui->lineEdit_VA_N2->setText("80");
    runCommand("pushButton_AllVan_Calc");

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
    connect( ui->pushButton_CalculatePattern,               SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_CalcGenerationFromPublicKey,    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_PoB,                            SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_PrivChkSum_WIF,                 SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_PrivChkSum_Rand,                SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_Priv1_WIF,                      SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_Priv1_Rand,                     SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pb_Addr_NewKeyPair,                        SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pb_Addr_CalcFast,                          SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_BWt_SecPass,                     SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );

    connect( ui->pushButton_AllVan_Calc,                    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
    connect( ui->pushButton_AllVan_Rand,                    SIGNAL(clicked(bool)), this, SLOT(buttonsClicked()) );
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

    ui->le_Addr_PrivateKey->setText(ADDRESS_TEST_ECDSA_PRIVATE_KEY);
    ui->le_Addr_PublicKey->setText(ADDRESS_TEST_ECDSA_PUBLIC_KEY);
    updateAddressTest();

    setWindowTitle("Bitcoin Tests " + version);
}

void BitcoinTests::updatePrivECDSAKey()
{
    QString phrase = ui->lineEdit_Phrase->text().trimmed();
    QString privECDSAKey = helper::getHexHashSha256FromString(phrase).toUpper();
    ui->lineEdit_PrivECDSAKey->setText(privECDSAKey);
}

void BitcoinTests::updatePoB()
{
    /* Proof of Burn
        by andrewnn */


    ui->lineEdit_PoB_Result->setText("");

    QString AddressRoot = ui->lineEdit_PoB_AddrRoot->text().trimmed();
    QString AddrFiller = ui->lineEdit_PoB_AddrFiller->text().trimmed();

    try {

        if (AddrFiller.length() != 1) {
            ui->lineEdit_PoB_Result->setText("Make the 'Address filler' field only 1 symbol length!");
            return;
        }

        AddressRoot = AddressRoot.leftJustified(28, AddrFiller[0]);
        AddressRoot = helper::makeWIFCheckSum(AddressRoot);

        ui->lineEdit_PoB_Result->setText(AddressRoot);

    } catch (...) {}


}

void BitcoinTests::updatePrivChkSum()
{
    /* WIF checksum checking
        by andrewnn */

    ui->lineEdit_PrivChkSum_Base58->setText("");
    ui->lineEdit_PrivChkSum_DropLast4->setText("");
    ui->lineEdit_PrivChkSum_SHA1->setText("");
    ui->lineEdit_PrivChkSum_SHA2->setText("");
    ui->lineEdit_PrivChkSum_Sum1->setText("");
    ui->lineEdit_PrivChkSum_Sum2->setText("");
    ui->label_PrivChkSum_Result->setText("");

    try {

        // 1 - Wallet import format
        QString WIF = ui->lineEdit_PrivChkSum_WIF->text().trimmed();

        // 2 - Converting WIF as Base58 string to byte array
        QString WIFasByteArray = helper::decodeBase58(WIF);
        ui->lineEdit_PrivChkSum_Base58->setText(WIFasByteArray);

        // 3 - Dropping last 4 checksum bytes from 2
        QString WIFCuted = WIFasByteArray;
        WIFCuted.chop(4 * 2);
        ui->lineEdit_PrivChkSum_DropLast4->setText(WIFCuted);

        // 4 - SHA-256 hash of 3
        WIFCuted = helper::getHexHashSha256FromHexString(WIFCuted).toUpper();
        ui->lineEdit_PrivChkSum_SHA1->setText(WIFCuted);

        // 5 - SHA-256 hash of 4
        WIFCuted = helper::getHexHashSha256FromHexString(WIFCuted).toUpper();
        ui->lineEdit_PrivChkSum_SHA2->setText(WIFCuted);

        // 6 - First 4 bytes of 4, this is the checksum
        QByteArray first4BitesOf4;
        for (int i = 0; i < 4 * 2; ++i)
            first4BitesOf4.append(WIFCuted.at(i));
        QString Sum1(first4BitesOf4);
        ui->lineEdit_PrivChkSum_Sum1->setText(Sum1);

        // 7 - Take the last 4 bytes of 2, this is the original checksum
        QString Sum2 = WIFasByteArray.right(4 * 2);
        ui->lineEdit_PrivChkSum_Sum2->setText(Sum2);

        ui->label_PrivChkSum_Result->setText(Sum1 == Sum2 ? "OK" : "Fail");
    }
    catch (...) {
        // Something went wrong ...
    }


}

void BitcoinTests::updateWIF2PrivateKey()
{
    /* Wallet import format to private key
        by andrewnn */

    ui->lineEdit_Priv1_Base58->setText("");
    ui->lineEdit_Priv1_DropLast4->setText("");
    ui->lineEdit_Priv1_Priv->setText("");

    try {
        // 1 - Wallet import format
        QString WIF = ui->lineEdit_Priv1_WIF->text().trimmed();

        // 2 - Converting WIF as Base58 string to byte array
        QString WIFasByteArray = helper::decodeBase58(WIF);
        ui->lineEdit_Priv1_Base58->setText(WIFasByteArray);

        // 3 - Dropping last 4 checksum bytes from 2
        QString WIFCuted = WIFasByteArray;
        WIFCuted.chop(4 * 2);
        ui->lineEdit_Priv1_DropLast4->setText(WIFCuted);

        // 4 - Dropping first byte. This is the private key
        WIFCuted.remove(0, 2);
        ui->lineEdit_Priv1_Priv->setText(WIFCuted);

    } catch (...) {}
}

void BitcoinTests::updateBrainwallet()
{
    /* Brainwallet
        by andrewnn */

    ui->lineEdit_BWt_PrivKey->setText("");
    ui->lineEdit_BWt_Res->setText("");

    try {
        // Secret pass phrase
        QString SecPass = ui->lineEdit_BWt_SecPass->text().trimmed();

        // Private key
        QString privECDSAKey = helper::getHexHashSha256FromString(SecPass).toUpper();
        ui->lineEdit_BWt_PrivKey->setText(privECDSAKey);

        // Public key
        QString publicKey = helper::getPublicECDSAKey(privECDSAKey).toUpper();
        //QString publicKeyCompressed = helper::getPublicECDSAKey(privECDSAKey, true).toUpper();

        // SHA256(public_key)
        QString publicKeySHA256 = helper::getHexHashSha256FromHexString(publicKey).toUpper();

        // address = RIPEMD-160(SHA256(public_key))
        QString address = helper::getHexHashRipemd160FromHexString(publicKeySHA256).toUpper();

        // address = (prepend the 0x00)
        QString prepend = "00" + address;

        // SHA256(prepend 00)
        QString address256 = helper::getHexHashSha256FromHexString(prepend).toUpper();

        // SHA256(SHA256(address))
        QString address256256 = helper::getHexHashSha256FromHexString(address256).toUpper();

        // First 4 bytes
        QByteArray first4BitesArray;
        for (int i = 0; i < 4 * 2; ++i)
            first4BitesArray.append(address256256.at(i));

        QString ResultHex = prepend + QString(first4BitesArray);
        QString ResultBase58 = helper::encodeBase58(ResultHex);

        // Resulting address
        ui->lineEdit_BWt_Res->setText(ResultBase58);

    } catch(...) {}

}

void BitcoinTests::randAllVanityTest()
{
    /* Random of All Vanity test
        by andrewnn */

    ui->lineEdit_VA_priv1->setText(helper::getHexHashSha256FromString(helper::GetRandomString()).toUpper());
    ui->lineEdit_VA_priv2->setText(helper::getHexHashSha256FromString(helper::GetRandomString()).toUpper());
}

void BitcoinTests::updateAllVanityTest()
{
    /* All Vanity test
        by andrewnn */

    ui->lineEdit_VA_uncPK1->setText("");
    ui->lineEdit_VA_uncPK2->setText("");

    ui->lineEdit_VA_cPK1->setText("");
    ui->lineEdit_VA_cPK2->setText("");

    ui->lineEdit_VA2_uPK1->setText("");
    ui->lineEdit_VA2_uPK2->setText("");

    ui->lineEdit_VA2_uPubK1->setText("");
    ui->lineEdit_VA2_uPubK2->setText("");

    ui->lineEdit_VA2_uWIF1->setText("");
    ui->lineEdit_VA2_uWIF2->setText("");

    ui->lineEdit_VA2_uA1->setText("");
    ui->lineEdit_VA2_uA2->setText("");

    ui->lineEdit_VA2_cPubK1->setText("");
    ui->lineEdit_VA2_cPubK2->setText("");

    ui->lineEdit_VA_A1->setText("");
    ui->lineEdit_VA_A2->setText("");

    ui->lineEdit_VA_cA1->setText("");
    ui->lineEdit_VA_cA2->setText("");

    ui->lineEdit_VA2_cA1->setText("");
    ui->lineEdit_VA2_cA2->setText("");

    ui->lineEdit_VA2_cPrivK1->setText("");
    ui->lineEdit_VA2_cPrivK2->setText("");

    ui->lineEdit_VA2_cWIF1->setText("");
    ui->lineEdit_VA2_cWIF2->setText("");

    try
    {
        QString privKey1 = ui->lineEdit_VA_priv1->text();
        QString privKey2 = ui->lineEdit_VA_priv2->text();

        // Uncompressed public key
        QString publicKey1 = helper::getPublicECDSAKey(privKey1).toUpper();
        QString publicKey2 = helper::getPublicECDSAKey(privKey2).toUpper();
        ui->lineEdit_VA_uncPK1->setText(publicKey1);
        ui->lineEdit_VA_uncPK2->setText(publicKey2);

        QString NetByte = ui->lineEdit_VA_N1->text();
        QString Prefix = ui->lineEdit_VA_N2->text();

        // Uncompressed address
        QString adress1 = helper::getWIFFromPublicKey(publicKey1, NetByte);
        ui->lineEdit_VA_A1->setText(adress1);
        QString adress2 = helper::getWIFFromPublicKey(publicKey2, NetByte);
        ui->lineEdit_VA_A2->setText(adress2);

        // Compressed public key
        QString publicKeyComp1 = helper::getPublicECDSAKey(privKey1, true).toUpper();
        QString publicKeyComp2 = helper::getPublicECDSAKey(privKey2, true).toUpper();
        ui->lineEdit_VA_cPK1->setText(publicKeyComp1);
        ui->lineEdit_VA_cPK2->setText(publicKeyComp1);

        // Compressed address
        QString adress1c = helper::getWIFFromPublicKey(publicKeyComp1, NetByte);
        ui->lineEdit_VA_cA1->setText(adress1c);
        QString adress2c = helper::getWIFFromPublicKey(publicKeyComp2, NetByte);
        ui->lineEdit_VA_cA2->setText(adress2c);


        // Sum and Mult

        // Uncompressed private key

        QString privateSum = helper::getPrivateKeysSum(privKey1, privKey2).toUpper();
        ui->lineEdit_VA2_uPK1->setText(privateSum);

        QString privateMult = helper::getPrivateKeysMultiplication(privKey1, privKey2).toUpper();
        ui->lineEdit_VA2_uPK2->setText(privateMult);

        // Uncompressed WIF

        QString UncompWIFSum = helper::getWIFFromPrivateKey(privateSum);
        QString UncompWIFMult = helper::getWIFFromPrivateKey(privateMult);

        ui->lineEdit_VA2_uWIF1->setText(UncompWIFSum);
        ui->lineEdit_VA2_uWIF2->setText(UncompWIFMult);

        // Uncompressed public key

        QString publicSum = helper::getPublicKeysSum(publicKey1, publicKey2, false).toUpper();
        ui->lineEdit_VA2_uPubK1->setText(publicSum);

        QString publicMult = helper::getPublicPrivateKeysMultiplication(publicKey1, privKey2, false).toUpper();
        ui->lineEdit_VA2_uPubK2->setText(publicMult);

        // Uncompressed address


        QString UncompAdrSum = helper::getWIFFromPublicKey(publicSum);
        QString UncompAdrMult = helper::getWIFFromPublicKey(publicMult);

        ui->lineEdit_VA2_uA1->setText(UncompAdrSum);
        ui->lineEdit_VA2_uA2->setText(UncompAdrMult);


        // Compressed private key
        QString privKeySum = privateSum + "01";
        QString privKeyMult = privateMult + "01";

        ui->lineEdit_VA2_cPrivK1->setText(privKeySum);
        ui->lineEdit_VA2_cPrivK2->setText(privKeyMult);



        // Compressed WIF
        QString compWIF1 = helper::getWIFFromPrivateKey(privKeySum, Prefix);
        ui->lineEdit_VA2_cWIF1->setText(compWIF1);
        QString compWIF2 = helper::getWIFFromPrivateKey(privKeyMult, Prefix);
        ui->lineEdit_VA2_cWIF2->setText(compWIF2);

        // Compressed public key
        QString publicSumComp = helper::getPublicECDSAKey(privateSum, true);
        QString publicMultComp = helper::getPublicECDSAKey(privateMult, true);

        ui->lineEdit_VA2_cPubK1->setText(publicSumComp);
        ui->lineEdit_VA2_cPubK2->setText(publicMultComp);

        // Compressed address
        QString adressSumComp = helper::getWIFFromPublicKey(publicSumComp, NetByte);
        ui->lineEdit_VA2_cA1->setText(adressSumComp);
        QString adressMultComp = helper::getWIFFromPublicKey(publicMultComp, NetByte);
        ui->lineEdit_VA2_cA2->setText(adressMultComp);


    }
    catch(...) {}

}

void BitcoinTests::updateAddressTest(bool GenerateNewKeys)
{
    /// Address tests
    /// @author af (anreyfedorinin)
    ///

    QByteArray  PrivateKey;
    QByteArray  PublicKey;

    QString     PrivateKeyStr;
    QString     PublicKeyStr;

    if (GenerateNewKeys)
    {
        PrivateKeyStr = helper::getHexHashSha256FromString(helper::GetRandomString()).toUpper();
        PublicKeyStr = helper::getPublicECDSAKey(PrivateKeyStr);

        ui->le_Addr_PrivateKey->setText(PrivateKeyStr);
        ui->le_Addr_PublicKey->setText(PublicKeyStr);
    }
    else
    {
        PrivateKeyStr = ui->le_Addr_PrivateKey->text().trimmed();
        PublicKeyStr = ui->le_Addr_PublicKey->text().trimmed();
    }

    PrivateKey = QByteArray::fromHex(PrivateKeyStr.toUtf8().data());
    PublicKey = QByteArray::fromHex(PublicKeyStr.toUtf8().data());

    //  SHA256 hash of PublicKey
    QByteArray  Step2Data =
            helper::CalcHash(PublicKey.data(), PublicKey.size(), CDigest::dtSHA256);
    QString     Step2Str = QString(Step2Data.toHex().data()).toUpper();
    ui->le_Addr_Step2->setText(Step2Str);

    //  RIPEMD-160 hash of data from Step2
    QByteArray  Step3Data =
            helper::CalcHash(Step2Data.data(), Step2Data.size(), CDigest::dtRIPEMD160);
    QString     Step3Str = QString(Step3Data.toHex().data()).toUpper();
    ui->le_Addr_Step3->setText(Step3Str);

    //  Adding network bytes to data from Step3
    QByteArray  Step4Data = Step3Data;
    Step4Data.insert(0, (char)0x00);
    QString     Step4Str = QString(Step4Data.toHex().data()).toUpper();
    ui->le_Addr_Step4->setText(Step4Str);

    //  SHA-256 hash of data from Step4
    QByteArray  Step5Data =
            helper::CalcHash(Step4Data.data(), Step4Data.size(), CDigest::dtSHA256);
    QString     Step5Str = QString(Step5Data.toHex().data()).toUpper();
    ui->le_Addr_Step5->setText(Step5Str);

    //  SHA-256 hash of data from Step5
    QByteArray  Step6Data =
            helper::CalcHash(Step5Data.data(), Step5Data.size(), CDigest::dtSHA256);
    QString     Step6Str = QString(Step6Data.toHex().data()).toUpper();
    ui->le_Addr_Step6->setText(Step6Str);

    //  First 4 bytes of data from Step6
    QByteArray  Step7Data;
    for (int k = 0; k < 4; k++)
    {
        Step7Data.insert(k, Step6Data.at(k));
    }
    QString     Step7Str = QString(Step7Data.toHex().data()).toUpper();
    ui->le_Addr_Step7->setText(Step7Str);

    //  Adding data from Step7 to the data from Step4;
    QByteArray  Step8Data = Step4Data + Step7Data;
    QString     Step8Str = QString(Step8Data.toHex().data()).toUpper();
    ui->le_Addr_Step8->setText(Step8Str);

    //  Base58 encoding of data from Step8
    QString     Step9Str = helper::encodeBase58(Step8Data);
    ui->le_Addr_Step9->setText(Step9Str);
};

void BitcoinTests::calcAddressTestFast()
{
    /// Address tests
    /// @author af (anreyfedorinin)
    ///

    QString     PublicKeyStr = ui->le_Addr_PublicKey->text().trimmed();
    QByteArray  PublicKey = QByteArray::fromHex(PublicKeyStr.toUtf8().data());

    QByteArray  Blob1 = helper::CalcHashN(PublicKey, {CDigest::dtSHA256, CDigest::dtRIPEMD160});
    Blob1.insert(0, (char)0x00);

    QByteArray  Blob2 = helper::CalcHashN(Blob1, {CDigest::dtSHA256, CDigest::dtSHA256});

    for (int k = 0; k < 4; k++)
    {
        Blob1 += Blob2.at(k);
    }

    ui->lbl_Addr_FastResData->setText(helper::encodeBase58(Blob1));
};

void BitcoinTests::updateWIF()
{
    QString privECDSAKey = ui->lineEdit_PrivECDSAKey->text().trimmed();
    QString prependVersion = QString("80" + privECDSAKey);
    ui->lineEdit_PrependVersion->setText(prependVersion);

    QString stingSHA256HashOf2 = helper::getHexHashSha256FromHexString(prependVersion).toUpper();
    ui->lineEdit_SHA256HashOf2->setText(stingSHA256HashOf2);

    QString stingSHA256HashOf3 = helper::getHexHashSha256FromHexString(stingSHA256HashOf2).toUpper();
    ui->lineEdit_SHA256HashOf3->setText(QString(stingSHA256HashOf3));

    QByteArray first4BitesOf4;
    for (int i = 0; i < 8; i++)
    {
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
    if (command == "pushButton_AllVan_Calc")
    {
        updateAllVanityTest();
    }
    else if (command == "pushButton_AllVan_Rand")
    {
        randAllVanityTest();
        updateAllVanityTest();
    }
    else if (command == "pushButton_BWt_SecPass")
    {
        updateBrainwallet();
    }
    else if (command == "pushButton_Priv1_Rand")
    {
        ui->lineEdit_Priv1_WIF->setText(helper::generateWIF());
        updateWIF2PrivateKey();
    }
    else if (command == "pushButton_Priv1_WIF")
    {
        updateWIF2PrivateKey();
    }
    else if (command == "pushButton_PrivChkSum_Rand")
    {
        ui->lineEdit_PrivChkSum_WIF->setText(helper::generateWIF());
        updatePrivChkSum();
    }
    else if (command == "pushButton_PrivChkSum_WIF")
    {
        updatePrivChkSum();
    }
    else if (command == "pushButton_PoB")
    {
        updatePoB();
    }
    else if (command == "pushButton_PraseToECDSAQt")
    {
        updatePrivECDSAKey();
        updateWIF();
    }
    else if (command == "pushButton_CalcPublicECDSAKeyTests")
    {
        QString PrivateKey = ui->lineEdit_PrivECDSAKeyTests->text().trimmed();
        QString PublicKey = helper::getPublicECDSAKey(PrivateKey).toUpper();
        QString CompressedPublicKey = helper::getPublicECDSAKey(PrivateKey, true).toUpper();

        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(PublicKey);
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(CompressedPublicKey);
    }
    else if (command == "pushButton_PublicKeyECDAKeyToUpper")
    {
        QString UncompressedPublicKey = ui->lineEdit_PublicECDSAKeyTestsUncompressed->text().toUpper();
        QString CompressedPublicKey = ui->lineEdit_PublicECDSAKeyTestsCompressed->text().toUpper();

        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(UncompressedPublicKey);
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(CompressedPublicKey);
    }
    else if (command == "pushButton_PublicKeyECDAKeyToLower")
    {
        QString UncompressedPublicKey = ui->lineEdit_PublicECDSAKeyTestsUncompressed->text().toLower();
        QString CompressedPublicKey = ui->lineEdit_PublicECDSAKeyTestsCompressed->text().toLower();

        ui->lineEdit_PublicECDSAKeyTestsUncompressed->setText(UncompressedPublicKey);
        ui->lineEdit_PublicECDSAKeyTestsCompressed->setText(CompressedPublicKey);
    }
    else if (command == "pushButton_CalculateWIF")
    {
        updateWIF();
    }
    else if (command == "pushButton_DataForHashToLower")
    {
        QString Text = ui->textEdit_DataForHash->toPlainText().toLower();
        ui->textEdit_DataForHash->setText(Text);
    }
    else if (command == "pushButton_DataForHashToUpper")
    {
        QString Text = ui->textEdit_DataForHash->toPlainText().toUpper();
        ui->textEdit_DataForHash->setText(Text);
    }
    else if (command == "pushButton_HashToLower")
    {
        QString Text = ui->lineEdit_HashResult->text().toLower();
        ui->lineEdit_HashResult->setText(Text);
    }
    else if (command == "pushButton_HashToUpper")
    {
        QString Text = ui->lineEdit_HashResult->text().toUpper();
        ui->lineEdit_HashResult->setText(Text);
    }
    else if ((command == "pushButton_CalcHexHash") ||
             (command == "pushButton_CalcStringHash"))
    {
        QString hashFunction = ui->comboBox_HashType->currentText();
        QString dataForHash = ui->textEdit_DataForHash->toPlainText();
        QString hashResult = "";
        if (command == "pushButton_CalcHexHash")
        {
            if (hashFunction == "SHA-256 (Qt)")
            {
                hashResult = helper::getQtHexHashSha256FromHexString(dataForHash);
            }
            else if (hashFunction == "RIPEMD 160")
            {
                hashResult = helper::getHexHashRipemd160FromHexString(dataForHash);
            }
            else if (hashFunction == "SHA-256 (Bitcoin)")
            {
                hashResult = helper::getHexHashSha256FromHexString(dataForHash);
            }
            else
            {
                qDebug() << "pushButton_CalcHexHash; unknown hashFunction == " << hashFunction;
            }
        }
        else
        {
            if (hashFunction == "SHA-256 (Qt)")
            {
                hashResult = helper::getQtHashSha256(dataForHash);
            }
            else if (hashFunction == "RIPEMD 160")
            {
                hashResult = helper::getHexHashRipemd160FromString(dataForHash);
            }
            else if (hashFunction == "Base58")
            {
                hashResult = helper::encodeBase58(dataForHash);
            }
            else if (hashFunction == "SHA-256 (Bitcoin)")
            {
                hashResult = helper::getHexHashSha256FromString(dataForHash);
            }
            else
            {
                qDebug() << "pushButton_CalcStringHash; unknown hashFunction == " << hashFunction;
            }
        }
        ui->lineEdit_HashResult->setText(hashResult);
    }
    else if (command == "pushButton_CalcSumOfPrivKeys")
    {
        ui->lineEdit_VanitySumOfPrivKeys->setText(helper::getPrivateKeysSum(ui->lineEdit_VanityPrivECDSAKey1_S->text(), ui->lineEdit_VanityPrivECDSAKey2_S->text()).toUpper());
        ui->lineEdit_VanityPublicECDSAKey1->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityPrivECDSAKey1_S->text()).toUpper());
        ui->lineEdit_VanityPublicECDSAKey2->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityPrivECDSAKey2_S->text()).toUpper());
        ui->lineEdit_VanityPublicKeyFromSumOfPrivateKeys->setText(helper::getPublicECDSAKey(ui->lineEdit_VanitySumOfPrivKeys->text()).toUpper());
        ui->lineEdit_VanityPublicKeyFromSumOfPrivateKeysCorrespondingAddress->setText(helper::getWIFFromPublicKey(ui->lineEdit_VanityPublicKeyFromSumOfPrivateKeys->text()));
        runCommand("pushButton_CalcSumOfPublicKeys");
    }
    else if (command == "pushButton_CalcSumOfPublicKeys")
    {
        ui->lineEdit_VanitySumOfPublicKeys->setText(helper::getPublicKeysSum(ui->lineEdit_VanityPublicECDSAKey1->text().trimmed(), ui->lineEdit_VanityPublicECDSAKey2->text().trimmed()).toUpper());
        ui->lineEdit_VanitySumOfPublicKeysCorrespondingAddress->setText(helper::getWIFFromPublicKey(ui->lineEdit_VanitySumOfPublicKeys->text()));
    }
    else if (command == "pushButton_CalcMultiplicationOfPrivKeys")
    {
        ui->lineEdit_VanityPublicECDSAKey1_M->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityPrivECDSAKey1_M->text()).toUpper());
        ui->lineEdit_VanityPrivECDSAKey_M2->setText(ui->lineEdit_VanityPrivECDSAKey2_M->text());
        ui->lineEdit_VanityMultiplicationOfPrivKeys->setText(helper::getPrivateKeysMultiplication(ui->lineEdit_VanityPrivECDSAKey1_M->text().trimmed(), ui->lineEdit_VanityPrivECDSAKey2_M->text().trimmed()).toUpper());
        ui->lineEdit_VanityPublicKeyFromMultiplicationOfPrivKeys->setText(helper::getPublicECDSAKey(ui->lineEdit_VanityMultiplicationOfPrivKeys->text()).toUpper());
        ui->lineEdit_CorrAddress1->setText(helper::getWIFFromPublicKey(ui->lineEdit_VanityPublicKeyFromMultiplicationOfPrivKeys->text()));
        runCommand("pushButton_CalcGenerationFromPublicKey");
    }
    else if (command == "pushButton_CalcGenerationFromPublicKey")
    {
        ui->lineEdit_VanityPublicKeyFromModdifiedBasePoing_M->setText(helper::getPublicFromModfiedBasePoint(ui->lineEdit_VanityPublicECDSAKey1_M->text(), ui->lineEdit_VanityPrivECDSAKey_M2->text()).toUpper());
        ui->lineEdit_CorrAddress2->setText(helper::getWIFFromPublicKey(ui->lineEdit_VanityPublicKeyFromModdifiedBasePoing_M->text()));
    }
    else if (command == "pushButton_CalculatePattern")
    {
        auto patterComplexity = cosmyc::Vanity::PatternComplexity(ui->lineEdit_Pattern->text());
        ui->label_PatternComplexityRes->setText(helper::getStringFromDouble(patterComplexity));

        ui->label_PatternLavishnessRes->setText(helper::getStringFromDouble(cosmyc::Vanity::PatternLavishness(
                                                    ui->lineEdit_Bountry->text().toULongLong(), patterComplexity)));
    }
    else if (command == "pb_Addr_NewKeyPair")
    {
        updateAddressTest(true);
    }
    else if (command == "pb_Addr_CalcFast")
    {
        calcAddressTestFast();
    }
    else
    {
        qDebug() << "Core::buttonsClicked(); Unknown sender()->objectName() == " << sender()->objectName();
    }
}

void BitcoinTests::buttonsClicked()
{
    runCommand(sender()->objectName());
}
