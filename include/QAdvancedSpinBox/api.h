#pragma once

#if defined(WIN32)
	#if defined(QAdvancedSpinBox_EXPORTS)
		#define QAdvancedSpinBox_API __declspec(dllexport)
	#else
		#define QAdvancedSpinBox_API __declspec(dllimport)
	#endif
#else
	#if defined(QAdvancedSpinBox_EXPORTS)
		#define QAdvancedSpinBox_API __attribute__((visibility("default")))
	#else
		#define QAdvancedSpinBox_API
	#endif
#endif
