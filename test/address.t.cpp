#include "address.t.h"
#include "../lib/address.h"
#include <QHostAddress>

using namespace QSS;

Address_T::Address_T()
{
}

void Address_T::testConstructor1()
{
    QHostAddress ip("127.0.0.1");
    Address a("127.0.0.1", 1080), b("err", 1080);
    QCOMPARE(a.getAddress(), QString("127.0.0.1"));
    QCOMPARE(a.getFirstIP(), ip);
    QCOMPARE(a.getPort(), quint16(1080));
    QVERIFY(a.isIPValid());
    QVERIFY(!b.isIPValid());
}

void Address_T::testConstructor2()
{
    QHostAddress ip("127.0.0.1");
    Address a(ip, 1080);
    QCOMPARE(a.getAddress(), QString("127.0.0.1"));
    QCOMPARE(a.getFirstIP(), ip);
    QCOMPARE(a.getPort(), quint16(1080));
    QVERIFY(a.isIPValid());
}

void Address_T::testAssignment()
{
    Address a("127.0.0.1", 1080), b;
    b = a;
    QCOMPARE(a.getAddress(), b.getAddress());
    QCOMPARE(a.getFirstIP(), b.getFirstIP());
    QCOMPARE(a.getPort(), b.getPort());
    QCOMPARE(a.isIPValid(), b.isIPValid());
}

void Address_T::testSetAddress()
{
    QString ipStr("127.0.0.1");
    QHostAddress ip(ipStr);
    Address a;
    a.setAddress(ipStr);
    QCOMPARE(a.getAddress(), ipStr);
    QCOMPARE(a.getFirstIP(), ip);
    QVERIFY(a.isIPValid());
}

void Address_T::testSetIPAddress()
{
    QString ipStr("127.0.0.1");
    QHostAddress ip(ipStr);
    Address a;
    a.setIPAddress(ip);
    QCOMPARE(a.getAddress(), ipStr);
    QCOMPARE(a.getFirstIP(), ip);
    QVERIFY(a.isIPValid());
}

void Address_T::testSetPort()
{
    Address a;
    quint16 port = 1080;
    a.setPort(port);
    QCOMPARE(a.getPort(), port);
}
