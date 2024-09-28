#include "ty_durak.h"

#include "ui_ty_durak.h"

#include <QTextCodec>
#include <QFont>
#include <QCloseEvent>
#include <QIODevice>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

namespace
{
const int c_panelHeight{ 5 };
const QString c_fileData{ "data.json" };
const QString c_ask{ "ask" };
const QString c_answer{ "answer" };

QString toHumanReadable(const QByteArray& data)
{
	const auto codecSys = QTextCodec::codecForName("System");
	return codecSys->toUnicode(data);
}

void initializeData()
{
    _MSC_VER;
    QFile file{ c_fileData };
    if (file.exists())
    {
        return;
    }

    file.open(QIODevice::WriteOnly);

    QJsonObject jObject;

    jObject[c_ask] = toHumanReadable("Ты дебил?");
    jObject[c_answer] = toHumanReadable("Я знал)");

    file.write(QJsonDocument(jObject).toJson());
}

}

ty_durak::ty_durak(QWidget *parent)
    : QWidget(parent)
    , m_ui{ std::make_unique<Ui::ty_durakClass>() }
    , m_isDurak{ false }
{
    m_ui->setupUi(this);

    initializeData();
    init();

    /*Q_ASSERT*/(connect(m_ui->yesButton, &QPushButton::clicked, this, &ty_durak::i_knew));
}

ty_durak::~ty_durak()
{}

bool ty_durak::event(QEvent* event)
{
    return QWidget::event(event);
}

void ty_durak::closeEvent(QCloseEvent* event)
{
    if (!m_isDurak)
    {
        event->ignore();

        return;
    }
    event->accept();
}

void ty_durak::init()
{
	QFile file{ c_fileData };

	file.open(QIODevice::ReadOnly);

    QJsonObject jObject = QJsonDocument::fromJson(file.readAll()).object();

    m_ui->label->setText(jObject[c_ask].toString());
	m_answer = jObject[c_answer].toString();
}

void ty_durak::i_knew()
{
    QFont fontLabel = m_ui->label->font();
    fontLabel.setPointSize(fontLabel.pointSize() + c_panelHeight);

    m_ui->label->setFont(fontLabel);
	m_ui->label->setText(m_answer);

    m_ui->yesButton->deleteLater();
    m_ui->noButton->deleteLater();

    m_isDurak = true;
}