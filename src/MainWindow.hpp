//
// Created by Michin on 08.06.2024.
//

#ifndef TEXTEDITOR_MAINWINDOW_HPP
#define TEXTEDITOR_MAINWINDOW_HPP

#include <QMainWindow>
#include <QSessionManager>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow();

    void loadFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();

#ifndef QT_NO_SESSIONMANAGER
    void commitData(QSessionManager &);
#endif

private:
    void createAction();
    void createStatusBar();
    void roadSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *testEdit;
    QString curFile;
};


#endif //TEXTEDITOR_MAINWINDOW_HPP
