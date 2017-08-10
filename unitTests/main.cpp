#include <qt_traits.h>
#include <QDebug>
#include <QMetaType>
#include <gtest/gtest.h>
#include "TestObject.h"

namespace 
{
	class QtTraits : public ::testing::Test {
	protected:

		QtTraits() {};
		virtual ~QtTraits() {};
		virtual void SetUp() {};
		virtual void TearDown() {};
	};
}

TEST_F(QtTraits, is_qenum)
{
	qDebug() << "TEST";
//	qDebug() << decltype(QVariant::fromValue(TestObject::isQenumClass{}));
//	qDebug() << decltype(QVariant::fromValue(TestObject::isNotQenum{}));
//	qDebug() << decltype(QVariant::fromValue(TestObject::isNotQenumClass{}).toString());
	EXPECT_TRUE(qt_traits::is_qenum<TestObject::isQenumClass>::value);
	EXPECT_TRUE(qt_traits::is_qenum<TestObject::isQenum>::value);
	EXPECT_FALSE(qt_traits::is_qenum<TestObject::isNotQenumClass>::value);
	EXPECT_FALSE(qt_traits::is_qenum<TestObject::isNotQenum>::value);
	EXPECT_FALSE(qt_traits::is_qenum<int>::value);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
