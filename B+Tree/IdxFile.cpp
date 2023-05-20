#include "IdxFile.h"

namespace DictionaryStructures
{
	IdxFile::IdxFile(std::string fileName) : m_idxFileName(fileName), m_fdIdx()
	{
	}

	IdxFile::~IdxFile()
	{
	}

	bool IdxFile::openStream()
	{
		bool ret = false;
		m_fdIdx.open(m_idxFileName.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
		if (m_fdIdx.is_open() == true)
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	bool IdxFile::closeStream()
	{
		m_fdIdx.close();
		return true;
	}

	bool IdxFile::diskRead(uint32_t pageID)
	{
		bool ret = false;
		return ret;
	}

	bool IdxFile::diskWrite(uint32_t pageID)
	{
		bool ret = false;
		m_fdIdx << "<block><id>" << pageID << "</id></block>" << std::endl;
		if ((m_fdIdx.rdstate() & std::ofstream::goodbit) == 0)
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	uint32_t IdxFile::allocatePage()
	{
		bool ret = false;
		return ret;
	}

	bool IdxFile::deAllocatePage(uint32_t pageID)
	{
		bool ret = false;
		return ret;
	}

} // end namespace DictionaryStructures

