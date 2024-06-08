//
// Created by Michin on 08.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow() : textEdit(new QPlainTextEdit)
{
    setCentralWidget(textEdit);

    createActions();
    createStatusBar();

    readSettings();

    connect(textEdit->document(), &QTextDocument::contentsChange,
            this, &MainWindow::documentWasModified);

#ifndef QT_NO_SESSIONMANAGER
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &MainWindow::commitData);
#endif

    setCurrentFile(QString());
    setUnifiedTitleAndToolBarOnMac(true);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave())
    {
        writeSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::newFile()
{
    if(maybeSave())
    {
        textEdit->clear();
        setCurrentFile(QString());
    }
}