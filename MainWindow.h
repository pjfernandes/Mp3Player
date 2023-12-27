#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();
    void play();
    void pause();
    void stop();

private:
    QMediaPlayer *player;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
};

#endif // MAINWINDOW_H