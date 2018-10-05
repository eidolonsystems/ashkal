#include <QApplication>
#include "Ashkal/Ashkal/Resources.hpp"

using namespace Ashkal;

int main(int argc, char** argv) {
  auto application = QApplication(argc, argv);
  application.setOrganizationName(QObject::tr("Eidolon Systems Ltd."));
  application.setApplicationName(QObject::tr("Ashkal"));
  application.setApplicationVersion("1.0");
  initialize_resources();
  application.exec();
}
