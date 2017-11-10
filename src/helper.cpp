#include "helper.h"

std::string helper::convertQStringToStdString(const QString &str)
{
    return str.toLocal8Bit().constData();
}

QString helper::convertStdStringToQString(const std::string &str)
{
    return QTextCodec::codecForName("UTF8")->toUnicode(QByteArray(str.c_str()));
}

QByteArray helper::getQtHexHashSha256(const QByteArray &ba)
{
    QByteArray hashSha256 = QCryptographicHash::hash(ba, QCryptographicHash::Sha256);
    return hashSha256.toHex();
}

QByteArray helper::getQtHexHashSha256(const QString &str)
{
    return getQtHexHashSha256(str.toUtf8());
}
