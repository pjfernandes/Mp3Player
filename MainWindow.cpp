#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    player = new QMediaPlayer(this);

    openButton = new QPushButton("Open", this);
    playButton = new QPushButton("Play", this);
    pauseButton = new QPushButton("Pause", this);
    stopButton = new QPushButton("Stop", this);

    connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::play);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::pause);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stop);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(openButton);
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(stopButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    delete player;
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open MP3 File", QDir::homePath(), "MP3 Files (*.mp3)");
    if (!fileName.isEmpty()) {
        player->setMedia(QUrl::fromLocalFile(fileName));
    }
}

void MainWindow::play() {
    player->play();
}

void MainWindow::pause() {
    player->pause();
}

void MainWindow::stop() {
    player->stop();
}