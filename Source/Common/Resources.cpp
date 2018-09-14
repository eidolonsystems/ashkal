#include "Ashkal/Ashkal/Resources.hpp"
#include <cstdio>
#include <QApplication>
#include <QFontDatabase>
#include <QtPlugin>

#ifdef _MSC_VER
  Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#elif __linux__
  Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
#endif

Q_IMPORT_PLUGIN(QGifPlugin);
Q_IMPORT_PLUGIN(QSvgIconPlugin);

void local_resources() {
  Q_INIT_RESOURCE(Resources);
}

void Ashkal::initialize_resources() {
#ifdef _DEBUG
  std::freopen("stdout.log", "w", stdout);
  std::freopen("stderr.log", "w", stderr);
#endif
  local_resources();
}
