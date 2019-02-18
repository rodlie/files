#ifndef MIMEUTILS_H
#define MIMEUTILS_H

#include "properties.h"

#include <QFileInfo>

/**
 * @class MimeUtils
 * @brief Helps with mime type management
 * @author Michal Rost
 * @date 29.4.2013
 */
class MimeUtils : public QObject {
  Q_OBJECT
public:
  explicit MimeUtils(QObject* parent = nullptr);
  virtual ~MimeUtils();
  void openInApp(QString exe, const QFileInfo &file, QString termCmd = QString());
  void openFilesInApp(QString exe, const QStringList &files, QString termCmd);
  void openInApp(const QFileInfo &file, QString termCmd = QString());
  void setDefaultsFileName(const QString &fileName);
  void setDefault(const QString &mime, const QStringList &apps);
  QStringList getDefault(const QString &mime) const;
  QStringList getMimeTypes() const;
  QString getMimeType(const QString &path);
  QString getDefaultsFileName() const;
  QString getAppForMimeType(const QString &mime) const;
public slots:
  void generateDefaults();
  void saveDefaults();
  void loadDefaults();
private:
  bool defaultsChanged;
  QString defaultsFileName;
  Properties* defaults;
};

#endif // MIMEUTILS_H
