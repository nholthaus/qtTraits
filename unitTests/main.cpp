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
	EXPECT_TRUE(qt_traits::is_qenum_v<TestObject::isQenumClass>);
	EXPECT_TRUE(qt_traits::is_qenum_v<TestObject::isQenum>);
	EXPECT_FALSE(qt_traits::is_qenum_v<TestObject::isNotQenumClass>);
	EXPECT_FALSE(qt_traits::is_qenum_v<TestObject::isNotQenum>);
	EXPECT_FALSE(qt_traits::is_qenum_v<int>);
}

int main(int argc, char* argv[])
{
	qDebug() << "Qt Traits testing"; //"This is so it doesn't complain that the test is not a Qt executable";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
