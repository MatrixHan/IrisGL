#ifndef IRISUTILS_H
#define IRISUTILS_H

#include <QDir>
#include <QCoreApplication>

class IrisUtils
{
public:
    static QString getAbsoluteAssetPath(QString relToApp)
    {
        QDir basePath = QDir(QCoreApplication::applicationDirPath());
    #if defined(WIN32)
        basePath.cdUp();
    #elif defined(Q_OS_MAC)
        basePath.cdUp();
        basePath.cdUp();
        basePath.cdUp();
    #endif

        auto path = QDir::cleanPath(basePath.absolutePath() + QDir::separator() + relToApp);
        return path;
    }
};

#endif // IRISUTILS_H
