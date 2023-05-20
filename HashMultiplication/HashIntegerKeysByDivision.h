#ifndef _HASHINTEGERKEYSBYDIVISION_H_
#define _HASHINTEGERKEYSBYDIVISION_H_

#include <cstdint>
#include <string>
#include <vector>
#include <list>
#include "HashIntegerKeys.h"

namespace DictionaryStructures
{

	class HashIntegerKeysByDivision : public HashIntegerKeys
	{
		typedef struct _key
		{
			std::string keyValue;
		} key;

	public:
		HashIntegerKeysByDivision();
		virtual ~HashIntegerKeysByDivision();
	private:
		virtual uint32_t createNumericKey(std::string key);			
		friend class HashMultiplicationTest1;
	};

} // end namespace DictionaryStructures
#endif // _HASHINTEGERKEYSBYDIVISION_H_