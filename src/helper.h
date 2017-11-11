#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QDebug>
#include <iostream>

#include <assert.h>

#define QT_STRING  helper::convertStdStringToQString
#define STD_STRING helper::convertQStringToStdString

namespace helper {

    std::string convertQStringToStdString(const QString &str);
    QString convertStdStringToQString(const std::string &str);

    QString encodeBase58(const QString &str);

    QByteArray  getQtHexHashSha256(const QByteArray &ba);
    QString     getQtHexHashSha256(const QString &str);

    QString getQtHexHashSha256FromHexString(const QString &str);

    QString getPublicECDSAKey(const QString &privKey);
}

#endif // HELPER_H
