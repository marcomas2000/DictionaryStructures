#ifndef _HASHINTEGERKEYS_H_
#define _HASHINTEGERKEYS_H_

#include <cstdint>
#include <string>
#include <vector>
#include <list>

namespace DictionaryStructures
{
	const uint32_t MAXPIGEONHOLES = 27000;
	const uint32_t MAXKEYSIZE = 256;

	class HashIntegerKeys
	{
		typedef struct _key
		{
			std::string keyValue;
		} key;

	public:
		HashIntegerKeys();
		bool init(uint32_t hashTableSize, uint16_t keySize);
		virtual ~HashIntegerKeys();

		bool insertKey(std::string key);
		bool searchKey(std::string key);
		bool deleteKey(std::string key);

		size_t getSizeHashIndex();
	protected:
		bool isKeyValid(std::string);
		virtual uint32_t createNumericKey(std::string key) = 0;
		uint32_t calculatePigeonHole(uint32_t  numericKey);

		std::vector<std::list<key*>> m_hashIndex;
		uint16_t m_keySize;

		// Test class
		friend class HashMultiplicationTest1;
	};

	inline size_t HashIntegerKeys::getSizeHashIndex()
	{
		return m_hashIndex.size();
	}
} // end namespace DictionaryStructures
#endif // _HASHINTEGERKEYS_H_