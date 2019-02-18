#ifndef APPLICATIONDIALOG_H
#define APPLICATIONDIALOG_H

#include "desktopfile.h"

#include <QDialog>
#include <QTreeWidgetItem>
#include <QMap>
#include <QStringList>
#include <QLineEdit>
#include <QIcon>

class ApplicationDialog : public QDialog
{
  Q_OBJECT

public:
  explicit ApplicationDialog(bool enable_launcher = true,
                             QWidget *parent = nullptr);
  QString getCurrentLauncher() const;

private slots:
  void populate();

protected slots:
  void updateCommand(QTreeWidgetItem* current,
                     QTreeWidgetItem* previous);

protected:
  QTreeWidget *appList;
  QLineEdit *edtCommand;
  DesktopFile result;
  QIcon defaultIcon;
  QMap<QString, QStringList> catNames;
  QMap<QString, QTreeWidgetItem*> categories;
  QMap<QString, QTreeWidgetItem*> applications;
  QTreeWidgetItem* findCategory(const DesktopFile &app);
  void createCategories();
};

#endif // APPLICATIONDIALOG_H
