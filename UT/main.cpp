#include <QtTest>
#include "testunits.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestUnits testTokenizer;
    return QTest::qExec(&testTokenizer, argc, argv);
}
