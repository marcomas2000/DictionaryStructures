#include "HashIntegerKeysByDivision.h"
#include <cctype>


namespace DictionaryStructures
{

	HashIntegerKeysByDivision::HashIntegerKeysByDivision() : HashIntegerKeys()
	{
	}

	HashIntegerKeysByDivision::~HashIntegerKeysByDivision()
	{
	}

	uint32_t HashIntegerKeysByDivision::createNumericKey(std::string key)
	{
		uint32_t numKeyValue = 0;
		for (uint16_t i = 0; i < key.length(); i++)
		{
			numKeyValue += toascii(toupper(key[i]));
		}
		return numKeyValue;
	}


} // end namespace DictionaryStructures
