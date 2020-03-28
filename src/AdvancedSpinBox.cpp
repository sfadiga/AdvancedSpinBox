#include <QAdvancedSpinBox/AdvancedSpinBox.h>

#include <QMouseEvent>
#include <QLineEdit>
#include <cmath>
#include "AdvancedSpinBoxImpl_impl.h"

QSpinBoxWithDecimals::QSpinBoxWithDecimals(QWidget *w): QSpinBox(w){};

int QSpinBoxWithDecimals::displayIntegerBase() {
	return QSpinBox::displayIntegerBase();
}

template class AdvancedSpinBoxImpl<QSpinBoxWithDecimals>;
