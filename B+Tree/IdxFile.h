#ifndef _IDXFILE_H_
#define _IDXFILE_H_

#include <cstdint>
#include <string>
#include <fstream>
//#include <vector>
//#include <list>

namespace DictionaryStructures
{
	class IdxFile
	{
	public:
		IdxFile(std::string fileName);
		virtual ~IdxFile();

		bool diskRead(uint32_t pageID);
		bool diskWrite(uint32_t pageID);
		uint32_t allocatePage();
		bool deAllocatePage(uint32_t pageID);

		bool openStream();
		bool closeStream();

	private:
		// Test class
		friend class BPlusTreeTest2;

		std::string  m_idxFileName;
		std::fstream m_fdIdx;
	};

} // end namespace DictionaryStructures

#endif // _IDXFILE_H_