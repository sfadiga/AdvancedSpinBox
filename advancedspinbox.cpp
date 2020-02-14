#include "advancedspinbox.h"

#include <QMouseEvent>
#include <QLineEdit>
#include <qmath.h>

AdvancedSpinBox::AdvancedSpinBox(QWidget *w)
    : QSpinBox(w), m_edit(this->lineEdit()), m_digitStep(1)
{
    m_edit->installEventFilter(this);
}

int AdvancedSpinBox::digitStep() const
{
    return m_digitStep;
}

void AdvancedSpinBox::setDigitStep(int val)
{
    m_digitStep = val;
    emit digitStepChanged(val);
}

bool AdvancedSpinBox::eventFilter(QObject *, QEvent *e)
{
    if (e->type() == QMouseEvent::HoverMove)
    {
        auto me = static_cast<QMouseEvent*>(e);
        int cursorIndex = m_edit->cursorPositionAt(me->pos());
        QString txt = m_edit->text();
        int length = txt.length();
        if(cursorIndex < length)
        {
            int step = m_digitStep;
            step = m_digitStep * static_cast<int>(qPow(BASE_10, length - (cursorIndex + 1)));
            setSingleStep(step);
        }
    }
    return false;
}

AdvancedDoubleSpinBox::AdvancedDoubleSpinBox(QWidget *w)
    : QDoubleSpinBox(w), m_edit(this->lineEdit()), m_digitStep(1)
{
    m_edit->installEventFilter(this);
}

int AdvancedDoubleSpinBox::digitStep() const
{
    return m_digitStep;
}

void AdvancedDoubleSpinBox::setDigitStep(int val)
{
    m_digitStep = val;
    emit digitStepChanged(val);
}

bool AdvancedDoubleSpinBox::eventFilter(QObject *, QEvent *e)
{
    if (e->type() == QMouseEvent::HoverMove)
    {
        auto me = static_cast<QMouseEvent*>(e);
        int cursorIndex = m_edit->cursorPositionAt(me->pos());
        QString txt = m_edit->text();
        int dotIndex = txt.indexOf(".");
        if(cursorIndex < txt.length())
        {
            double step = m_digitStep;
            if(cursorIndex > dotIndex)
            {
                int i = cursorIndex - dotIndex;
                step = m_digitStep / qPow(BASE_10, i);
            }
            else
            {
                step = m_digitStep * qPow(BASE_10, dotIndex - (cursorIndex + 1));
            }
            setSingleStep(step);
        }
    }
    return false;
}
