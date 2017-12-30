#include "myalarm.h"
#include "ui_myalarm.h"

myAlarm::myAlarm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myAlarm)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    myTimer->setSingleShot(false);         //make timer never be overdue.
    timeShow = new QTimer(this);
    mTimer = new QTimer(this);

    QString path = QCoreApplication::applicationDirPath();
    path.append("/data.txt");
    file = new QFile(path);
    in.setDevice(file);
    out.setDevice(file);
    listUpdate();

    ui->positionSlider->setMaximum(5*60*1000);
    player = new QMediaPlayer(this);
    iter = 0;

    timeShow->start(1000);
    connect(timeShow,SIGNAL(timeout()),this,SLOT(showTime()));
    connect(timeShow,SIGNAL(timeout()),this,SLOT(leftTime()));

    mTimer->start(1);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(checkPlay()));
    connect(this,SIGNAL(endPlay()),this,SLOT(updateInterval()));
    connect(this,SIGNAL(manStop()),SLOT(updateInterval()));

    works();
    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(works()));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(setPositionSlider(qint64)));

    ui->volumnSlider->setValue(50);
    player->setVolume(50);
}

myAlarm::~myAlarm()
{
    delete ui;
}

QString myAlarm::readText()
{
    QString contents = "";
    QString line;
    if(file->open(QFile::ReadOnly | QFile::Text)){
        line = in.readLine();
        while(!line.isNull()){
            //const char *str = line.constData();
            //if(str[0])contents = contents+line;
            if(!line.isEmpty()) contents = contents+line+"\n";
            line = in.readLine();
        }
        file->close();
        //qDebug()<<"read contents is "<<contents;
        return contents;
    }
    else {
        qDebug()<<"read open failed.";
        return "";
    }
}

void myAlarm::musicPlay()
{
    QString text = readText();
    QStringList musicList = text.split("\n");
    int all = getSongs();
    if(all <= 0){
        QMessageBox::information(this,"music play","here is no music to play.");
        return ;
    }
    qint16 dex = iter%all;
    qDebug()<<"dex: "<<dex;
    QStringList songList = musicList[dex].split("|");
    QString songAddr = songList.last();
    QFile tmpFile(songAddr);
    if(!tmpFile.open(QFile::ReadOnly)){
        QDialog dlg;
        QMessageBox::warning(&dlg,"where is file","we can't find your music file in disk.\n \
the lost file is:\n \
"+songAddr);
    }
    else {
        tmpFile.close();
        player->setMedia(QUrl::fromLocalFile(songAddr));
        player->setVolume(100);
        player->play();

        //minutes = (moreMsec + minutes*60*1000)/1000/60;
        iter++;
        //if(minutes == 0){      // check whether QMediaPlay::play() is blocking.
            //musicPlay();       // yes, it's not blocking.
        //}
    }
}

void myAlarm::showTime()
{
    QTime now = QTime::currentTime();
    QString str = "now ";
    str = str + now.toString("hh:mm:ss");
    ui->timeLabel->setText(str);
    QFont font("Microsoft YaHei",20);
    ui->timeLabel->setFont(font);
}

void myAlarm::leftTime()
{
    QString str = "left ";
    if(ui->positionSlider->value()>0){
        str = "00:00:00";
    }
    else {
        int mesc = myTimer->remainingTime();
        int hour = mesc/1000/60/60;
        int minute = mesc/1000/60 - hour*60;
        int sec = mesc/1000-hour*60*60-minute*60;

        if(hour>=0 && hour<=9)
        str = str + "0" + QString::number(hour)+":";
        else  str = str + QString::number(hour)+":";

        if(minute>=0 && minute<=9)
        str = str + "0" + QString::number(minute)+":";
        else str = str + QString::number(minute)+":";

        if(sec>=0 && sec<=9)
        str = str + "0" + QString::number(sec);
        else str = str + QString::number(sec);
    }
    ui->leftLabel->setText(str);
    QFont font("Microsoft YaHei",20);
    ui->leftLabel->setFont(font);
}

void myAlarm::listUpdate()
{
    int row = 0;
    if(ui->listWidget->currentRow()>=0) row = ui->listWidget->currentRow();

    ui->listWidget->clear();
    if(file->open(QFile::ReadOnly | QFile::Text)){
        QString line;
        line = in.readLine();
        while(!line.isEmpty()){
            QStringList strs = line.split("|");
            QString musicName = strs.first();
            ui->listWidget->addItem(musicName);
            line = in.readLine();
        }
        file->close();
    }
    else qDebug()<<"file read open error!";

    ui->listWidget->setCurrentRow(row);
}

qint16 myAlarm::getSongs()
{
    return ui->listWidget->count();
}

void myAlarm::works()
{
    QString minutesText = ui->comboBox->currentText();
    minutes = minutesText.toInt();
    int mesc = 1000*60;
    int interval = minutes*mesc;
    myTimer->start(interval);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(musicPlay()));
}

void myAlarm::setPositionSlider(qint64 i)  // position i is msec.
{
    ui->positionSlider->setValue(i);
}

