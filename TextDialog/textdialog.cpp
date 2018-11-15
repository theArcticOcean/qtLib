#include "textdialog.h"
#include "ui_textdialog.h"

#include <QDebug>
#include <QMutexLocker>

TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);
    count = 0;

    connect( ui->buttonBox, SIGNAL(clicked(QAbstractButton*)),
             this, SLOT(buttonClicked(QAbstractButton*)) );
    connect( this, SIGNAL( getInfo(TextAndNumber)),
             this, SLOT(showText(TextAndNumber)) );
}

TextDialog::~TextDialog()
{
    delete ui;
}

void TextDialog::showText(TextAndNumber tan)
{
    QMutexLocker locker( &mutex );
    ui->listWidget->addItem( QString( "Call %1 (%3): %2" ).arg( count++ ).arg(tan.text).arg(tan.number) );
}

void TextDialog::buttonClicked(QAbstractButton *button)
{
    qDebug() << "buttonClicked: " << ui->buttonBox->buttonRole( button );
    if( ui->buttonBox->buttonRole( button ) == QDialogButtonBox::ResetRole )
    {
        ui->listWidget->clear();
    }
}

void TextDialog::on_pushButton_clicked()
{
    emit getInfo( TextAndNumber( 1, "one") );
}
