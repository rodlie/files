/****************************************************************************
* This file is part of qtFM, a simple, fast file manager.
* Copyright (C) 2012, 2013 Michal Rost
* Copyright (C) 2010, 2011, 2012 Wittfella
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
* Contact e-mail: rost.michal@gmail.com, wittfella@qtfm.org
*
****************************************************************************/

#include <QApplication>
#include "mainwindow.h"

#ifdef WITH_MAGICK
#include <Magick++.h>
#endif

#include <stdio.h>
#include <stdlib.h>

void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    if (localMsg.contains("link outline hasn't been detected!") ||
        localMsg.contains("iCCP: known incorrect sRGB profile") ||
        localMsg.contains("XDG_RUNTIME_DIR")) { return; }
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
#if QT_VERSION >= 0x050500
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
#endif
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

/**
 * @brief main function
 * @param argc number of command line arguments
 * @param argv command line arguments
 * @return 0/1
 */

int main(int argc, char *argv[]) {

  qInstallMessageHandler(msgHandler);

#ifdef WITH_MAGICK
  Magick::InitializeMagick(nullptr);
#endif
  QApplication app(argc, argv);
  QApplication::setOrganizationName(APP);
  QApplication::setApplicationName(APP);
  QApplication::setOrganizationDomain("eu");

  // Initialize resources
  //Q_INIT_RESOURCE(resources);

  // Translate application
  /*QTranslator qtTranslator;
  qtTranslator.load("qt_" + QLocale::system().name(),
                    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
  app.installTranslator(&qtTranslator);
  QTranslator qtfmTranslator;
  qtfmTranslator.load("/usr/share/qtfm/qtfm_" + QLocale::system().name());
  app.installTranslator(&qtfmTranslator);*/

  // Create main window and execute application
  MainWindow mainWin;
  return app.exec();
}
