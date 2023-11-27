// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/rp_widget.h"

namespace Ui {

class CodeDigit;

class CodeInput final : public Ui::RpWidget {
public:
	CodeInput(QWidget *parent);

	void setDigitsCountMax(int digitsCount);

	void setCode(QString code);

	void requestCode();
	[[nodiscard]] rpl::producer<QString> codeCollected() const;

	void clear();
	void showError();

protected:
	void focusInEvent(QFocusEvent *e) override;
	void focusOutEvent(QFocusEvent *e) override;
	void paintEvent(QPaintEvent *e) override;
	void keyPressEvent(QKeyEvent *e) override;

private:
	[[nodiscard]] QString collectDigits() const;

	void unfocusAll(int except);
	void findEmptyAndPerform(const Fn<void(int)> &callback);

	int _digitsCountMax = 0;
	std::vector<not_null<CodeDigit*>> _digits;
	int _currentIndex = 0;

	rpl::event_stream<QString> _codeCollected;

};

} // namespace Ui