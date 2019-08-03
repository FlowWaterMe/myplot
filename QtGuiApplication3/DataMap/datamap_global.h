#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATAMAP_LIB)
#  define DATAMAP_EXPORT Q_DECL_EXPORT
# else
#  define DATAMAP_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATAMAP_EXPORT
#endif
