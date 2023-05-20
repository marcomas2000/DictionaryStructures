#ifndef _BPLUSTREE_H_
#define _BPLUSTREE_H_

#include <cstdint>
#include <string>
#include <vector>
#include <list>

namespace DictionaryStructures
{
	class BPlusTree
	{
	public:
		BPlusTree();
		virtual ~BPlusTree();

		bool insertKey(std::string key);
		bool searchKey(std::string key);
		bool deleteKey(std::string key);

	protected:

		// Test class
		friend class BPlusTreeTest1;
	};

} // end namespace DictionaryStructures
#endif // _BPLUSTREE_H_