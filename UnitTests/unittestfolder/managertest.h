#ifndef MANAGERTEST_H
#define MANAGERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "handlerandmanager/gamemanager.h"
class ManagerTest : public QObject
{
    Q_OBJECT
public:
    explicit ManagerTest(QObject *parent = nullptr);

signals:

public slots:
private Q_SLOTS:
    void simpleTest();
};
QTEST_MAIN(ManagerTest)

#endif // MANAGERTEST_H
