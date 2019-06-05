#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OSADAPTER_LIB)
#  define OSADAPTER_EXPORT Q_DECL_EXPORT
# else
#  define OSADAPTER_EXPORT Q_DECL_IMPORT
# endif
#else
# define OSADAPTER_EXPORT
#endif
