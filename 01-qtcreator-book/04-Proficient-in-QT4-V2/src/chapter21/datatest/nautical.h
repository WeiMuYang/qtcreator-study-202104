#ifndef NAUTICAL_H
#define NAUTICAL_H

#include <QtCore>

class Nautical : public QObject 
{
	Q_OBJECT

public:
	Nautical();

	~Nautical();

	Nautical(const Nautical& nautical);

	Nautical(int nm);

	double toKilometer();

private:
	double m_nm;
};

Q_DECLARE_METATYPE(Nautical)
/* corelib/kernel/qmetatype.h 
  #define Q_DECLARE_METATYPE(TYPE) \
  template <> \
  struct QMetaTypeId< TYPE > \
  { \
    enum { Defined = 1 }; \
    static int qt_metatype_id() \
    { \
        static QBasicAtomic id = Q_ATOMIC_INIT(0); \
        if (!id) \
           id = qRegisterMetaType< TYPE >(#TYPE); \
       return id; \
    } \
};
*/

//qRegisterMetaType<Nautical>("Nautical");
/* corelib/kernel/qmetatype.h
template <typename T>
int qRegisterMetaType(const char *typeName)
{
    typedef void*(*ConstructPtr)(const T*);
    ConstructPtr cptr = qMetaTypeConstructHelper<T>;
    typedef void(*DeletePtr)(T*);
    DeletePtr dptr = qMetaTypeDeleteHelper<T>;

    return QMetaType::registerType(typeName, reinterpret_cast<QMetaType::Destructor>(dptr),
                                   reinterpret_cast<QMetaType::Constructor>(cptr));
}
*/


#endif

