#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QTextCodec>
#include <QCryptographicHash>

#define QT_STRING  loghelper::qt::convertStdStringToQString
#define STD_STRING loghelper::qt::convertQStringToStdString

namespace helper {
    std::string convertQStringToStdString(const QString &str);
    QString convertStdStringToQString(const std::string &str);
    QByteArray getQtHexHashSha256(const QByteArray &ba);
    QByteArray getQtHexHashSha256(const QString &str);
}

#endif // HELPER_H
