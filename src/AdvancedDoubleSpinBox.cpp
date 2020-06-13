#include <QAdvancedSpinBox/AdvancedDoubleSpinBox.h>

#include <QMouseEvent>
#include <QLineEdit>
#include <cmath>
#include "AdvancedSpinBoxImpl_impl.h"

QDoubleSpinBoxWithDisplayIntegerBase::QDoubleSpinBoxWithDisplayIntegerBase(QWidget *w): QDoubleSpinBox(w){}

int QDoubleSpinBoxWithDisplayIntegerBase::decimals(){
	return QDoubleSpinBox::decimals();
}

template class AdvancedSpinBoxImpl<QDoubleSpinBoxWithDisplayIntegerBase>;
