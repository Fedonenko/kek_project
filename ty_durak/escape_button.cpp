#include "escape_button.h"

#include <QEvent>
#include <QDebug>
#include <QRandomGenerator>

escape_button::escape_button(QWidget* parent)
	: QPushButton(parent)
{
}

escape_button::~escape_button()
{}

#include <QMetaEnum>
QDebug operator<<(QDebug str, const QEvent* ev) {
	static int eventEnumIndex = QEvent::staticMetaObject
		.indexOfEnumerator("Type");
	str << "QEvent";
	if (ev) {
		QString name = QEvent::staticMetaObject
			.enumerator(eventEnumIndex).valueToKey(ev->type());
		if (!name.isEmpty()) str << name; else str << ev->type();
	}
	else {
		str << (void*)ev;
	}
	return str.maybeSpace();
}

bool escape_button::event(QEvent* event)
{
	if (event->type() == QEvent::Enter 
		|| event->type() == QEvent::MouseMove
		|| event->type() == QEvent::HoverEnter
		|| event->type() == QEvent::HoverMove
		)
	{
		qDebug() << "Under!!!!!!!!!!!!!";

		escape();
	}
	else
	{
		qDebug() << "Not!";
	}

	//qDebug() << event;

	return QPushButton::event(event);
}

void escape_button::escape()
{
	QWidget* wgtParent = dynamic_cast<QWidget*>(parent());
	if (!wgtParent)
	{
		Q_ASSERT(wgtParent);

		return;
	}

	QPoint point = pos();
	const QRect parentFrame = wgtParent->frameGeometry();
	const QRect currentFrame = frameGeometry();
	const QPoint curPosition = mapFromGlobal(QCursor::pos());

	const auto generator = QRandomGenerator::system();
	point.setX(generator->bounded(0, parentFrame.width() - currentFrame.width()));
	point.setY(generator->bounded(0, parentFrame.height() - currentFrame.height() - 20));

	move(point);

	if ( frameGeometry().contains(curPosition))
	{
		escape();
	}
}