#include <QObject>

class TestObject
{
	Q_GADGET
public:

	enum class isQenumClass
	{
		A,
		B,
	};
	Q_ENUM(isQenumClass);

	enum isQenum
	{
		C,
		D,
	};
	Q_ENUM(isQenum);

	enum class isNotQenumClass
	{
		E,
		F,
	};

	enum isNotQenum
	{
		G,
		H,
	};

	int isNotEnum;
};