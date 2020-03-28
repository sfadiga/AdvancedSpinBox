#include <QAdvancedSpinBox/AdvancedSpinBoxBase.h>
#include <QMouseEvent>
#include <iostream>

AdvancedSpinBoxBase::AdvancedSpinBoxBase(){}

int AdvancedSpinBoxBase::pos2Pow(int length){
	auto d = this->decimals();
	auto negativePart = d + bool(d);
	auto positivePositions = length - negativePart;
	auto pow = positivePositions - cursorIndex;
	std::cout << "length " << length << " d "<< d << " negativePart "<< negativePart << " positivePositions "<< positivePositions << " cursorIndex " << cursorIndex << " pow "<< pow << std::endl;
	if(pow < 0){
		++pow; // for decimal separator
	}
	std::cout << "pow "<< pow << std::endl;
	return pow;
}

void AdvancedSpinBoxBase::cursorPositionChangedProcessor([[gnu::unused]] int oldPos, int newPos){
	int length = m_edit->text().length();
	auto lMSL = length - suffixLength;

	std::cout << "rawCursorIndex " << newPos << " prefixLength "<< prefixLength << " suffixLength "<< suffixLength << " cursorIndex "<< newPos - prefixLength << std::endl;
	if(newPos >= prefixLength && newPos <= lMSL){
		if(m_edit->selectionStart() == -1){
			rawCursorIndex = newPos;
			cursorIndex = rawCursorIndex - prefixLength;
			//std::cout << "rawCursorIndex " << rawCursorIndex << " prefixLength "<< prefixLength << " suffixLength "<< suffixLength << " cursorIndex "<< cursorIndex << std::endl;
			this->updateStep(lMSL - prefixLength);
		}
	}
}

bool AdvancedSpinBoxBase::eventFilter(QObject *, QEvent *e)
{
	if(e->type() == QMouseEvent::HoverMove){
		auto me = static_cast<QMouseEvent*>(e);
		auto newPos = m_edit->cursorPositionAt(me->pos());
		auto pos = m_edit->cursorPosition();
		if(pos != newPos && m_edit->selectionStart() == -1){
			m_edit->setCursorPosition(newPos);
		}
	}
	return false;
}