void myAlarm::updateInterval()
{
    //moreMsec = ui->positionSlider->maximum();
    myTimer->setInterval(minutes*60*1000);
    ui->positionSlider->setValue(0);
    ui->positionSlider->setMaximum(5*1000*60);
}

void myAlarm::checkPlay()
{
    if(player->mediaStatus() == QMediaPlayer::EndOfMedia){
        player->stop();
        emit endPlay();
    }
    return ;
}

void myAlarm::on_addButton_clicked()
{
    QList<QUrl> list;
    QStringList filters;
    QString text;
    QFileDialog dialog;
    QString path = QCoreApplication::applicationDirPath();

    list<<QUrl::fromLocalFile(path);
    dialog.setSidebarUrls(list);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    filters << "music files (*.mp3 *.wma *.wav *.mod)";
    dialog.setNameFilters(filters);
    text = readText();

    if(dialog.exec()) {
        QStringList dirList, fileList;
        QStringList tmpList;
        dirList = dialog.selectedFiles();

        foreach (QString newFile, dirList) {
            //qDebug() << file;
            tmpList = newFile.split("/");
            // find *.mp3 *.wma *.wav *.mod
            // .mp3 file is ^.*\.mp3$,  we use | combinate all necessary files.
            int index = tmpList.indexOf(QRegExp("^.*\.mp3$|^.*\.wma$|^.*\.wav$|^.*\.mod$"));
            QString addString = tmpList[index]+"|"+newFile+"\n";
            text = text+addString;
        }
        if(file->open(QFile::WriteOnly | QFile::Text)){
            out<<text;
            file->flush();
            file->close();
        }
    }
    listUpdate();
}

void myAlarm::on_insertButton_clicked()
{
    const int insertRow = ui->listWidget->currentRow();  /* start from 0 */
    if(insertRow < 0){
        QMessageBox::warning(this,"Insert Music","we need cursor");
        return ;
    }
    QList<QUrl> list;
    QStringList filters;
    QString text;
    QStringList textList;

    QFileDialog dialog;
    QString newText = "";
    QStringList dirList, fileList;
    QStringList tmpList;
    QString addString;

    QString path = QCoreApplication::applicationDirPath();
    list<<QUrl::fromLocalFile(path);
    dialog.setSidebarUrls(list);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    filters << "music files (*.mp3 *.wma *.wav *.mod)";
    dialog.setNameFilters(filters);
    text = readText();

    if(dialog.exec()) {
        //qDebug()<<"insert :";
        dirList = dialog.selectedFiles();
        int dex = 0;
        textList = text.split("\n");//(QRegExp("[\n ]"));
        foreach (QString textListLine, textList) {
            if(dex == insertRow){
                foreach (QString newFile, dirList) {
                    tmpList = newFile.split("/");
                    // find *.mp3 *.wma *.wav *.mod
                    // .mp3 file is ^.*\.mp3$,  we use | combinate all necessary files.
                    int index = tmpList.indexOf(QRegExp("^.*\.mp3$|^.*\.wma$|^.*\.wav$|^.*\.mod$"));
                    //qDebug()<<index;
                    addString  = tmpList[index]+"|"+newFile+"\n";
                    newText = newText+addString;
                    //qDebug()<<addString;
                    dex++;
                }
            }
            if(!textListLine.isEmpty()){
                newText = newText+textListLine+"\n";
                dex++;
            }
        }
        if(file->open(QFile::WriteOnly | QFile::Text)){
            ui->listWidget->clear();
            out<<newText;
            file->flush();
            file->close();
        }
        //qDebug()<<"music list add and update";
    }
    listUpdate();
    ui->listWidget->setCurrentRow(insertRow);
}

void myAlarm::on_deleteButton_clicked()
{
    QString contents = readText();
    const int row = ui->listWidget->currentRow();
    //qDebug()<<"deleted row: "<<row;
    if(row >=0 )ui->listWidget->takeItem(row);
    else {
        QMessageBox::warning(this,"Delete Music","we need cursor!");
        return ;
    }

    QStringList list = contents.split("\n"); //(QRegExp("[\n ]"));
    if(!file->open(QFile::WriteOnly | QFile::Text)) {
        qDebug()<<"write open failed.";
        return ;
    }
    int dex = 0;
    foreach (QString line, list) {
        QStringList strArr = line.split("|");
        QString goal = strArr.first();
        if(row == dex){
            //qDebug()<<"deleted!";
            dex++;
        }
        else {
            if(!line.isEmpty()){
                out<<line+"\n";
                dex++;
            }
        }
    }
    file->flush();
    file->close();

}

void myAlarm::on_clearButton_clicked()
{
    ui->listWidget->clear();
    if(file->open(QFile::WriteOnly | QFile::Text)){
        out<<"";
        file->flush();
        file->close();
    }
    else qDebug()<<"file write open error.";
}

void myAlarm::on_stopButton_clicked()
{
    player->stop();
    emit manStop();
    //player->pause();
    //iter++;
}


void myAlarm::on_volumnSlider_sliderMoved(int position)
{
    //qDebug()<<position;
    player->setVolume(position);
}
