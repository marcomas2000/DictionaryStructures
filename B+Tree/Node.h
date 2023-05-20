#ifndef _NODE_H_
#define _NODE_H_

#include <cstdint>
#include <string>
#include <vector>
#include <list>

namespace DictionaryStructures
{
	class Node
	{
	public:
		Node();
		virtual ~Node();

	protected:

		// Test class
		friend class BPlusTreeTest1;
	};

} // end namespace DictionaryStructures

#endif // _NODE_H_