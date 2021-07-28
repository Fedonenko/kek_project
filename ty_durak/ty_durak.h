#pragma once

#include <QtWidgets/QWidget>
#include <memory>

namespace Ui
{
class ty_durakClass;
}

class ty_durak : public QWidget
{
    Q_OBJECT

public:
    ty_durak(QWidget *parent = Q_NULLPTR);
    virtual ~ty_durak();

protected:
    virtual bool event(QEvent* event) override;
    virtual void closeEvent(QCloseEvent* event) override;

private:
    void init();

public slots:
    void i_knew();

private:
    QString m_answer;
    std::unique_ptr<Ui::ty_durakClass> m_ui;
    bool m_isDurak;
};
