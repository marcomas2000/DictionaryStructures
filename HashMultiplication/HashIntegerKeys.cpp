#include "HashIntegerKeys.h"
#include <cctype>


namespace DictionaryStructures
{

	HashIntegerKeys::HashIntegerKeys() : m_hashIndex(), m_keySize(0)
	{
	}

	bool HashIntegerKeys::init(uint32_t hashTableSize, uint16_t keySize)
	{
		bool ret = false;
		if (keySize <= MAXKEYSIZE)
		{
			if ((hashTableSize <= MAXPIGEONHOLES) && (hashTableSize > 0))
			{
				m_hashIndex.resize(hashTableSize);
				m_keySize = keySize;
				ret = true;
			}
			else
			{
				ret = false;
			}
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	HashIntegerKeys::~HashIntegerKeys()
	{
	}

	bool HashIntegerKeys::insertKey(std::string key)
	{
		bool ret = false;
		ret = isKeyValid(key);
		if (ret == true)
		{
			bool found = searchKey(key);
			if (found == false)
			{

				uint32_t numericKey = createNumericKey(key);
				uint32_t pigeonHole = calculatePigeonHole(numericKey);
				HashIntegerKeys::key* elem = new HashIntegerKeys::key;

				elem->keyValue = key;
				m_hashIndex[pigeonHole].push_back(elem);
				ret = true;
			}
			else
			{
				ret = false;
			}
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	bool HashIntegerKeys::searchKey(std::string indexKey)
	{
		bool ret = false;
		ret = isKeyValid(indexKey);
		if (ret == true)
		{
			uint32_t numericKey = createNumericKey(indexKey);
			uint32_t pigeonHole = calculatePigeonHole(numericKey);
			std::list<HashIntegerKeys::key*>::iterator it;
			std::list<HashIntegerKeys::key*> pigeonHoleList = m_hashIndex[pigeonHole];
			bool found = false;
			for (it = pigeonHoleList.begin(); (it != pigeonHoleList.end()) && (found == false); it++)
			{
				if ((*it)->keyValue == indexKey)
				{
					found = true;
				}
			}
			if (found == true)
			{
				ret = true;
			}
			else
			{
				ret = false;
			}
		}
		return ret;
	}

	bool HashIntegerKeys::deleteKey(std::string indexKey)
	{
		bool ret = false;
		ret = isKeyValid(indexKey);
		if (ret == true)
		{
			uint32_t numericKey = createNumericKey(indexKey);
			uint32_t pigeonHole = calculatePigeonHole(numericKey);
			std::list<HashIntegerKeys::key*>::iterator it;
			std::list<HashIntegerKeys::key*>::iterator tbd;
			std::list<HashIntegerKeys::key*> pigeonHoleList = m_hashIndex[pigeonHole];
			bool found = false;
			for (it = pigeonHoleList.begin(); (it != pigeonHoleList.end()) && (found == false); ++it)
			{
				if ((*it)->keyValue == indexKey)
				{
					tbd = it;
					found = true;
				}
			}
			if (found == true)
			{
				pigeonHoleList.erase(tbd);
				ret = true;
			}
			else
			{
				ret = false;
			}
		}
		return ret;
	}

	bool HashIntegerKeys::isKeyValid(std::string key)
	{
		bool ret = false;
		// key must be shorter than maximum configured for the table in ::init
		if (key.length() <= m_keySize)
		{
			// key must be composed of alphabetic and numeric characters
			bool stopCheck = false;
			for (uint16_t i = 0; (i < key.length()) && (stopCheck == false); i++)
			{
				if (isalnum(key[i]) == 0)
				{
					stopCheck = true;
				}
			}
			if (stopCheck == true)
			{
				ret = false;
			}
			else
			{
				ret = true;
			}
		}
		else
		{
			ret = false;
		}
		return ret;
	}

	uint32_t HashIntegerKeys::calculatePigeonHole(uint32_t  numericKey)
	{
		return numericKey % m_hashIndex.size();
	}


} // end namespace DictionaryStructures
