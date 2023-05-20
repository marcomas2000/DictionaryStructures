#include "gtest/gtest.h"
#include "B+Tree/IdxFile.h"

namespace DictionaryStructuresTest
{
	class IdxFileTest : public ::testing::Test
	{
	protected:
		DictionaryStructures::IdxFile* m_idxTest;
		
		IdxFileTest() : m_idxTest(nullptr)
		{}

		void SetUp() override
		{
			m_idxTest = new DictionaryStructures::IdxFile("testIdxfile.idx");
		}

		void TearDown() override
		{
			if (m_idxTest != nullptr)
			{
				m_idxTest->closeStream();
			}
		}
	};

	TEST_F(IdxFileTest, TestOpenCloseStream)
	{
		bool ret = m_idxTest->openStream();
		ASSERT_EQ(ret, true);
		ret = m_idxTest->closeStream();
		EXPECT_EQ(ret, true);
	}
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}