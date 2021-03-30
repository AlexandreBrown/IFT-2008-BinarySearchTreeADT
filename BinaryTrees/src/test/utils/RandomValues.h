#ifndef BINARYTREES_SRC_TEST_UTILS_RANDOMVALUES_H_
#define BINARYTREES_SRC_TEST_UTILS_RANDOMVALUES_H_

#include <string>
namespace Random {
	class RandomValues {

		public:
			template<typename T>
			static T getRandomNumber();
	};

	template<typename T>
	T RandomValues::getRandomNumber() {
		return static_cast<T>(random());
	}
}

#endif
