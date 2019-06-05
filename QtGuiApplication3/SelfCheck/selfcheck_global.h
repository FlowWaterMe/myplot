#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SELFCHECK_LIB)
#  define SELFCHECK_EXPORT Q_DECL_EXPORT
# else
#  define SELFCHECK_EXPORT Q_DECL_IMPORT
# endif
#else
# define SELFCHECK_EXPORT
#endif
